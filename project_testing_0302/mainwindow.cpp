// mainwindow.cpp
#include <QTcpSocket>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "NetProtocol.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 在构造函数里设置时间函数
    QTimer *globalTimer = new QTimer(this);
    connect(globalTimer, &QTimer::timeout, this, [this](){
        QString currentTime = QDateTime::currentDateTime().toString("hh:mm");

        // 核心：把时间“喊”出去，谁想听谁就接
        emit signal_broadcastTime(currentTime);
    });
    globalTimer->start(1000);



    // 1. 创建套接字对象
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost("192.168.172.26", 9999);

    connect(tcpSocket, &QTcpSocket::errorOccurred, this, [this](QAbstractSocket::SocketError) {
        qDebug() << "连接出错：" << tcpSocket->errorString();
        QMessageBox::information(this, "连接服务器错误","请检查网络或服务器是否启动"); return;
    });

    connect(tcpSocket, &QTcpSocket::readyRead, this, &MainWindow::on_clientReadData);

    // 1. 实例化
    loginPage = new LoginWidget(this);
    regPage = new RegisterWidget(this);
    menuPage = new MainMenuWidget(this);
    testPage =  new TestingRoom(this);

    // 2. 塞进 Stacked Widget
    ui->stackedWidget->addWidget(loginPage); // 索引为 0
    ui->stackedWidget->addWidget(regPage);   // 索引为 1
    ui->stackedWidget->addWidget(menuPage);  // 索引为 2
    ui->stackedWidget->addWidget (testPage); // 索引为 3

    // 3. 设置初始页
    ui->stackedWidget->setCurrentIndex(0);

    // 4. --- 核心跳转代码 ---
    // 当监听到 loginPage 发出 signal_showRegister 信号时，切换索引
    connect(loginPage, &LoginWidget::signal_showRegister, this, [this]() {
        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(loginPage, &LoginWidget::signal_LoginSuccess, this, [this](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    connect(regPage, &RegisterWidget::signal_CallbackLoginwidget, this, [this](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(menuPage, &MainMenuWidget::signal_gotoTestPage, this, [this](){
        ui->stackedWidget->setCurrentIndex(3);
        testPage->requestPaper("888888");
    });

    connect(testPage, &TestingRoom::signal_examFinished, this, [this](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    connect(this, &MainWindow::signal_registerResult, regPage, &RegisterWidget::handleRegisterResult);
    connect(this, &MainWindow::signal_loginResult, loginPage, &LoginWidget::handleLoginResult);
    connect(loginPage, &LoginWidget::signal_RecordUsername, menuPage, &MainMenuWidget::updateUserName); //用户名更新函数
    connect(this, &MainWindow::signal_broadcastTime, menuPage, &MainMenuWidget::updateTimeLabel);   //更新时间函数
    connect(menuPage, &MainMenuWidget::signal_callbackLoginMenu, this, [this](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(testPage, &TestingRoom::signal_sendData, this, [this](const QByteArray &data){
        NetProtocol::sendSecureData(this->tcpSocket, data);
    });

    connect(this, &MainWindow::signal_joinExamResult, menuPage, &MainMenuWidget::handleJoinExamResult);

    //-----------------------传输数据到服务器-----------------------------//
    connect(loginPage, &LoginWidget::SecureData, this, [this](const QByteArray &data){
        NetProtocol::sendSecureData(this->tcpSocket, data);
    });

    connect(regPage, &RegisterWidget::signal_RegisterData, this, [this](const QByteArray &data){
        NetProtocol::sendSecureData(this->tcpSocket, data);
    });

    // 在 MainWindow 构造函数，new 完 menuPage 之后连线：
    connect(menuPage, &MainMenuWidget::signal_joinExamReq, this, [=](QString code){

        // 1. 打包（调用咱们刚加的函数）
        QByteArray plainData = NetProtocol::packExamCode(MSG_JOIN_EXAM, code);

        // 2. 加密
        QByteArray cipherData = NetProtocol::encrypt(plainData);

        // 3. 发送（msocket 是你客户端的套接字对象）
        NetProtocol::sendSecureData(this->tcpSocket, cipherData);

    });

    // 监听大厅发出的查成绩请求，打包发给服务器
    connect(menuPage, &MainMenuWidget::signal_getScoresReq, this, [this](){
        QJsonObject root;
        root["type"] = 3001;
        root["data"] = QJsonObject(); // 空数据就行，服务器凭 socket 就能认出你是谁

        NetProtocol::sendSecureData(this->tcpSocket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
    });

    // 监听大厅发出的修改密码请求，打包发给服务器
    connect(menuPage, &MainMenuWidget::signal_changePwdReq, this, [this](QString oldPwd, QString newPwd){
        QJsonObject reqData;
        reqData["old_pwd"] = oldPwd;
        reqData["new_pwd"] = newPwd;

        QJsonObject root;
        root["type"] = MSG_CHANGE_PWD; // 确保你的 NetProtocol.h 里加了 MSG_CHANGE_PWD = 1008
        root["data"] = reqData;

        NetProtocol::sendSecureData(this->tcpSocket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
    });

    // 监听大厅发出的“注销”请求，打包发给服务器
    connect(menuPage, &MainMenuWidget::signal_LogoutData, this, [this](){
        QJsonObject root;
        root["type"] = MSG_LOGOUT; // 确保 NetProtocol 里有这个枚举 (比如 1003)
        root["data"] = QJsonObject(); // 空包就行，服务器认得 socket

        NetProtocol::sendSecureData(this->tcpSocket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
    });
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_clientReadData() {
    // 1. 拿到所有原始字节流
    QByteArray raw = tcpSocket->readAll();

    // 2. 调用你的工具函数：内部包含了“Base64解码 -> 异或还原 -> 转JSON对象”
    QJsonObject root = NetProtocol::parseSecureData(raw);

    // 如果解析出来的对象是空的，说明包有问题，直接拦截
    if (root.isEmpty()) {
        qDebug() << "解析失败或收到空包";
        return;
    }

    // 3. 提取核心数据
    int type = root["type"].toInt();
    QJsonObject data = root["data"].toObject();
    bool success = data["success"].toBool();
    QString msg = data["message"].toString();

    // 4. 根据类型发射不同的信号（即你说的分发）
    switch (type) {
    case MSG_LOGIN: // 1001
        emit signal_loginResult(success, msg);
        break;

    case MSG_REGISTER: // 1002
        emit signal_registerResult(success, msg);
        break;

    case MSG_LOGOUT:
        emit signal_logoutResult(success, msg);

    case MSG_JOIN_EXAM: {
        // 从 data 里把多余的科目和时长单独抽出来
        QString subject = data["subject"].toString();
        int duration = data["duration"].toInt();

        // 按照你的规矩，发射信号给 menuPage
        emit signal_joinExamResult(success, msg, subject, duration);
        break;}

    case MSG_GET_PAPER:
        testPage->handlePaperResult(data);
        break;

    case MSG_GET_SCORES:
        menuPage->handleScoresResult(data);
        break;

    case MSG_CHANGE_PWD:
        menuPage->handleChangePwdResult(success, msg);
        break;

    default:
        qDebug() << "收到未知业务类型的回执：" << type;
        break;
    }
}

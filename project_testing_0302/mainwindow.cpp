// mainwindow.cpp
#include <QTcpSocket>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "NetProtocol.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUI();           // 1. 让 UI 经理去把页面建好
    initNetwork();      // 2. 让 网络经理 去连服务器、包揽所有发包工作
    initPageJumps();    // 3. 让 路由经理 去把页面互相跳转的线拉好
}

MainWindow::~MainWindow() {
    delete ui;
}

// ==========================================
// 🏢 1. UI 经理的办公室 (只负责实例化页面、UI 布局、全局定时器)
// ==========================================
void MainWindow::initUI() {
    // 1. 实例化
    loginPage = new LoginWidget(this);
    regPage = new RegisterWidget(this);
    menuPage = new MainMenuWidget(this);
    testPage =  new TestingRoom(this);
    menuteach = new menu_Teacher(this);

    // 2. 塞进 Stacked Widget
    ui->stackedWidget->addWidget(loginPage); // 0
    ui->stackedWidget->addWidget(regPage);   // 1
    ui->stackedWidget->addWidget(menuPage);  // 2
    ui->stackedWidget->addWidget(testPage);  // 3
    ui->stackedWidget->addWidget(menuteach); // 4

    // 3. 设置初始页
    ui->stackedWidget->setCurrentIndex(0);

    // 4. 全局时间播报中心
    QTimer *globalTimer = new QTimer(this);
    connect(globalTimer, &QTimer::timeout, this, [this](){
        QString currentTime = QDateTime::currentDateTime().toString("hh:mm");
        emit signal_broadcastTime(currentTime);
    });
    globalTimer->start(1000);

    // 5. 更新时间函数（同时给学生端和教师端发时间）
    connect(this, &MainWindow::signal_broadcastTime, menuPage, &MainMenuWidget::updateTimeLabel);
    connect(this, &MainWindow::signal_broadcastTime, menuteach, &menu_Teacher::updateTimeLabel); // 顺手帮你补上了给老师端发时间！
}

// ==========================================
// 🏢 2. 路由经理的办公室 (只管界面跳转、组件间纯数据传递)
// ==========================================
void MainWindow::initPageJumps() {
    // 登录页 -> 注册页
    connect(loginPage, &LoginWidget::signal_showRegister, this, [this]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
    // 注册页 -> 登录页
    connect(regPage, &RegisterWidget::signal_CallbackLoginwidget, this, [this](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    // 大厅注销 -> 回登录页
    connect(menuPage, &MainMenuWidget::signal_callbackLoginMenu, this, [this](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    // 考场交卷 -> 切回大厅
    connect(testPage, &TestingRoom::signal_examFinished, this, [this](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    // 登录成功 -> 智能分流
    connect(loginPage, &LoginWidget::signal_LoginSuccess, this, [this](int role){
        if(role == 0) { 
            ui->stackedWidget->setCurrentIndex(2); 
            emit menuPage->signal_getMyClassesReq(); // 学生拉班级
        }
        if(role == 1) {
            ui->stackedWidget->setCurrentIndex(4);
            emit menuteach->signal_getClassesReq();  // 老师拉班级
        }
    });

    // 大厅 -> 考场 (带着真实的动态考试码！)
    connect(menuPage, &MainMenuWidget::signal_gotoTestPage, this, [this](QString code){
        ui->stackedWidget->setCurrentIndex(3);
        testPage->requestPaper(code);
    });

    // --- 跨页面数据传递的信号连线 ---
    connect(this, &MainWindow::signal_registerResult, regPage, &RegisterWidget::handleRegisterResult);
    connect(this, &MainWindow::signal_loginResult, loginPage, &LoginWidget::handleLoginResult);
    connect(loginPage, &LoginWidget::signal_RecordUsername, menuPage, &MainMenuWidget::updateUserName);

    // --- 把服务器传回来的结果，派发给各部门弹窗/填表 ---
    connect(this, &MainWindow::signal_joinExamResult, menuPage, &MainMenuWidget::handleJoinExamResult);
    connect(this, &MainWindow::signal_createClassResult, menuteach, &menu_Teacher::handleCreateClassResult);
    connect(this, &MainWindow::signal_getClassesResult, menuteach, &menu_Teacher::handleGetClassesResult);
    connect(this, &MainWindow::signal_joinClassResult, menuPage, &MainMenuWidget::handleJoinClassResult);
    connect(this, &MainWindow::signal_getMyClassesResult, menuPage, &MainMenuWidget::handleGetMyClassesResult);
    connect(this, &MainWindow::signal_getClassStudentsResult, menuteach, &menu_Teacher::handleGetClassStudentsResult);
    connect(this, &MainWindow::signal_addQuestionResult, menuteach, &menu_Teacher::handleAddQuestionResult);
    connect(this, &MainWindow::signal_publishExamResult, menuteach, &menu_Teacher::handlePublishExamResult);
    connect(this, &MainWindow::signal_getClassExamsResult, menuteach, &menu_Teacher::handleGetClassExamsResult);
    connect(this, &MainWindow::signal_getExamScoresResult, menuteach, &menu_Teacher::handleGetExamScoresResult);
}

// ==========================================
// 🏢 3. 网络经理的办公室 (所有 socket 相关的发包连线全在这里)
// ==========================================
void MainWindow::initNetwork() {
    // 1. 创建套接字并连接服务器
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost("127.0.0.1", 9999);

    connect(tcpSocket, &QTcpSocket::errorOccurred, this, [this](QAbstractSocket::SocketError) {
        qDebug() << "连接出错：" << tcpSocket->errorString();
        QMessageBox::information(this, "连接服务器错误","请检查网络或服务器是否启动"); 
    });

    // 极其核心的收包中心
    connect(tcpSocket, &QTcpSocket::readyRead, this, &MainWindow::on_clientReadData);

    // ================= 以下全是发包给服务器的连线 =================
    
    // 登录 / 注册 / 考场 (直接传已打包好的 data)
    connect(loginPage, &LoginWidget::SecureData, this, [this](const QByteArray &data){
        NetProtocol::sendSecureData(this->tcpSocket, data);
    });
    connect(regPage, &RegisterWidget::signal_RegisterData, this, [this](const QByteArray &data){
        NetProtocol::sendSecureData(this->tcpSocket, data);
    });
    connect(testPage, &TestingRoom::signal_sendData, this, [this](const QByteArray &data){
        NetProtocol::sendSecureData(this->tcpSocket, data);
    });

    // 学生端发包
    connect(menuPage, &MainMenuWidget::signal_joinExamReq, this, [=](QString code){
        QByteArray plainData = NetProtocol::packExamCode(MSG_JOIN_EXAM, code);
        NetProtocol::sendSecureData(this->tcpSocket, NetProtocol::encrypt(plainData));
    });
    connect(menuPage, &MainMenuWidget::signal_getScoresReq, this, [this](){
        QJsonObject root; root["type"] = MSG_GET_SCORES; root["data"] = QJsonObject();
        NetProtocol::sendSecureData(this->tcpSocket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
    });
    connect(menuPage, &MainMenuWidget::signal_changePwdReq, this, [this](QString oldPwd, QString newPwd){
        QJsonObject reqData; reqData["old_pwd"] = oldPwd; reqData["new_pwd"] = newPwd;
        QJsonObject root; root["type"] = MSG_CHANGE_PWD; root["data"] = reqData;
        NetProtocol::sendSecureData(this->tcpSocket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
    });
    connect(menuPage, &MainMenuWidget::signal_LogoutData, this, [this](){
        QJsonObject root; root["type"] = MSG_LOGOUT; root["data"] = QJsonObject();
        NetProtocol::sendSecureData(this->tcpSocket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
    });
    connect(menuPage, &MainMenuWidget::signal_joinClassReq, this, [this](QString code){
        QJsonObject reqData; reqData["class_code"] = code;
        QJsonObject root; root["type"] = MSG_JOIN_CLASS; root["data"] = reqData;
        NetProtocol::sendSecureData(this->tcpSocket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
    });
    connect(menuPage, &MainMenuWidget::signal_getMyClassesReq, this, [this](){
        QJsonObject root; root["type"] = MSG_GET_MY_CLASSES; root["data"] = QJsonObject();
        NetProtocol::sendSecureData(this->tcpSocket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
    });

    // 教师端发包
    connect(menuteach, &menu_Teacher::signal_createClassReq, this, [this](QString className){
        QJsonObject reqData; reqData["class_name"] = className;
        QJsonObject root; root["type"] = MSG_CREATE_CLASS; root["data"] = reqData;
        NetProtocol::sendSecureData(this->tcpSocket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
    });
    connect(menuteach, &menu_Teacher::signal_getClassesReq, this, [this](){
        QJsonObject root; root["type"] = MSG_GET_CLASSES; root["data"] = QJsonObject();
        NetProtocol::sendSecureData(this->tcpSocket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
    });
    connect(menuteach, &menu_Teacher::signal_getClassStudentsReq, this, [this](QString code){
        QJsonObject reqData; reqData["class_code"] = code;
        QJsonObject root; root["type"] = MSG_GET_CLASS_STUDENTS; root["data"] = reqData;
        NetProtocol::sendSecureData(this->tcpSocket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
    });
    connect(menuteach, &menu_Teacher::signal_addQuestionReq, this, [this](QJsonObject data){
        QJsonObject root; root["type"] = MSG_ADD_QUESTION; root["data"] = data;
        NetProtocol::sendSecureData(this->tcpSocket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
    });
    connect(menuteach, &menu_Teacher::signal_publishExamReq, this, [this](QJsonObject data){
        QJsonObject root; root["type"] = MSG_PUBLISH_EXAM; root["data"] = data;
        NetProtocol::sendSecureData(this->tcpSocket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
    });
    connect(menuteach, &menu_Teacher::signal_getClassExamsReq, this, [this](QString code){
        QJsonObject reqData; reqData["class_code"] = code;
        QJsonObject root; root["type"] = MSG_GET_CLASS_EXAMS; root["data"] = reqData;
        NetProtocol::sendSecureData(this->tcpSocket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
    });
    connect(menuteach, &menu_Teacher::signal_getExamScoresReq, this, [this](QString examCode){
        QJsonObject reqData; reqData["exam_code"] = examCode;
        QJsonObject root; root["type"] = MSG_GET_EXAM_SCORES; root["data"] = reqData;
        NetProtocol::sendSecureData(this->tcpSocket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
    });
    connect(menuteach, &menu_Teacher::signal_logoutReq, this, [this](){
        ui->stackedWidget->setCurrentIndex(0);
        QJsonObject root; root["type"] = MSG_LOGOUT; root["data"] = QJsonObject();
        NetProtocol::sendSecureData(this->tcpSocket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
    });
}

// ==========================================
// 🏢 4. 数据拆包分发中心 (原封不动保留你的极其严谨的逻辑)
// ==========================================
void MainWindow::on_clientReadData() {
    QByteArray raw = tcpSocket->readAll();
    QJsonObject root = NetProtocol::parseSecureData(raw);

    if (root.isEmpty()) {
        qDebug() << "解析失败或收到空包";
        return;
    }

    int type = root["type"].toInt();
    QJsonObject data = root["data"].toObject();
    bool success = data["success"].toBool();
    QString msg = data["message"].toString();

    switch (type) {
    case MSG_LOGIN: emit signal_loginResult(success, msg, data["role"].toInt()); break;
    case MSG_REGISTER: emit signal_registerResult(success, msg); break;
    case MSG_LOGOUT: emit signal_logoutResult(success, msg); break;
    case MSG_JOIN_EXAM: emit signal_joinExamResult(success, msg, data["subject"].toString(), data["duration"].toInt()); break;
    case MSG_GET_PAPER: testPage->handlePaperResult(data); break;
    case MSG_GET_SCORES: menuPage->handleScoresResult(data); break;
    case MSG_CHANGE_PWD: menuPage->handleChangePwdResult(success, msg); break;
    case MSG_CREATE_CLASS: emit signal_createClassResult(success, msg); break;
    case MSG_GET_CLASSES: emit signal_getClassesResult(data["classes"].toArray()); break;
    case MSG_JOIN_CLASS: emit signal_joinClassResult(success, msg); break;
    case MSG_GET_MY_CLASSES: emit signal_getMyClassesResult(data["classes"].toArray()); break;
    case MSG_GET_CLASS_STUDENTS: emit signal_getClassStudentsResult(data["students"].toArray()); break;
    case MSG_ADD_QUESTION: emit signal_addQuestionResult(success, msg); break;
    case MSG_PUBLISH_EXAM: emit signal_publishExamResult(success, msg, data["exam_code"].toString()); break;
    case MSG_GET_CLASS_EXAMS: emit signal_getClassExamsResult(data["exams"].toArray()); break;
    case MSG_GET_EXAM_SCORES: emit signal_getExamScoresResult(data["scores"].toArray()); break;
    default: qDebug() << "收到未知业务类型的回执：" << type; break;
    }
}

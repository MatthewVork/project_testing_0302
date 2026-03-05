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

    // 1. 创建套接字对象
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost("192.168.172.26", 9999);

    connect(tcpSocket, &QTcpSocket::connected, this, [this]() {
        qDebug() << "成功连接到服务器！";
        //tcpSocket->write("Hello Server, this is Teacher Client!");
    });

    connect(tcpSocket, &QTcpSocket::errorOccurred, this, [this](QAbstractSocket::SocketError) {
        qDebug() << "连接出错：" << tcpSocket->errorString();
        QMessageBox::information(this, "连接服务器错误","请检查网络或服务器是否启动"); return;
    });

    connect(tcpSocket, &QTcpSocket::readyRead, this, &MainWindow::on_clientReadData);

    // 1. 实例化
    loginPage = new LoginWidget(this);
    regPage = new RegisterWidget(this);
    menuPage = new MainMenuWidget(this);

    // 2. 塞进 Stacked Widget
    ui->stackedWidget->addWidget(loginPage); // 索引为 0
    ui->stackedWidget->addWidget(regPage);   // 索引为 1
    ui->stackedWidget->addWidget(menuPage);  // 索引为 2

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

    connect(regPage, &RegisterWidget::signal_RegisterData, this, [this](const QByteArray &data){
        NetProtocol::sendSecureData(this->tcpSocket, data);
    });

    connect(this, &MainWindow::signal_registerResult, regPage, &RegisterWidget::handleRegisterResult);
    connect(this, &MainWindow::signal_loginResult, loginPage, &LoginWidget::handleLoginResult);

    connect(menuPage, &MainMenuWidget::signal_callbackLoginMenu, this, [this](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    //收到传输JSON信号
    connect(loginPage, &LoginWidget::SecureData, this, [this](const QByteArray &data){

        // 调用你之前在 NetProtocol 里写好的静态发送函数
        // 填入主窗口维护的那个物理套接字 tcpSocket
        NetProtocol::sendSecureData(this->tcpSocket, data);

        qDebug() << "主窗口已拦截到登录信号，正在通过 Socket 发送加密数据包...";
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
    case NetProtocol::MSG_LOGIN: // 1001
        emit signal_loginResult(success, msg);
        break;

    case NetProtocol::MSG_REGISTER: // 1002
        emit signal_registerResult(success, msg);
        break;

    default:
        qDebug() << "收到未知业务类型的回执：" << type;
        break;
    }
}





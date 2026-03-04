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




// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1. 实例化你的“积木”
    loginPage = new LoginWidget(this);
    regPage = new registerwidget(this);

    // 2. 塞进 Stacked Widget
    ui->stackedWidget->addWidget(loginPage); // 索引为 0
    ui->stackedWidget->addWidget(regPage);   // 索引为 1

    // 3. 设置初始页
    ui->stackedWidget->setCurrentIndex(2);

    // 4. --- 核心跳转代码 ---
    // 当监听到 loginPage 发出 signal_showRegister 信号时，翻到索引 3
    connect(loginPage, &LoginWidget::signal_showRegister, this, [this]() {
        ui->stackedWidget->setCurrentIndex(3);
    });
}

MainWindow::~MainWindow() {
    delete ui;
}

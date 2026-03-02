#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    // 连接按钮点击事件。注意：请务必确认 Designer 里的 objectName 确实是 pushButton_Register
    connect(ui->pushButton_Register, &QPushButton::clicked, this, [this]() {
        emit signal_showRegister(); // 发射信号
    });
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

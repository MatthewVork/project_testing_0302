#include <QMessageBox>
#include "registerwidget.h"
#include "ui_registerwidget.h"
#include "NetProtocol.h"

RegisterWidget::RegisterWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegisterWidget)
{
    ui->setupUi(this);
}

RegisterWidget::~RegisterWidget() {
    delete ui;
}

// ==========================================
// 🏢 1. UI 按钮交互逻辑
// ==========================================
void RegisterWidget::on_registerBtn_clicked() {
    //去掉首尾的隐形空格
    QString user = ui->userEdit->text().trimmed();
    QString pwd = ui->pwdEdit->text().trimmed();
    QString pwdConfirm = ui->pwdConfirmEdit->text().trimmed();

    if(user.isEmpty() || pwd.isEmpty()) {
        QMessageBox::warning(this, "错误", "请将信息填写完整");
        return;
    }
    if (pwd != pwdConfirm) {
        QMessageBox::warning(this, "错误", "两次输入的密码不一致");
        return;
    }

    // 极其清爽的打包发射
    QByteArray plainData = NetProtocol::packUserAndPass(MSG_REGISTER, user, pwd);
    emit signal_RegisterData(NetProtocol::encrypt(plainData));
}

void RegisterWidget::on_backBtn_clicked() {
    // 清除内容并退回
    ui->userEdit->clear();
    ui->pwdEdit->clear();
    ui->pwdConfirmEdit->clear();
    emit signal_CallbackLoginwidget();
}

// ==========================================
// 🏢 2. 处理服务器结果
// ==========================================
void RegisterWidget::handleRegisterResult(bool success, QString msg) {
    if (success) {
        QMessageBox::information(this, "注册成功", msg);
        on_backBtn_clicked(); //注册成功直接调用返回按钮的逻辑
    } else {
        QMessageBox::warning(this, "注册失败", msg);
    }
}

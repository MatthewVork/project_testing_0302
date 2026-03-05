#include "registerwidget.h"
#include "ui_registerwidget.h"
#include "NetProtocol.h"

RegisterWidget::RegisterWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegisterWidget)
{
    ui->setupUi(this);
}

RegisterWidget::~RegisterWidget()
{
    delete ui;
}

void RegisterWidget::on_registerBtn_clicked() {
    QString user = ui->userEdit->text();
    QString pwd = ui->pwdEdit->text();
    QString pwdConfirm = ui->pwdConfirmEdit->text();

    // 1. 本地校验：密码是否一致
    if(user.isEmpty()||pwd.isEmpty()) { QMessageBox::warning(this, "错误", "请将信息填写完整"); return; }

    if (pwd != pwdConfirm)
    {
        QMessageBox::warning(this, "错误", "两次输入的密码不一致");
        return;
    }

    // 2. 打包并加密数据
    QByteArray data = NetProtocol::packUserAndPass(NetProtocol::MSG_REGISTER, user, pwd);
    QByteArray safeData = NetProtocol::encrypt(data);

    // 3. 发射信号给 MainWindow，让它通过 Socket 发送出去
    emit signal_RegisterData(safeData);
}

void RegisterWidget::on_backBtn_clicked()
{
    emit signal_CallbackLoginwidget();
}

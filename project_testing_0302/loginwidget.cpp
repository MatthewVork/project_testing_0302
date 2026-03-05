#define USERNAME "123"
#define PASSWORD "123"

#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "NetProtocol.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::handleLoginResult(bool success, QString msg)
{
    if (success)
    {
        QMessageBox *autoCloseBox = new QMessageBox(this);
        autoCloseBox->setWindowTitle("登录成功");
        autoCloseBox->setText("验证通过，正在进入系统...");
        autoCloseBox->setIcon(QMessageBox::Information);
        autoCloseBox->setStandardButtons(QMessageBox::NoButton);
        autoCloseBox->show();

        emit signal_RecordUsername(ui->Username->text());   //将用户名记录下来

        QTimer::singleShot(1000, autoCloseBox, [autoCloseBox, this]() { //指向autoCloseBox
            autoCloseBox->close();
            autoCloseBox->deleteLater();
            emit signal_LoginSuccess();
            ui->Username->clear();
            ui->Password->clear(); return; //发送信号通知主窗口切换屏幕
        });
    }
    else { QMessageBox::information(this, "登录失败", msg); ui->Password->clear(); return; }
}

void LoginWidget::on_loginBtn_clicked()
{
    if(ui->Username->text().isEmpty() || ui->Password->text().isEmpty()) QMessageBox::information(this, "错误", "缺少登录信息，请重新输入！");

    QByteArray data = NetProtocol::encrypt(
    NetProtocol::packUserAndPass(
    NetProtocol::MSG_LOGIN, ui->Username->text(), ui->Password->text()));

    emit SecureData(data); // 发出信号，由 MainWindow 接收并发送
}

void LoginWidget::on_registerBtn_clicked()
{
    emit signal_showRegister();
}

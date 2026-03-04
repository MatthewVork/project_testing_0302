#define USERNAME "123"
#define PASSWORD "123"

#include <QMessageBox>
#include <QTimer>

#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "NetProtocol.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    // 连接按钮点击事件。注意：请务必确认 Designer 里的 objectName 确实是 pushButton_Register
    connect(ui->pushButton_Login, &QPushButton::clicked, this, [this]() {
        check_login();  //检查信号
    });

    connect(ui->pushButton_Register, &QPushButton::clicked, this, [this](){
        emit signal_showRegister(); // 发射信号
    });
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::check_login()
{
    QByteArray data1 = NetProtocol::packData(1001, ui->Username->text(), ui->Password->text());

    emit SecureData(data1); // 发出信号，由 MainWindow 接收并发送

    //这里用来赋值比较

    if(ui->Username->text().isEmpty())
    {
        qDebug()<<"username is empty";
        QMessageBox::information(this, "登录失败","账号为空"); return;
    }

    if(ui->Username->text().compare(USERNAME) != 0)
    {
        qDebug()<<"username is false";
        QMessageBox::information(this, "登录失败","账号错误"); return;
    }

    if(ui->Username->text().compare(USERNAME) == 0)
    {
        if(ui->Password->text().compare(PASSWORD) == 0)
        {
            QMessageBox *autoCloseBox = new QMessageBox(this);
            autoCloseBox->setWindowTitle("登录成功");
            autoCloseBox->setText("验证通过，正在进入系统...");
            autoCloseBox->setIcon(QMessageBox::Information);

            autoCloseBox->setStandardButtons(QMessageBox::NoButton);
            autoCloseBox->show();

            QTimer::singleShot(2000, autoCloseBox, [autoCloseBox, this]() { //指向autoCloseBox
                autoCloseBox->close();      // 关闭弹窗，销毁内存（非常重要！）
                autoCloseBox->deleteLater(); });

            emit signal_LoginSuccess(); //发送信号通知主窗口切换屏幕
            return;
        }
        else
        {
            qDebug()<<"password is false";
            QMessageBox::information(this, "登录失败", "请重新输入密码，" + ui->Username->text()); return;
        }
    }
}

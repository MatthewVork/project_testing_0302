#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QString>
#include <QByteArray>

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

public slots:
    // ================= 供大管家调用的外部接口 =================
    void handleLoginResult(bool success, QString msg, int role);

signals:
    // ================= 向外发射的信号 =================
    void signal_showRegister();                  // 告诉大管家：切到注册页
    void signal_LoginSuccess(int role);          // 告诉大管家：登录成功，准备进大厅 (附带身份)
    void SecureData(const QByteArray &data);     // 将打包好的数据丢给大管家发送
    void signal_RecordUsername(QString data);    // 告诉大厅：把左上角的用户名改了

private slots:
    // ================= UI 交互槽函数 =================
    void on_loginBtn_clicked();                  // 点击登录
    void on_registerBtn_clicked();               // 点击注册

private:
    Ui::LoginWidget *ui;
};

#endif // LOGINWIDGET_H

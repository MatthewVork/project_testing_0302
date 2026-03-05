#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

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
    void handleLoginResult(bool success, QString msg);
    void on_loginBtn_clicked();
    void on_registerBtn_clicked();

signals:
    void signal_showRegister();
    void signal_LoginSuccess();
    void SecureData(const QByteArray &data);
    void signal_RecordUsername(QString data);

private:
    Ui::LoginWidget *ui;
};

#endif // LOGINWIDGET_H

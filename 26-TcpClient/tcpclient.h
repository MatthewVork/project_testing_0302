#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class TcpClient;
}
QT_END_NAMESPACE

class TcpClient : public QWidget
{
    Q_OBJECT

public:
    TcpClient(QWidget *parent = nullptr);
    ~TcpClient();

private slots:
    void on_reconnectCb_clicked(bool checked);

    void on_connectBtn_clicked();

    void on_checkBox_clicked(bool checked);

    void on_sendBtn_clicked();

private:
    Ui::TcpClient *ui;
    QTcpSocket msocket;
    QTimer looptimer;//循环发送的定时器
    QTimer rnttimer ;//断线重连定时器
};
#endif // TCPCLIENT_H

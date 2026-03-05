#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QWidget>
#include "../project_testing_0302/NetProtocol.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class TcpServer;
}
QT_END_NAMESPACE

class TcpServer : public QWidget
{
    Q_OBJECT

public:
    TcpServer(QWidget *parent = nullptr);
    ~TcpServer();

protected slots:
    void new_client();
    void read_data();

private slots:
    void on_startBtn_clicked();
    void on_clearSendBtn_clicked();
    void on_clearRecvBtn_clicked();
    void on_sendBtn_clicked();
    void handleRegister(const QJsonObject &data);

    bool verifyLogin(const QJsonObject &data);
    bool init_Database();
private:
    Ui::TcpServer *ui;
    //创建QTcpServer对象
    QTcpServer mserver;
    //创建一个列表存储所有的客户端套接字
    QVector<QTcpSocket*> clients;
    QString getRealIP();
};
#endif // TCPSERVER_H

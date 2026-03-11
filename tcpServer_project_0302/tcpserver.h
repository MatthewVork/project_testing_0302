#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QWidget>
#include <QVector>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui { class TcpServer; }
QT_END_NAMESPACE

class TcpServer : public QWidget
{
    Q_OBJECT

public:
    TcpServer(QWidget *parent = nullptr);
    ~TcpServer();

protected slots:
    // ================= 底层网络事件 =================
    void new_client();
    void read_data();

private slots:
    // ================= UI 按钮交互 =================
    void on_startBtn_clicked();
    void on_clearSendBtn_clicked();
    void on_clearRecvBtn_clicked();
    void on_sendBtn_clicked();

private:
    Ui::TcpServer *ui;
    QTcpServer mserver;               // 监听服务器
    QVector<QTcpSocket*> clients;     // 客户端套接字集合

    bool init_Database();             // 数据库初始化

    // ================= 通用发包引擎 =================
    void sendResponse(QTcpSocket* socket, int msgType, const QJsonObject &data);

    // ================= 1. 账号与通用业务逻辑 =================
    void handleRegister(QTcpSocket* socket, const QJsonObject &data);
    void handleLogin(QTcpSocket* socket, const QJsonObject &data);
    void handleLogout(QTcpSocket* socket, const QJsonObject &data);
    void handleChangePwd(QTcpSocket* socket, const QJsonObject &data);

    // ================= 2. 学生端业务逻辑 =================
    void handleJoinExam(QTcpSocket* socket, const QJsonObject &data);
    void handleGetPaper(QTcpSocket* socket, const QJsonObject &data);
    void handleSubmitExam(QTcpSocket* socket, const QJsonObject &data);
    void handleGetScores(QTcpSocket* socket, const QJsonObject &data);
    void handleJoinClass(QTcpSocket* socket, const QJsonObject &data);
    void handleGetMyClasses(QTcpSocket* socket, const QJsonObject &data);

    // ================= 3. 教师端业务逻辑 =================
    void handleCreateClass(QTcpSocket* socket, const QJsonObject &data);
    void handleGetClasses(QTcpSocket* socket, const QJsonObject &data);
    void handleGetClassStudents(QTcpSocket* socket, const QJsonObject &data);
    void handleAddQuestion(QTcpSocket* socket, const QJsonObject &data);
    void handlePublishExam(QTcpSocket* socket, const QJsonObject &data);
    void handleGetClassExams(QTcpSocket* socket, const QJsonObject &data);
    void handleGetExamScores(QTcpSocket* socket, const QJsonObject &data);
};

#endif // TCPSERVER_H

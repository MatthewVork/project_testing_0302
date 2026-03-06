#include "tcpserver.h"
#include "ui_tcpserver.h"
#include "qtcpsocket.h"
#include "../project_testing_0302/NetProtocol.h"
#include <QTcpServer>
#include <QMessageBox>
#include <QHostAddress>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

TcpServer::TcpServer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpServer)
{
    ui->setupUi(this);
    //关联客户端连接信号
    if(!init_Database()) return;
    connect(&mserver, &QTcpServer::newConnection, this, &TcpServer::new_client);
}

TcpServer::~TcpServer()
{
    delete ui;
    // 1. 如果还在监听，先强制关掉监听
    if(mserver.isListening()) {
        mserver.close();
    }

    // 2. 遍历并踢掉所有还在连接的客户端
    for(QTcpSocket* socket : clients) {
        socket->disconnectFromHost();
        socket->deleteLater();
    }

    delete ui;
}

void TcpServer::on_startBtn_clicked()
{
    //判断是已启动
    if(mserver.isListening())
    {
        mserver.close();//关闭监听
        ui->startBtn->setText("启动");
        ui->portEdit->setEnabled(true);
        return ;
    }

    //启动服务器
    bool ret = mserver.listen(QHostAddress::Any,ui->portEdit->text().toUShort());
    if(ret)
    {
        ui->startBtn->setText("停止");
        ui->portEdit->setEnabled(false);
    }
}

void TcpServer::new_client()
{
    qDebug()<<"新客户端连接";
    //获取与客户端通信的套接字
    QTcpSocket *msocket = mserver.nextPendingConnection();
    //把客户端套接字存储到列表中
    clients.append(msocket);
    //把客户端ip地址存储界面列表
    ui->listWidget->addItem(msocket->peerAddress().toString().remove("::ffff:"));//(拿到客户端地址并且转字符串)

    //当有客户端连接的时候会发生readyRead信号
    connect(msocket, &QTcpSocket::readyRead, this, &TcpServer::read_data);

    //当客户端离线的是会发送disconnect
    connect(msocket, &QTcpSocket::disconnected,this, [&](){
        qDebug()<<"客户端离线";
        QTcpSocket* msocket = (QTcpSocket*)sender(); //获取离线对象

        QString user = msocket->property("login_user").toString();
        if (!user.isEmpty()) {
            QSqlQuery q;
            q.prepare("UPDATE users SET is_online = 0 WHERE username = :user");
            q.bindValue(":user", user);
            q.exec();
        }
        //查找下msocket在clients里面的位置，
        int row = clients.indexOf(msocket);
        qDebug()<<row;
        //在通过row从界面上把ip删除
        QListWidgetItem* item =  ui->listWidget->takeItem(row);
        delete item;
        //把套接字从clients删除
        clients.removeOne(msocket);
    });
}



void TcpServer::read_data() {
    QTcpSocket* msocket = qobject_cast<QTcpSocket*>(sender());
    if (!msocket) return;

    // 重点：这里改用 QByteArray，不要用 QString msg
    QByteArray rawData = msocket->readAll();

    // 先解密，再转成字符串显示，否则会出现 image_e7128b 中的乱码
    QByteArray plainData = NetProtocol::decrypt(rawData);

    // UI 显示逻辑
    ui->textBrowser->append("收到密文: " + QString(rawData));
    ui->textBrowser->append("解密明文: " + QString::fromUtf8(plainData));

    QJsonDocument doc = QJsonDocument::fromJson(plainData);
    if (!doc.isNull() && doc.isObject())
    {
        QJsonObject rootObj = doc.object();
        int msgType = rootObj["type"].toInt();
        qDebug() << "收到的消息类型编号为：" << msgType;

        switch(msgType)
        {
            case NetProtocol::MSG_LOGIN: handleLogin(msocket, rootObj["data"].toObject()); break;
            case NetProtocol::MSG_REGISTER: handleRegister(msocket, rootObj["data"].toObject()); break;
            case NetProtocol::MSG_JOIN_EXAM: handleJoinExam(msocket, rootObj["data"].toObject()); break;
            case NetProtocol::MSG_LOGOUT: break;
            case NetProtocol::MSG_ADD_QUESTION: break;
            case NetProtocol::MSG_GET_QUESTION: break;
            case NetProtocol::MSG_SUBMIT_EXAM: break;
            case NetProtocol::MSG_GET_PAPER: break;
        }
    }
}


void TcpServer::on_clearSendBtn_clicked()
{
    ui->textEdit->clear();
}


void TcpServer::on_clearRecvBtn_clicked()
{
    ui->textBrowser->clear();
}


void TcpServer::on_sendBtn_clicked()
{
    //检测选中的客户端
    int row = ui->listWidget->currentRow();
    if(row < 0)
    {
        QMessageBox::warning(this,"提示","请选择要接收的客户端");
        return ;
    }
    //获取要发送的数据
    QString data = ui->textEdit->toPlainText();
    //获取发送数据的套接字
    QTcpSocket* msocket = clients.at(row);
    msocket->write(data.toUtf8());
}

bool TcpServer::init_Database() {
    // 1. 添加 SQLite 驱动并设置数据库文件名
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("exam_system.db"); // 运行后你会看到这个文件

    if (!db.open()) {
        qDebug() << "数据库打开失败：" << db.lastError().text();
        return false;
    }

    QSqlQuery query;

    // ==========================================
    // 第一部分：初始化用户表 (Users)
    // ==========================================
    QString sqlUser = "CREATE TABLE IF NOT EXISTS users ("
                      "username TEXT PRIMARY KEY, "
                      "password TEXT NOT NULL, "
                      "is_online INTEGER DEFAULT 0)";

    if(!query.exec(sqlUser)) {
        qDebug() << "用户表建表失败，原因：" << query.lastError().text();
        return false;
    } else {
        query.exec("UPDATE users SET is_online = 0");   // 所有在线状态清零
    }

    // ==========================================
    // 第二部分：初始化考试表 (Exams) - 新增！
    // ==========================================
    QString sqlExam = "CREATE TABLE IF NOT EXISTS exams ("
                      "exam_code TEXT PRIMARY KEY, " // 考试码作为主键（例如 "888888"）
                      "subject TEXT NOT NULL, "      // 科目名称
                      "duration INTEGER)";           // 考试时长（分钟）

    if(!query.exec(sqlExam)) {
        qDebug() << "考试表建表失败，原因：" << query.lastError().text();
        return false;
    } else {
        // 插入一条测试数据，供客户端大厅测试输入使用
        // 使用 INSERT OR IGNORE 防止每次重启服务器都重复插入报错
        query.exec("INSERT OR IGNORE INTO exams (exam_code, subject, duration) "
                   "VALUES ('888888', 'C++基础摸底考试', 60)");
    }

    // 两张表都准备完毕
    qDebug() << "数据库准备就绪！(已加载 users 表 和 exams 表)";
    return true;
}

void TcpServer::handleRegister(QTcpSocket* msocket, const QJsonObject &data) {
    QString user = data["username"].toString();
    QString pwd = data["password"].toString();

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (:user, :pwd)");
    query.bindValue(":user", user);
    query.bindValue(":pwd", pwd);

    bool success = query.exec(); // 执行 SQL
    QString message = success ? "注册成功！" : "注册失败，用户名可能已存在";

    // --- 关键：构造并回发统一格式的 JSON ---
    QJsonObject resData;
    resData["success"] = success;
    resData["message"] = message;

    QJsonObject root;
    root["type"] = NetProtocol::MSG_REGISTER; // 保持 1002 不变
    root["data"] = resData;

    // 打包、加密、发送
    QByteArray reply = QJsonDocument(root).toJson(QJsonDocument::Compact);
    NetProtocol::sendSecureData(msocket, NetProtocol::encrypt(reply));

    qDebug() << "服务器已回送结果：" << message;
}

void TcpServer::handleLogin(QTcpSocket* socket, const QJsonObject &data)
{
    QString user = data["username"].toString();
    QString pwd = data["password"].toString();

    QSqlQuery query;
    // 第一步：只根据用户名查找
    query.prepare("SELECT password, is_online FROM users WHERE username = :user");
    query.bindValue(":user", user);
    query.exec();

    bool success = false;
    QString message;

    if (!query.next()) { success = false; message = "该账号不存在，请先注册"; }
    else
    {
        QString db_pwd = query.value(0).toString(); //账号存在，对比数据库里的密码和在线状态
        int is_online = query.value(1).toInt();

        if (db_pwd == pwd)
        {
            success = (is_online == 0);
            message = success ? "登录成功" : "登录失败：该账号已在别处登录！";

            if (success) {
                QSqlQuery updateQuery;
                updateQuery.prepare("UPDATE users SET is_online = 1 WHERE username = :user");
                updateQuery.bindValue(":user", user);
                updateQuery.exec();

                socket->setProperty("login_user", user); // 极其重要：记住是谁用的这个 socket
            }
        }
        else
        {
            success = false;
            message = "密码错误，请重新输入";
        }
    }

    // 第二步：通过 NetProtocol 发送精准的报错信息
    QJsonObject res;
    res["success"] = success;
    res["message"] = message;

    QJsonObject root;
    root["type"] = NetProtocol::MSG_LOGIN; // 1001
    root["data"] = res;

    NetProtocol::sendSecureData(socket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
}

void TcpServer::handleJoinExam(QTcpSocket* socket, const QJsonObject &data) {
    QString code = data["exam_code"].toString();

    QSqlQuery query;
    query.prepare("SELECT subject, duration FROM exams WHERE exam_code = :code");
    query.bindValue(":code", code);
    query.exec();

    QJsonObject resData;
    if (query.next()) {
        resData["success"] = true;
        resData["subject"] = query.value(0).toString();
        resData["duration"] = query.value(1).toInt();
        resData["message"] = "考试码验证成功！";
    } else {
        resData["success"] = false;
        resData["message"] = "考试码不存在，请重新输入！";
    }

    QJsonObject root;
    root["type"] = NetProtocol::MSG_JOIN_EXAM;
    root["data"] = resData;
    NetProtocol::sendSecureData(socket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
}

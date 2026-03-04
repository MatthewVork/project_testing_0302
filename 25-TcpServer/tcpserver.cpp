#include "tcpserver.h"
#include "ui_tcpserver.h"
#include "qtcpsocket.h"
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

static QByteArray decrypt(const QByteArray &base64Cipher) {
    QByteArray cipher = QByteArray::fromBase64(base64Cipher); // Base64 解码
    const char key = 'K';
    for(int i = 0; i < cipher.size(); ++i) {
        cipher[i] = cipher[i] ^ key; // 异或还原
    }
    return cipher;
}

void TcpServer::read_data() {
    QTcpSocket* msocket = qobject_cast<QTcpSocket*>(sender());
    if (!msocket) return;

    // 重点：这里改用 QByteArray，不要用 QString msg
    QByteArray rawData = msocket->readAll();

    // 先解密，再转成字符串显示，否则会出现 image_e7128b 中的乱码
    QByteArray plainData = decrypt(rawData);

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
            case MSG_LOGIN: break;
            case MSG_REGISTER: break;
            case MSG_LOGOUT: break;
            case MSG_ADD_QUESTION: break;
            case MSG_GET_QUESTION: break;
            case MSG_SUBMIT_EXAM: break;
            case MSG_GET_PAPER: break;
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

void TcpServer::init_Database() {
    // 1. 添加 SQLite 驱动并设置数据库文件名
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("exam_system.db"); // 运行后你会看到这个文件

    if (!db.open()) {
        qDebug() << "数据库打开失败：" << db.lastError().text();
        return;
    }

    // 2. 创建用户表 (如果不存在的话)
    QSqlQuery query;
    // username 设置为 UNIQUE，这样同名用户注册就会报错，非常省心
    QString sql = "CREATE TABLE IF NOT EXISTS users ("
                  "username TEXT PRIMARY KEY, "
                  "password TEXT NOT NULL)";

    if(!query.exec(sql)) {
        qDebug() << "建表失败：" << query.lastError().text();
    } else {
        qDebug() << "数据库准备就绪！";
    }
}

void TcpServer::handleRegister(const QJsonObject &data) {
    QString user = data["username"].toString();
    QString pwd = data["password"].toString();

    QSqlQuery query;
    // 使用占位符 :user 和 :pwd 防止 SQL 注入，这是专业写法
    query.prepare("INSERT INTO users (username, password) VALUES (:user, :pwd)");
    query.bindValue(":user", user);
    query.bindValue(":pwd", pwd);

    if (query.exec()) {
        qDebug() << "注册成功：" << user;
        // 这里你可以通过 socket 发回一个 "注册成功" 的 JSON 包
    } else {
        qDebug() << "注册失败，可能是账号已存在：" << query.lastError().text();
        // 发回 "注册失败" 的包
    }
}

bool TcpServer::verifyLogin(QString user, QString pwd) {
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :user AND password = :pwd");
    query.bindValue(":user", user);
    query.bindValue(":pwd", pwd);

    query.exec();
    return query.next(); // 如果查到了结果，说明账号密码匹配，返回 true
}

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
#include <QRandomGenerator>

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
            case MSG_LOGIN: handleLogin(msocket, rootObj["data"].toObject()); break;
            case MSG_REGISTER: handleRegister(msocket, rootObj["data"].toObject()); break;
            case MSG_JOIN_EXAM: handleJoinExam(msocket, rootObj["data"].toObject()); break;
            case MSG_LOGOUT: handleLogout(msocket, rootObj["data"].toObject()); break;
            case MSG_ADD_QUESTION: break;
            case MSG_GET_QUESTION: break;
            case MSG_SUBMIT_EXAM: handleSubmitExam(msocket, rootObj["data"].toObject()); break;
            case MSG_GET_PAPER: handleGetPaper(msocket, rootObj["data"].toObject()); break;
            case MSG_GET_SCORES: handleGetScores(msocket, rootObj["data"].toObject()); break;
            case MSG_CHANGE_PWD: handleChangePwd(msocket, rootObj["data"].toObject()); break;
            case MSG_CREATE_CLASS: handleCreateClass(msocket, rootObj["data"].toObject()); break;
            case MSG_GET_CLASSES: handleGetClasses(msocket, rootObj["data"].toObject()); break;
            case MSG_JOIN_CLASS: handleJoinClass(msocket, rootObj["data"].toObject()); break; // 5005 专属接线员
            case MSG_GET_MY_CLASSES: handleGetMyClasses(msocket, rootObj["data"].toObject()); break; // 5006
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
                      "role INTEGER DEFAULT 0, " //0 代表学生，1 代表老师
                      "is_online INTEGER DEFAULT 0)";

    if(!query.exec(sqlUser)) {
        qDebug() << "用户表建表失败，原因：" << query.lastError().text();
        return false;
    } else {
        query.exec("UPDATE users SET is_online = 0");   // 所有在线状态清零
        query.exec("INSERT OR IGNORE INTO users (username, password, role, is_online) "
                   "VALUES ('admin', '123456', 1, 0)");
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

    // ==========================================
    // 创建题库表 (questions) 并录入测试题目
    // ==========================================
    QString sqlQuestion = "CREATE TABLE IF NOT EXISTS questions ("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                          "exam_code TEXT NOT NULL, "
                          "question_text TEXT NOT NULL, "
                          "option_A TEXT NOT NULL, "
                          "option_B TEXT NOT NULL, "
                          "option_C TEXT NOT NULL, "
                          "option_D TEXT NOT NULL, "
                          "correct_answer TEXT NOT NULL)";

    if(!query.exec(sqlQuestion)) {
        qDebug() << "题库表建表失败：" << query.lastError().text();
    } else {
        // 先清空一下 888888 的旧题目（防止你以后重复运行塞进去几百道一样的题）
        query.exec("DELETE FROM questions WHERE exam_code = '888888'");

        // 录入第一题
        query.exec("INSERT INTO questions (exam_code, question_text, option_A, option_B, option_C, option_D, correct_answer) "
                   "VALUES ('888888', 'C++中，用于输出到控制台的标准流对象是？', 'cin', 'cout', 'cerr', 'clog', 'B')");

        // 录入第二题
        query.exec("INSERT INTO questions (exam_code, question_text, option_A, option_B, option_C, option_D, correct_answer) "
                   "VALUES ('888888', '下列哪个关键字用于声明动态分配的内存？', 'malloc', 'alloc', 'new', 'create', 'C')");

        // 录入第三题
        query.exec("INSERT INTO questions (exam_code, question_text, option_A, option_B, option_C, option_D, correct_answer) "
                   "VALUES ('888888', 'Qt中，用于实现对象间通信的核心机制是？', '回调函数', '信号与槽', '全局变量', '消息队列', 'B')");

        qDebug() << "题库初始化完成！考试码 888888 已成功录入 3 道测试题。";
    }

    // ==========================================
    // 创建成绩表 (scores)
    // ==========================================
    QString sqlScore = "CREATE TABLE IF NOT EXISTS scores ("
                       "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                       "username TEXT NOT NULL, "
                       "exam_code TEXT NOT NULL, "
                       "score INTEGER NOT NULL, "
                       "submit_time TEXT)";

    if(!query.exec(sqlScore)) {
        qDebug() << "成绩表建表失败：" << query.lastError().text();
    }

    // ==========================================
    // 升级版：创建班级表 (classes) - 增加班级码
    // ==========================================
    // 这次我们用 class_code 作为主键，因为每个班的邀请码必须是全网唯一的！
    QString sqlClass = "CREATE TABLE IF NOT EXISTS classes ("
                       "class_code TEXT PRIMARY KEY, " // 👈 核心：6位班级码
                       "class_name TEXT NOT NULL, "    // 班级名称（允许同名，比如好几个老师都建了“软工1班”）
                       "teacher_name TEXT NOT NULL)";

    if(!query.exec(sqlClass)) {
        qDebug() << "班级表建表失败：" << query.lastError().text();
    }

    // ==========================================
    // 新增：创建分班表 (class_students) - 记录谁在哪个班
    // ==========================================
    QString sqlClassStudent = "CREATE TABLE IF NOT EXISTS class_students ("
                              "class_code TEXT NOT NULL, "
                              "username TEXT NOT NULL, "
                              "PRIMARY KEY (class_code, username))"; // 联合主键，防止同一个学生加两次

    if(!query.exec(sqlClassStudent)) {
        qDebug() << "分班表建表失败：" << query.lastError().text();
    }

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
    root["type"] = MSG_REGISTER; // 保持 1002 不变
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
    query.prepare("SELECT password, is_online, role FROM users WHERE username = :user");
    query.bindValue(":user", user);
    query.exec();

    bool success = false;
    QString message;
    int role = 0;   //老师学生身份

    if (!query.next()) { success = false; message = "该账号不存在，请先注册"; }
    else
    {
        QString db_pwd = query.value(0).toString(); //账号存在，对比数据库里的密码和在线状态
        int is_online = query.value(1).toInt();

        if (db_pwd == pwd)
        {
            success = (is_online == 0);
            message = success ? "登录成功" : "登录失败：该账号已在别处登录！";
            role = query.value(2).toInt();

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
    res["role"] = role;

    QJsonObject root;
    root["type"] = MSG_LOGIN; // 1001
    root["data"] = res;

    NetProtocol::sendSecureData(socket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
}

void TcpServer::handleJoinExam(QTcpSocket* socket, const QJsonObject &data) {
    // 获取当前登录的用户名
    QString user = socket->property("login_user").toString();
    QString code = data["exam_code"].toString();

    QJsonObject resData;
    QSqlQuery query;

    // 🌟 第一道防线：检查是否已经考过这门课了
    query.prepare("SELECT id FROM scores WHERE username = :user AND exam_code = :code");
    query.bindValue(":user", user);
    query.bindValue(":code", code);
    query.exec();

    if (query.next()) {
        // 查到了记录，说明他考过了！直接拦截！
        resData["success"] = false;
        resData["message"] = "您已参加过该科目的考试，系统不允许重复作答！";
    } else {
        // 🌟 第二道防线：没考过，再去查查有没有这个考试码
        query.prepare("SELECT subject, duration FROM exams WHERE exam_code = :code");
        query.bindValue(":code", code);
        query.exec();

        if (query.next()) {
            resData["success"] = true;
            resData["subject"] = query.value(0).toString();
            resData["duration"] = query.value(1).toInt();
            resData["message"] = "考试码验证成功！";
        } else {
            resData["success"] = false;
            resData["message"] = "考试码不存在，请重新输入！";
        }
    }

    QJsonObject root;
    root["type"] = MSG_JOIN_EXAM;
    root["data"] = resData;
    NetProtocol::sendSecureData(socket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
}

void TcpServer::handleGetPaper(QTcpSocket* socket, const QJsonObject &data) {
    QString code = data["exam_code"].toString();
    QJsonArray questionArray;

    QSqlQuery query;
    query.prepare("SELECT question_text, option_A, option_B, option_C, option_D, correct_answer "
                  "FROM questions WHERE exam_code = :code");
    query.bindValue(":code", code);
    query.exec();

    while(query.next()) {
        QJsonObject q;
        q["text"] = query.value(0).toString();
        q["A"] = query.value(1).toString();
        q["B"] = query.value(2).toString();
        q["C"] = query.value(3).toString();
        q["D"] = query.value(4).toString();
        q["answer"] = query.value(5).toString();
        questionArray.append(q);
    }

    QJsonObject resData;
    resData["questions"] = questionArray; // 先把题目装进内层信封

    QJsonObject root;
    root["type"] = MSG_GET_PAPER;
    root["data"] = resData; // 再把内层信封塞进外层包裹

    // 加密发回
    NetProtocol::sendSecureData(socket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
}

void TcpServer::handleSubmitExam(QTcpSocket* socket, const QJsonObject &data) {
    QString user = socket->property("login_user").toString();
    QString code = data["exam_code"].toString();
    int score = data["score"].toInt();

    // 👈 新增：由服务器获取绝对安全的当前时间
    QString submitTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    QSqlQuery query;
    // 插入语句加上 submit_time
    query.prepare("INSERT INTO scores (username, exam_code, score, submit_time) VALUES (:user, :code, :score, :time)");
    query.bindValue(":user", user);
    query.bindValue(":code", code);
    query.bindValue(":score", score);
    query.bindValue(":time", submitTime); // 👈 绑定时间

    if(query.exec()) {
        qDebug() << "✅ 交卷入库成功！考生：" << user << " | 分数：" << score << " | 时间：" << submitTime;
    }
}

void TcpServer::handleGetScores(QTcpSocket* socket, const QJsonObject &data) {
    // 1. 获取是谁在查成绩
    QString user = socket->property("login_user").toString();
    QJsonArray scoresArray;
    QSqlQuery query;

    // 2. 联合查询：从 scores 表拿分数，从 exams 表拿科目名称
    query.prepare("SELECT s.exam_code, e.subject, s.score, s.submit_time "
                  "FROM scores s "
                  "LEFT JOIN exams e ON s.exam_code = e.exam_code "
                  "WHERE s.username = :user");
    query.bindValue(":user", user);
    query.exec();

    // 3. 把查到的所有成绩塞进 JSON 数组
    while(query.next()) {
        QJsonObject obj;
        obj["exam_code"] = query.value(0).toString();
        obj["subject"] = query.value(1).toString();
        obj["score"] = query.value(2).toInt();
        obj["submit_time"] = query.value(3).toString();

        scoresArray.append(obj);
    }

    // 4. 打包发回给客户端
    QJsonObject resData;
    resData["scores"] = scoresArray;

    QJsonObject root;
    root["type"] = 3001;
    root["data"] = resData;

    NetProtocol::sendSecureData(socket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
}

void TcpServer::handleChangePwd(QTcpSocket* socket, const QJsonObject &data) {
    // 1. 之前登录时，我们用 setProperty 在 socket 上绑定了用户名
    QString user = socket->property("login_user").toString();

    QString oldPwd = data["old_pwd"].toString();
    QString newPwd = data["new_pwd"].toString();

    QSqlQuery query;
    bool success = false;
    QString msg = "原密码错误，修改失败！";

    // 2. 先去 users 表里查一下旧密码对不对
    query.prepare("SELECT password FROM users WHERE username = :user");
    query.bindValue(":user", user);
    query.exec();

    // 3. 如果查到了该用户，且旧密码匹配得上
    if (query.next() && query.value(0).toString() == oldPwd) {
        // 4. 执行更新操作
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE users SET password = :newPwd WHERE username = :user");
        updateQuery.bindValue(":newPwd", newPwd);
        updateQuery.bindValue(":user", user);

        if (updateQuery.exec()) {
            success = true;
            msg = "密码修改成功！请使用新密码重新登录。";
            qDebug() << "✅ 玩家" << user << "成功修改了密码！";
        }
    }

    // 5. 打包回执，发回给客户端
    QJsonObject resData;
    resData["success"] = success;
    resData["message"] = msg;

    QJsonObject root;
    root["type"] = MSG_CHANGE_PWD; // 或者写 1008
    root["data"] = resData;

    NetProtocol::sendSecureData(socket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
}

void TcpServer::handleLogout(QTcpSocket* socket, const QJsonObject &data) {
    // 拿到当前正在通信的用户名
    QString user = socket->property("login_user").toString();

    if (!user.isEmpty()) {
        QSqlQuery query;
        // 1. 把数据库里的在线状态改成 0
        query.prepare("UPDATE users SET is_online = 0 WHERE username = :user");
        query.bindValue(":user", user);

        if (query.exec()) {
            // 2. 把当前 socket 绑定的名字清空（防止串号）
            socket->setProperty("login_user", "");
            qDebug() << "✅ 玩家" << user << "已正常注销，在线状态清零！";
        }
    }
}

void TcpServer::handleCreateClass(QTcpSocket* socket, const QJsonObject &data) {
    QString className = data["class_name"].toString();
    QString teacher = socket->property("login_user").toString();

    // 👇 1. 核心绝招：随机生成 6 位班级邀请码 (A-Z, 0-9)
    QString classCode;
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    for(int i = 0; i < 6; ++i) {
        int index = QRandomGenerator::global()->bounded(possibleCharacters.length());
        classCode.append(possibleCharacters.at(index));
    }

    // 2. 存入数据库
    QSqlQuery query;
    query.prepare("INSERT INTO classes (class_code, class_name, teacher_name) VALUES (:code, :name, :teacher)");
    query.bindValue(":code", classCode);
    query.bindValue(":name", className);
    query.bindValue(":teacher", teacher);

    bool success = query.exec();
    QString msg = success ? QString("创建成功！\n请将班级码发给学生：%1").arg(classCode) : "创建失败，数据库异常！";

    // 3. 打包发回给客户端
    QJsonObject resData;
    resData["success"] = success;
    resData["message"] = msg;
    // 顺便把生成的码也发给客户端，方便它显示在表格里
    resData["class_code"] = classCode;

    QJsonObject root;
    root["type"] = MSG_CREATE_CLASS;
    root["data"] = resData;

    NetProtocol::sendSecureData(socket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));

    if (success) qDebug() << "✅ 老师" << teacher << "建班成功：" << className << " | 班级码：" << classCode;
}

void TcpServer::handleGetClasses(QTcpSocket* socket, const QJsonObject &data) {
    // 拿到当前老师的名字
    QString teacher = socket->property("login_user").toString();
    QJsonArray classArray;
    QSqlQuery query;

    // 去数据库查属于这个老师的所有班级
    query.prepare("SELECT class_name, class_code FROM classes WHERE teacher_name = :teacher");
    query.bindValue(":teacher", teacher);
    query.exec();

    // 把查到的结果一个个塞进 JSON 数组
    while(query.next()) {
        QJsonObject obj;
        obj["class_name"] = query.value(0).toString();
        obj["class_code"] = query.value(1).toString();
        classArray.append(obj);
    }

    // 打包发回给客户端
    QJsonObject resData;
    resData["classes"] = classArray;

    QJsonObject root;
    root["type"] = MSG_GET_CLASSES; // 5002
    root["data"] = resData;

    NetProtocol::sendSecureData(socket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
}

void TcpServer::handleJoinClass(QTcpSocket* socket, const QJsonObject &data) {
    QString classCode = data["class_code"].toString();
    // 拿到当前正在操作的学生账号
    QString student = socket->property("login_user").toString();

    QSqlQuery query;
    QJsonObject resData;
    bool success = false;
    QString msg;

    // 1. 第一道防线：去 classes 表里查，有没有这把“钥匙”对应的房间
    query.prepare("SELECT class_name FROM classes WHERE class_code = :code");
    query.bindValue(":code", classCode);
    query.exec();

    if (!query.next()) {
        msg = "班级码不存在，请找老师确认后重试！";
    } else {
        QString className = query.value(0).toString();

        // 2. 第二道防线：钥匙是对的，尝试把学生写进 class_students (分班表)
        query.prepare("INSERT INTO class_students (class_code, username) VALUES (:code, :student)");
        query.bindValue(":code", classCode);
        query.bindValue(":student", student);

        if (query.exec()) {
            success = true;
            msg = "成功加入班级：" + className;
            qDebug() << "✅ 学生" << student << "成功加入了班级" << className;
        } else {
            // 因为咱们建表时用了 (class_code, username) 做联合主键，重复插入会自动报错拦截！
            msg = "你已经在这个班级里啦，不需要重复加入！";
        }
    }

    // 3. 打包发回给客户端
    resData["success"] = success;
    resData["message"] = msg;

    QJsonObject root;
    root["type"] = MSG_JOIN_CLASS; // 5005
    root["data"] = resData;

    NetProtocol::sendSecureData(socket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
}

void TcpServer::handleGetMyClasses(QTcpSocket* socket, const QJsonObject &data) {
    QString student = socket->property("login_user").toString();
    QJsonArray classArray;
    QSqlQuery query;

    // 联合查询：通过 class_students 找到学生加了哪些班，再从 classes 表拿到班级名和老师名
    query.prepare("SELECT c.class_name, c.teacher_name, c.class_code "
                  "FROM classes c "
                  "INNER JOIN class_students cs ON c.class_code = cs.class_code "
                  "WHERE cs.username = :student");
    query.bindValue(":student", student);
    query.exec();

    while(query.next()) {
        QJsonObject obj;
        obj["class_name"] = query.value(0).toString();
        obj["teacher_name"] = query.value(1).toString();
        obj["class_code"] = query.value(2).toString();
        classArray.append(obj);
    }

    QJsonObject resData;
    resData["classes"] = classArray;

    QJsonObject root;
    root["type"] = MSG_GET_MY_CLASSES; // 5006
    root["data"] = resData;

    NetProtocol::sendSecureData(socket, NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));
}

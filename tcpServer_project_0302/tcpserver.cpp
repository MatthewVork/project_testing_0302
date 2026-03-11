#include "tcpserver.h"
#include "ui_tcpserver.h"
#include "../project_testing_0302/NetProtocol.h"
#include <QMessageBox>
#include <QHostAddress>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QRandomGenerator>
#include <QDateTime>

TcpServer::TcpServer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpServer)
{
    ui->setupUi(this);
    if(!init_Database()) return;
    connect(&mserver, &QTcpServer::newConnection, this, &TcpServer::new_client);
}

TcpServer::~TcpServer() {
    if(mserver.isListening()) mserver.close();
    for(QTcpSocket* socket : clients) {
        socket->disconnectFromHost();
        socket->deleteLater();
    }
    delete ui;
}

// ==========================================
// 🏢 通用发包引擎
// ==========================================
void TcpServer::sendResponse(QTcpSocket* socket, int msgType, const QJsonObject &data) {
    QJsonObject root;
    root["type"] = msgType;
    root["data"] = data;
    QByteArray reply = QJsonDocument(root).toJson(QJsonDocument::Compact);
    NetProtocol::sendSecureData(socket, NetProtocol::encrypt(reply));
}

// ==========================================
// 🏢 底层网络与 UI 交互模块
// ==========================================
void TcpServer::on_startBtn_clicked() {
    if(mserver.isListening()) {
        mserver.close();
        ui->startBtn->setText("启动");
        ui->portEdit->setEnabled(true);
        return;
    }
    if(mserver.listen(QHostAddress::Any, ui->portEdit->text().toUShort())) {
        ui->startBtn->setText("停止");
        ui->portEdit->setEnabled(false);
    }
}

void TcpServer::new_client() {
    QTcpSocket *msocket = mserver.nextPendingConnection();
    clients.append(msocket);
    ui->listWidget->addItem(msocket->peerAddress().toString().remove("::ffff:"));

    connect(msocket, &QTcpSocket::readyRead, this, &TcpServer::read_data);
    connect(msocket, &QTcpSocket::disconnected, this, [&]() {
        QTcpSocket* socket = (QTcpSocket*)sender();
        QString user = socket->property("login_user").toString();
        if (!user.isEmpty()) {
            QSqlQuery q;
            q.prepare("UPDATE users SET is_online = 0 WHERE username = :user");
            q.bindValue(":user", user);
            q.exec();
        }
        int row = clients.indexOf(socket);
        delete ui->listWidget->takeItem(row);
        clients.removeOne(socket);
    });
}

void TcpServer::read_data() {
    QTcpSocket* msocket = qobject_cast<QTcpSocket*>(sender());
    if (!msocket) return;

    QByteArray rawData = msocket->readAll();
    QByteArray plainData = NetProtocol::decrypt(rawData);

    ui->textBrowser->append("收到密文: " + QString(rawData));
    ui->textBrowser->append("解密明文: " + QString::fromUtf8(plainData));

    QJsonDocument doc = QJsonDocument::fromJson(plainData);
    if (!doc.isNull() && doc.isObject()) {
        QJsonObject rootObj = doc.object();
        int msgType = rootObj["type"].toInt();
        QJsonObject dataObj = rootObj["data"].toObject();

        //业务路由中心
        switch(msgType) {
        case MSG_LOGIN: handleLogin(msocket, dataObj); break;
        case MSG_REGISTER: handleRegister(msocket, dataObj); break;
        case MSG_LOGOUT: handleLogout(msocket, dataObj); break;
        case MSG_CHANGE_PWD: handleChangePwd(msocket, dataObj); break;

        case MSG_JOIN_EXAM: handleJoinExam(msocket, dataObj); break;
        case MSG_GET_PAPER: handleGetPaper(msocket, dataObj); break;
        case MSG_SUBMIT_EXAM: handleSubmitExam(msocket, dataObj); break;
        case MSG_GET_SCORES: handleGetScores(msocket, dataObj); break;
        case MSG_JOIN_CLASS: handleJoinClass(msocket, dataObj); break;
        case MSG_GET_MY_CLASSES: handleGetMyClasses(msocket, dataObj); break;

        case MSG_CREATE_CLASS: handleCreateClass(msocket, dataObj); break;
        case MSG_GET_CLASSES: handleGetClasses(msocket, dataObj); break;
        case MSG_GET_CLASS_STUDENTS: handleGetClassStudents(msocket, dataObj); break;
        case MSG_ADD_QUESTION: handleAddQuestion(msocket, dataObj); break;
        case MSG_PUBLISH_EXAM: handlePublishExam(msocket, dataObj); break;
        case MSG_GET_CLASS_EXAMS: handleGetClassExams(msocket, dataObj); break;
        case MSG_GET_EXAM_SCORES: handleGetExamScores(msocket, dataObj); break;
        }
    }
}

void TcpServer::on_clearSendBtn_clicked() { ui->textEdit->clear(); }
void TcpServer::on_clearRecvBtn_clicked() { ui->textBrowser->clear(); }
void TcpServer::on_sendBtn_clicked() {
    int row = ui->listWidget->currentRow();
    if(row < 0) { QMessageBox::warning(this,"提示","请选择要接收的客户端"); return; }
    clients.at(row)->write(ui->textEdit->toPlainText().toUtf8());
}

// ==========================================
// 🏢 数据库初始化
// ==========================================
bool TcpServer::init_Database() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("exam_system.db");
    if (!db.open()) return false;

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users (username TEXT PRIMARY KEY, password TEXT NOT NULL, role INTEGER DEFAULT 0, is_online INTEGER DEFAULT 0)");
    query.exec("UPDATE users SET is_online = 0");
    query.exec("INSERT OR IGNORE INTO users (username, password, role, is_online) VALUES ('admin', '123456', 1, 0)");

    query.exec("CREATE TABLE IF NOT EXISTS exams (exam_code TEXT PRIMARY KEY, subject TEXT NOT NULL, duration INTEGER, class_code TEXT)");
    query.exec("INSERT OR IGNORE INTO exams (exam_code, subject, duration) VALUES ('888888', 'C++基础摸底考试', 60)");

    query.exec("CREATE TABLE IF NOT EXISTS questions (id INTEGER PRIMARY KEY AUTOINCREMENT, exam_code TEXT NOT NULL, question_text TEXT NOT NULL, option_A TEXT NOT NULL, option_B TEXT NOT NULL, option_C TEXT NOT NULL, option_D TEXT NOT NULL, correct_answer TEXT NOT NULL)");
    query.exec("DELETE FROM questions WHERE exam_code = '888888'");
    query.exec("INSERT INTO questions (exam_code, question_text, option_A, option_B, option_C, option_D, correct_answer) VALUES ('888888', 'C++中，用于输出到控制台的标准流对象是？', 'cin', 'cout', 'cerr', 'clog', 'B')");
    query.exec("INSERT INTO questions (exam_code, question_text, option_A, option_B, option_C, option_D, correct_answer) VALUES ('888888', '下列哪个关键字用于声明动态分配的内存？', 'malloc', 'alloc', 'new', 'create', 'C')");
    query.exec("INSERT INTO questions (exam_code, question_text, option_A, option_B, option_C, option_D, correct_answer) VALUES ('888888', 'Qt中，用于实现对象间通信的核心机制是？', '回调函数', '信号与槽', '全局变量', '消息队列', 'B')");

    query.exec("CREATE TABLE IF NOT EXISTS scores (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT NOT NULL, exam_code TEXT NOT NULL, score INTEGER NOT NULL, submit_time TEXT)");
    query.exec("CREATE TABLE IF NOT EXISTS classes (class_code TEXT PRIMARY KEY, class_name TEXT NOT NULL, teacher_name TEXT NOT NULL)");
    query.exec("CREATE TABLE IF NOT EXISTS class_students (class_code TEXT NOT NULL, username TEXT NOT NULL, PRIMARY KEY (class_code, username))");

    return true;
}

// ==========================================
// 🏢 业务逻辑处理模块
// ==========================================

void TcpServer::handleRegister(QTcpSocket* socket, const QJsonObject &data) {
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (:user, :pwd)");
    query.bindValue(":user", data["username"].toString());
    query.bindValue(":pwd", data["password"].toString());

    bool success = query.exec();
    QJsonObject resData;
    resData["success"] = success;
    resData["message"] = success ? "注册成功！" : "注册失败，用户名可能已存在";

    sendResponse(socket, MSG_REGISTER, resData);
}

void TcpServer::handleLogin(QTcpSocket* socket, const QJsonObject &data) {
    QString user = data["username"].toString();
    QSqlQuery query;
    query.prepare("SELECT password, is_online, role FROM users WHERE username = :user");
    query.bindValue(":user", user);
    query.exec();

    QJsonObject resData;
    resData["success"] = false;

    if (!query.next()) {
        resData["message"] = "该账号不存在，请先注册";
    } else {
        if (query.value(0).toString() == data["password"].toString()) {
            bool success = (query.value(1).toInt() == 0);
            resData["success"] = success;
            resData["message"] = success ? "登录成功" : "登录失败：该账号已在别处登录！";
            resData["role"] = query.value(2).toInt();

            if (success) {
                QSqlQuery updateQuery;
                updateQuery.prepare("UPDATE users SET is_online = 1 WHERE username = :user");
                updateQuery.bindValue(":user", user);
                updateQuery.exec();
                socket->setProperty("login_user", user);
            }
        } else {
            resData["message"] = "密码错误，请重新输入";
        }
    }
    sendResponse(socket, MSG_LOGIN, resData);
}

void TcpServer::handleLogout(QTcpSocket* socket, const QJsonObject &data) {
    QString user = socket->property("login_user").toString();
    if (!user.isEmpty()) {
        QSqlQuery query;
        query.prepare("UPDATE users SET is_online = 0 WHERE username = :user");
        query.bindValue(":user", user);
        if (query.exec()) socket->setProperty("login_user", "");
    }
}

void TcpServer::handleChangePwd(QTcpSocket* socket, const QJsonObject &data) {
    QString user = socket->property("login_user").toString();
    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE username = :user");
    query.bindValue(":user", user);
    query.exec();

    QJsonObject resData;
    resData["success"] = false;
    resData["message"] = "原密码错误，修改失败！";

    if (query.next() && query.value(0).toString() == data["old_pwd"].toString()) {
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE users SET password = :newPwd WHERE username = :user");
        updateQuery.bindValue(":newPwd", data["new_pwd"].toString());
        updateQuery.bindValue(":user", user);
        if (updateQuery.exec()) {
            resData["success"] = true;
            resData["message"] = "密码修改成功！请使用新密码重新登录。";
        }
    }
    sendResponse(socket, MSG_CHANGE_PWD, resData);
}

void TcpServer::handleJoinExam(QTcpSocket* socket, const QJsonObject &data) {
    QString user = socket->property("login_user").toString();
    QString code = data["exam_code"].toString();
    QJsonObject resData;
    QSqlQuery query;

    query.prepare("SELECT id FROM scores WHERE username = :user AND exam_code = :code");
    query.bindValue(":user", user);
    query.bindValue(":code", code);
    query.exec();

    if (query.next()) {
        resData["success"] = false;
        resData["message"] = "您已参加过该科目的考试，系统不允许重复作答！";
    } else {
        query.prepare("SELECT subject, duration, class_code FROM exams WHERE exam_code = :code");
        query.bindValue(":code", code);
        query.exec();

        if (query.next()) {
            QString targetClassCode = query.value(2).toString();
            bool canJoin = true;

            if (!targetClassCode.isEmpty()) {
                QSqlQuery checkClassQuery;
                checkClassQuery.prepare("SELECT 1 FROM class_students WHERE class_code = :classCode AND username = :user");
                checkClassQuery.bindValue(":classCode", targetClassCode);
                checkClassQuery.bindValue(":user", user);
                checkClassQuery.exec();
                if (!checkClassQuery.next()) canJoin = false;
            }

            if (canJoin) {
                resData["success"] = true;
                resData["subject"] = query.value(0).toString();
                resData["duration"] = query.value(1).toInt();
                resData["message"] = "身份验证通过！即将进入考场...";
            } else {
                resData["success"] = false;
                resData["message"] = "抱歉拦截：这是一场班级专属考试，您不在该班级的名单中！";
            }
        } else {
            resData["success"] = false;
            resData["message"] = "考试码不存在，请重新输入！";
        }
    }
    sendResponse(socket, MSG_JOIN_EXAM, resData);
}

void TcpServer::handleGetPaper(QTcpSocket* socket, const QJsonObject &data) {
    QJsonArray questionArray;
    QSqlQuery query;
    query.prepare("SELECT question_text, option_A, option_B, option_C, option_D, correct_answer FROM questions WHERE exam_code = :code");
    query.bindValue(":code", data["exam_code"].toString());
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
    resData["questions"] = questionArray;
    sendResponse(socket, MSG_GET_PAPER, resData);
}

void TcpServer::handleSubmitExam(QTcpSocket* socket, const QJsonObject &data) {
    QSqlQuery query;
    query.prepare("INSERT INTO scores (username, exam_code, score, submit_time) VALUES (:user, :code, :score, :time)");
    query.bindValue(":user", socket->property("login_user").toString());
    query.bindValue(":code", data["exam_code"].toString());
    query.bindValue(":score", data["score"].toInt());
    query.bindValue(":time", QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    query.exec();
}

void TcpServer::handleGetScores(QTcpSocket* socket, const QJsonObject &data) {
    QJsonArray scoresArray;
    QSqlQuery query;
    query.prepare("SELECT s.exam_code, e.subject, s.score, s.submit_time FROM scores s LEFT JOIN exams e ON s.exam_code = e.exam_code WHERE s.username = :user");
    query.bindValue(":user", socket->property("login_user").toString());
    query.exec();

    while(query.next()) {
        QJsonObject obj;
        obj["exam_code"] = query.value(0).toString();
        obj["subject"] = query.value(1).toString();
        obj["score"] = query.value(2).toInt();
        obj["submit_time"] = query.value(3).toString();
        scoresArray.append(obj);
    }
    QJsonObject resData;
    resData["scores"] = scoresArray;
    sendResponse(socket, MSG_GET_SCORES, resData); // 👈 彻底消灭魔法数字 3001！
}

void TcpServer::handleCreateClass(QTcpSocket* socket, const QJsonObject &data) {
    QString classCode;
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    for(int i = 0; i < 6; ++i) classCode.append(possibleCharacters.at(QRandomGenerator::global()->bounded(possibleCharacters.length())));

    QSqlQuery query;
    query.prepare("INSERT INTO classes (class_code, class_name, teacher_name) VALUES (:code, :name, :teacher)");
    query.bindValue(":code", classCode);
    query.bindValue(":name", data["class_name"].toString());
    query.bindValue(":teacher", socket->property("login_user").toString());

    bool success = query.exec();
    QJsonObject resData;
    resData["success"] = success;
    resData["message"] = success ? QString("创建成功！\n请将班级码发给学生：%1").arg(classCode) : "创建失败，数据库异常！";
    if (success) resData["class_code"] = classCode;

    sendResponse(socket, MSG_CREATE_CLASS, resData);
}

void TcpServer::handleGetClasses(QTcpSocket* socket, const QJsonObject &data) {
    QJsonArray classArray;
    QSqlQuery query;
    query.prepare("SELECT class_name, class_code FROM classes WHERE teacher_name = :teacher");
    query.bindValue(":teacher", socket->property("login_user").toString());
    query.exec();

    while(query.next()) {
        QJsonObject obj;
        obj["class_name"] = query.value(0).toString();
        obj["class_code"] = query.value(1).toString();
        classArray.append(obj);
    }
    QJsonObject resData;
    resData["classes"] = classArray;
    sendResponse(socket, MSG_GET_CLASSES, resData);
}

void TcpServer::handleJoinClass(QTcpSocket* socket, const QJsonObject &data) {
    QString classCode = data["class_code"].toString();
    QSqlQuery query;
    QJsonObject resData;

    query.prepare("SELECT class_name FROM classes WHERE class_code = :code");
    query.bindValue(":code", classCode);
    query.exec();

    if (!query.next()) {
        resData["success"] = false;
        resData["message"] = "班级码不存在，请找老师确认后重试！";
    } else {
        QString className = query.value(0).toString();
        query.prepare("INSERT INTO class_students (class_code, username) VALUES (:code, :student)");
        query.bindValue(":code", classCode);
        query.bindValue(":student", socket->property("login_user").toString());

        if (query.exec()) {
            resData["success"] = true;
            resData["message"] = "成功加入班级：" + className;
        } else {
            resData["success"] = false;
            resData["message"] = "你已经在这个班级里啦，不需要重复加入！";
        }
    }
    sendResponse(socket, MSG_JOIN_CLASS, resData);
}

void TcpServer::handleGetMyClasses(QTcpSocket* socket, const QJsonObject &data) {
    QJsonArray classArray;
    QSqlQuery query;
    query.prepare("SELECT c.class_name, c.teacher_name, c.class_code FROM classes c INNER JOIN class_students cs ON c.class_code = cs.class_code WHERE cs.username = :student");
    query.bindValue(":student", socket->property("login_user").toString());
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
    sendResponse(socket, MSG_GET_MY_CLASSES, resData);
}

void TcpServer::handleGetClassStudents(QTcpSocket* socket, const QJsonObject &data) {
    QJsonArray studentArray;
    QSqlQuery query;
    query.prepare("SELECT username FROM class_students WHERE class_code = :code");
    query.bindValue(":code", data["class_code"].toString());
    query.exec();

    while(query.next()) {
        QJsonObject obj;
        obj["username"] = query.value(0).toString();
        studentArray.append(obj);
    }
    QJsonObject resData;
    resData["students"] = studentArray;
    sendResponse(socket, MSG_GET_CLASS_STUDENTS, resData);
}

void TcpServer::handleAddQuestion(QTcpSocket* socket, const QJsonObject &data) {
    QString code = data["exam_code"].toString();
    QSqlQuery query;
    query.prepare("INSERT INTO questions (exam_code, question_text, option_A, option_B, option_C, option_D, correct_answer) VALUES (:code, :question, :A, :B, :C, :D, :answer)");
    query.bindValue(":code", code);
    query.bindValue(":question", data["question_text"].toString());
    query.bindValue(":A", data["option_A"].toString());
    query.bindValue(":B", data["option_B"].toString());
    query.bindValue(":C", data["option_C"].toString());
    query.bindValue(":D", data["option_D"].toString());
    query.bindValue(":answer", data["correct_answer"].toString());

    bool success = query.exec();
    QJsonObject resData;
    resData["success"] = success;

    if (success) {
        QSqlQuery countQuery;
        countQuery.prepare("SELECT COUNT(*) FROM questions WHERE exam_code = :code");
        countQuery.bindValue(":code", code);
        countQuery.exec();
        int total = countQuery.next() ? countQuery.value(0).toInt() : 1;
        resData["message"] = QString("第 %1 题录入成功！请继续录入下一题。").arg(total);
    } else {
        resData["message"] = "保存失败，数据库异常！";
    }
    sendResponse(socket, MSG_ADD_QUESTION, resData);
}

void TcpServer::handlePublishExam(QTcpSocket* socket, const QJsonObject &data) {
    QString examCode;
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    for(int i = 0; i < 6; ++i) examCode.append(possibleCharacters.at(QRandomGenerator::global()->bounded(possibleCharacters.length())));

    QSqlQuery query;
    query.prepare("INSERT INTO exams (exam_code, subject, duration, class_code) VALUES (:examCode, :subject, :duration, :classCode)");
    query.bindValue(":examCode", examCode);
    query.bindValue(":subject", data["subject"].toString());
    query.bindValue(":duration", data["duration"].toInt());
    query.bindValue(":classCode", data["class_code"].toString());

    bool success = query.exec();
    QJsonObject resData;
    resData["success"] = success;
    resData["message"] = success ? "生成成功！" : "生成失败，数据库异常！";
    if (success) resData["exam_code"] = examCode;

    sendResponse(socket, MSG_PUBLISH_EXAM, resData);
}

void TcpServer::handleGetClassExams(QTcpSocket* socket, const QJsonObject &data) {
    QJsonArray examArray;
    QSqlQuery query;
    query.prepare("SELECT exam_code, subject FROM exams WHERE class_code = :code");
    query.bindValue(":code", data["class_code"].toString());
    query.exec();

    while(query.next()) {
        QJsonObject obj;
        obj["exam_code"] = query.value(0).toString();
        obj["subject"] = query.value(1).toString();
        examArray.append(obj);
    }
    QJsonObject resData;
    resData["exams"] = examArray;
    sendResponse(socket, MSG_GET_CLASS_EXAMS, resData);
}

void TcpServer::handleGetExamScores(QTcpSocket* socket, const QJsonObject &data) {
    QJsonArray scoreArray;
    QSqlQuery query;
    query.prepare("SELECT username, score FROM scores WHERE exam_code = :code ORDER BY score DESC");
    query.bindValue(":code", data["exam_code"].toString());
    query.exec();

    while(query.next()) {
        QJsonObject obj;
        obj["username"] = query.value(0).toString();
        obj["score"] = query.value(1).toInt();
        scoreArray.append(obj);
    }
    QJsonObject resData;
    resData["scores"] = scoreArray;
    sendResponse(socket, MSG_GET_EXAM_SCORES, resData);
}

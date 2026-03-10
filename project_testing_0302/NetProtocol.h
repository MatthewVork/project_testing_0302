#ifndef NETPROTOCOL_H
#define NETPROTOCOL_H

#include <QTcpsocket>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#include <QHeaderView>


enum NetDataType
{
    MSG_LOGIN    = 1001,
    MSG_REGISTER = 1002,
    MSG_LOGOUT   = 1003,
    MSG_JOIN_EXAM = 1004,
    MSG_CHANGE_PWD  = 1008,

    MSG_ADD_QUESTION = 2001,
    MSG_GET_QUESTION = 2002,
    MSG_SUBMIT_EXAM  = 2003,
    MSG_GET_PAPER    = 2004,
    MSG_PUBLISH_EXAM = 2005,
    MSG_GET_CLASS_EXAMS = 2006,
    MSG_GET_EXAM_SCORES = 2007,

    MSG_GET_SCORES = 3001,
    MSG_GET_FILE  = 3002,

    MSG_RESULT_SUCCESS = 4001,
    MSG_RESULT_FAILED  = 4002,
    MSG_HEARTBEAT      = 4003,

    MSG_CREATE_CLASS = 5001,       // 老师请求创建班级
    MSG_GET_CLASSES  = 5002,       // 拉取班级列表
    MSG_GET_CLASS_STUDENTS = 5003, // 拉取某个班级的学生名单 (提前备好)
    MSG_ADD_STUDENT  = 5004,       // 老师拉学生进班 (提前备好)
    MSG_JOIN_CLASS   = 5005,       // 学生通过邀请码加入班级
    MSG_GET_MY_CLASSES = 5006,      // 学生拉取自己已加入的班级列表
};

class NetProtocol
{
public:



    // 1. 打包函数：将类型和数据组合成 JSON 字节流
    static QByteArray packUserAndPass(int msgtype, QString username, QString password) //做重载函数
    {
        QJsonObject dataObj;
        dataObj["username"] = username;
        dataObj["password"] = password;

        QJsonObject rootObj;
        rootObj["type"] = msgtype;
        rootObj["data"] = dataObj;

        QJsonDocument doc(rootObj);

        qDebug()<<doc.toJson(QJsonDocument::Compact);
        return doc.toJson(QJsonDocument::Compact);
    }

    //打包函数---打包考试码信息
    static QByteArray packExamCode(int msgtype, QString examCode)
    {
        QJsonObject dataObj;
        dataObj["exam_code"] = examCode;

        QJsonObject rootObj;
        rootObj["type"] = msgtype;
        rootObj["data"] = dataObj;

        QJsonDocument doc(rootObj);
        return doc.toJson(QJsonDocument::Compact);
    }

    // 2. 加密函数：先异或 (XOR) 再转 Base64
    static QByteArray encrypt(const QByteArray &plainData) {
        QByteArray cipher = plainData;
        const char key = 'K'; //异或加密
        for(int i=0; i<cipher.size(); ++i) {
            cipher[i] = cipher[i] ^ key;
        }
        qDebug()<<cipher.toBase64();
        return cipher.toBase64(); // 转为 Base64 确保传输安全
    }

    // 3. 解密函数：先 Base64 解码再异或还原
    static QByteArray decrypt(const QByteArray &base64Cipher) {
        QByteArray cipher = QByteArray::fromBase64(base64Cipher); // Base64 解码
        const char key = 'K';
        for(int i = 0; i < cipher.size(); ++i) {
            cipher[i] = cipher[i] ^ key; // 异或还原
        }
        return cipher;
    }

    // 4. 发送函数：负责物理写入套接字
    static void sendSecureData(QTcpSocket *socket, const QByteArray &data) {
        if (socket && socket->state() == QAbstractSocket::ConnectedState) {
            socket->write(data);
            socket->flush(); // 确保数据立即发出
        }
    }

    // 5. 一键解析函数：直接从加密字节流变成可用的 JSON 对象
    static QJsonObject parseSecureData(const QByteArray &cipherData) {
        // 第一步：调用内部的解密函数
        QByteArray plain = decrypt(cipherData);

        // 第二步：转换为 JSON 文档
        QJsonDocument doc = QJsonDocument::fromJson(plain);

        // 第三步：如果是合法的对象，直接返回；否则返回空对象
        if (!doc.isNull() && doc.isObject()) {
            return doc.object();
        }
        return QJsonObject();
    }


};

#endif // NETPROTOCOL_H

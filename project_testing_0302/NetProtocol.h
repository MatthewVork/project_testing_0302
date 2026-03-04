#ifndef NETPROTOCOL_H
#define NETPROTOCOL_H

#include <QTcpsocket>
#include <QJsonObject>

class NetProtocol
{
public:

    enum NetDataType
    {
        MSG_LOGIN    = 1001,
        MSG_REGISTER = 1002,
        MSG_LOGOUT   = 1003,

        MSG_ADD_QUESTION = 2001,
        MSG_GET_QUESTION = 2002,
        MSG_SUBMIT_EXAM  = 2003,
        MSG_GET_PAPER    = 2004,

        MSG_SEND_FILE = 3001,
        MSG_GET_FILE  = 3002,

        MSG_RESULT_SUCCESS = 4001,
        MSG_RESULT_FAILED  = 4002,
        MSG_HEARTBEAT      = 4003,
    };

    static QByteArray packData(int msgtype, QString username, QString password) //做重载函数
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



    static QByteArray encrypt(const QByteArray &plainData) {
        QByteArray cipher = plainData;
        const char key = 'K'; // 简单示例：异或加密
        for(int i=0; i<cipher.size(); ++i) {
            cipher[i] = cipher[i] ^ key;
        }
        qDebug()<<cipher.toBase64();
        return cipher.toBase64(); // 转为 Base64 确保传输安全
    }

    static void sendSecureData(QTcpSocket *socket, const QByteArray &plainData) {
        if (!socket || socket->state() != QAbstractSocket::ConnectedState) return;

        // 调用上面的加密函数
        QByteArray secureData = encrypt(plainData);

        // 物理发送
        socket->write(secureData);
    }
};

#endif // NETPROTOCOL_H

#include "tcpserver.h"
#include "ui_tcpserver.h"

#include <QMessageBox>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QHostAddress>
#include <QString>

TcpServer::TcpServer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpServer)
{
    ui->setupUi(this);
    //关联客户端连接信号
    qDebug()<<getRealIP();
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

void TcpServer::read_data() //这个函数不能直接调用
{
    //获取信号发送者对象
    QTcpSocket* msocket = (QTcpSocket*)sender();
    QString msg = msocket->readAll();
    ui->textBrowser->append(msg);
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

QString TcpServer::getRealIP()
{
    QString realIp = "127.0.0.1"; // 默认保底

    QUdpSocket udpSocket;
    // 假装连接谷歌的 DNS 服务器 (8.8.8.8)，端口 53
    // 这一步操作系统会自动筛选出唯一一个通向外网的真实网卡 IP
    udpSocket.connectToHost(QHostAddress("8.8.8.8"), 53);

    // 等待连接（通常瞬间就能完成）
    if (udpSocket.waitForConnected(1000))
    {
        // 获取操作系统分配给这个 socket 的本地 IP
        realIp = udpSocket.localAddress().toString();
    }

    udpSocket.close();
    return realIp;
}


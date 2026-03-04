#include "tcpclient.h"
#include "ui_tcpclient.h"

#include <QMessageBox>

TcpClient::TcpClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    //设置禁用
    ui->sendBtn->setEnabled(false);
    ui->checkBox->setEnabled(false);

    //当连接成功会发送connected信号， 当断开连接会发送disconnected信号
    connect(&msocket,&QTcpSocket::connected,this, [&](){
        ui->connectBtn->setText("断开");
        ui->ipEdit->setEnabled(false);
        ui->portEdit->setEnabled(false);
        ui->sendBtn->setEnabled(true);
        ui->checkBox->setEnabled(true);
        //停止连接
        rnttimer.stop();
    });

    connect(&msocket, &QTcpSocket::disconnected, this, [&](){
        ui->connectBtn->setText("连接");
        ui->ipEdit->setEnabled(true);
        ui->portEdit->setEnabled(true);
        ui->sendBtn->setEnabled(false);
        ui->checkBox->setEnabled(false);

        if(ui->reconnectCb->isChecked()){
            //启动重连
            rnttimer.start(5000);
        }
    });

    //自动发送
    connect(&looptimer, &QTimer::timeout, this, &TcpClient::on_sendBtn_clicked);
    //断线重连
    connect(&rnttimer, &QTimer::timeout, this, &TcpClient::on_connectBtn_clicked);
}

TcpClient::~TcpClient()
{
    delete ui;
}

void TcpClient::on_reconnectCb_clicked(bool checked)
{
    if(checked)
    {
        //保证ip，端口已经输入
        if(ui->ipEdit->text().isEmpty()  || ui->portEdit->text().isEmpty())
        {
            QMessageBox::warning(this,"提示","请输入IP地址和端口号");
            ui->reconnectCb->setChecked(false);
            return ;
        }

        if(ui->connectBtn->text() == "连接")
        {
            rnttimer.start(5000);
        }
    }
}


void TcpClient::on_connectBtn_clicked()
{
    if(ui->connectBtn->text() == "断开")
    {
        msocket.disconnectFromHost();
        return ;
    }
    //连接服务器
    msocket.connectToHost(QHostAddress(ui->ipEdit->text()), ui->portEdit->text().toUShort());
}



void TcpClient::on_checkBox_clicked(bool checked)
{
    if(checked)
    {
        //保证ip，端口已经输入
        if(ui->tmEdit->text().isEmpty())
        {
            QMessageBox::warning(this,"提示","请输入发送间隔时间，单位为ms");
            ui->checkBox->setChecked(false);
            return ;
        }else
        {
            //启动发送定时器
            int t = ui->tmEdit->text().toUInt();
            looptimer.start(t);
        }
    }else
    {
        looptimer.stop();
    }


}


void TcpClient::on_sendBtn_clicked()
{
    //获取要发送的数据
    QString data = ui->textEdit->toPlainText();
    msocket.write(data.toUtf8());
}


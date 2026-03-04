/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpServer
{
public:
    QHBoxLayout *horizontalLayout_3;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *portEdit;
    QPushButton *startBtn;
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *clearSendBtn;
    QPushButton *clearRecvBtn;
    QPushButton *sendBtn;

    void setupUi(QWidget *TcpServer)
    {
        if (TcpServer->objectName().isEmpty())
            TcpServer->setObjectName("TcpServer");
        TcpServer->resize(616, 412);
        horizontalLayout_3 = new QHBoxLayout(TcpServer);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        listWidget = new QListWidget(TcpServer);
        listWidget->setObjectName("listWidget");

        horizontalLayout_3->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        portEdit = new QLineEdit(TcpServer);
        portEdit->setObjectName("portEdit");

        horizontalLayout->addWidget(portEdit);

        startBtn = new QPushButton(TcpServer);
        startBtn->setObjectName("startBtn");

        horizontalLayout->addWidget(startBtn);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(TcpServer);
        textBrowser->setObjectName("textBrowser");

        verticalLayout->addWidget(textBrowser);

        textEdit = new QTextEdit(TcpServer);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        clearSendBtn = new QPushButton(TcpServer);
        clearSendBtn->setObjectName("clearSendBtn");

        horizontalLayout_2->addWidget(clearSendBtn);

        clearRecvBtn = new QPushButton(TcpServer);
        clearRecvBtn->setObjectName("clearRecvBtn");

        horizontalLayout_2->addWidget(clearRecvBtn);

        sendBtn = new QPushButton(TcpServer);
        sendBtn->setObjectName("sendBtn");

        horizontalLayout_2->addWidget(sendBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);
        verticalLayout->setStretch(2, 5);
        verticalLayout->setStretch(3, 1);

        horizontalLayout_3->addLayout(verticalLayout);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);

        retranslateUi(TcpServer);

        QMetaObject::connectSlotsByName(TcpServer);
    } // setupUi

    void retranslateUi(QWidget *TcpServer)
    {
        TcpServer->setWindowTitle(QCoreApplication::translate("TcpServer", "TcpServer", nullptr));
        portEdit->setPlaceholderText(QCoreApplication::translate("TcpServer", "\347\233\221\345\220\254\347\253\257\345\217\243", nullptr));
        startBtn->setText(QCoreApplication::translate("TcpServer", "\345\220\257\345\212\250", nullptr));
        clearSendBtn->setText(QCoreApplication::translate("TcpServer", "\346\270\205\351\231\244\345\217\221\351\200\201", nullptr));
        clearRecvBtn->setText(QCoreApplication::translate("TcpServer", "\346\270\205\351\231\244\346\216\245\346\224\266", nullptr));
        sendBtn->setText(QCoreApplication::translate("TcpServer", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpServer: public Ui_TcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H

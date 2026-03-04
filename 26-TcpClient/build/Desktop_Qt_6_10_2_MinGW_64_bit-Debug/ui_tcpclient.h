/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpClient
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *ipEdit;
    QLineEdit *portEdit;
    QPushButton *connectBtn;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *tmEdit;
    QCheckBox *checkBox;
    QCheckBox *reconnectCb;
    QSpacerItem *verticalSpacer;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *clearRcvBtn;
    QPushButton *clearSndBtn;
    QPushButton *sendBtn;

    void setupUi(QWidget *TcpClient)
    {
        if (TcpClient->objectName().isEmpty())
            TcpClient->setObjectName("TcpClient");
        TcpClient->resize(510, 413);
        verticalLayout_3 = new QVBoxLayout(TcpClient);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        ipEdit = new QLineEdit(TcpClient);
        ipEdit->setObjectName("ipEdit");

        horizontalLayout_3->addWidget(ipEdit);

        portEdit = new QLineEdit(TcpClient);
        portEdit->setObjectName("portEdit");

        horizontalLayout_3->addWidget(portEdit);

        connectBtn = new QPushButton(TcpClient);
        connectBtn->setObjectName("connectBtn");

        horizontalLayout_3->addWidget(connectBtn);


        verticalLayout_3->addLayout(horizontalLayout_3);

        textBrowser = new QTextBrowser(TcpClient);
        textBrowser->setObjectName("textBrowser");

        verticalLayout_3->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        tmEdit = new QLineEdit(TcpClient);
        tmEdit->setObjectName("tmEdit");

        verticalLayout->addWidget(tmEdit);

        checkBox = new QCheckBox(TcpClient);
        checkBox->setObjectName("checkBox");

        verticalLayout->addWidget(checkBox);


        verticalLayout_2->addLayout(verticalLayout);

        reconnectCb = new QCheckBox(TcpClient);
        reconnectCb->setObjectName("reconnectCb");

        verticalLayout_2->addWidget(reconnectCb);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        textEdit = new QTextEdit(TcpClient);
        textEdit->setObjectName("textEdit");

        horizontalLayout->addWidget(textEdit);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);

        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        clearRcvBtn = new QPushButton(TcpClient);
        clearRcvBtn->setObjectName("clearRcvBtn");

        horizontalLayout_2->addWidget(clearRcvBtn);

        clearSndBtn = new QPushButton(TcpClient);
        clearSndBtn->setObjectName("clearSndBtn");

        horizontalLayout_2->addWidget(clearSndBtn);

        sendBtn = new QPushButton(TcpClient);
        sendBtn->setObjectName("sendBtn");

        horizontalLayout_2->addWidget(sendBtn);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 10);
        verticalLayout_3->setStretch(2, 5);
        verticalLayout_3->setStretch(3, 1);

        retranslateUi(TcpClient);

        QMetaObject::connectSlotsByName(TcpClient);
    } // setupUi

    void retranslateUi(QWidget *TcpClient)
    {
        TcpClient->setWindowTitle(QCoreApplication::translate("TcpClient", "TcpClient", nullptr));
        ipEdit->setPlaceholderText(QCoreApplication::translate("TcpClient", "\346\234\215\345\212\241\345\231\250IP", nullptr));
        portEdit->setPlaceholderText(QCoreApplication::translate("TcpClient", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        connectBtn->setText(QCoreApplication::translate("TcpClient", "\350\277\236\346\216\245", nullptr));
        tmEdit->setPlaceholderText(QCoreApplication::translate("TcpClient", "\351\227\264\351\232\224ms", nullptr));
        checkBox->setText(QCoreApplication::translate("TcpClient", "\350\277\236\347\273\255\345\217\221\351\200\201", nullptr));
        reconnectCb->setText(QCoreApplication::translate("TcpClient", "\346\226\255\347\272\277\351\207\215\350\277\236", nullptr));
        clearRcvBtn->setText(QCoreApplication::translate("TcpClient", "\346\270\205\351\231\244\346\216\245\346\224\266", nullptr));
        clearSndBtn->setText(QCoreApplication::translate("TcpClient", "\346\270\205\351\231\244\345\217\221\351\200\201", nullptr));
        sendBtn->setText(QCoreApplication::translate("TcpClient", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H

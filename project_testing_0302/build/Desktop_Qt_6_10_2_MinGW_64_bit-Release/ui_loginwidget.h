/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *Laber_Login;
    QLineEdit *Username;
    QLineEdit *Password;
    QPushButton *loginBtn;
    QPushButton *registerBtn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName("LoginWidget");
        LoginWidget->resize(800, 500);
        LoginWidget->setStyleSheet(QString::fromUtf8("/* ================= 1. \345\205\250\345\261\200\350\203\214\346\231\257\344\270\216\345\255\227\344\275\223 ================= */\n"
"QWidget {\n"
"    background-color: #F3F4F6;\n"
"    color: #333333;\n"
"    font-family: \"Microsoft YaHei\";\n"
"}\n"
"\n"
"/* ================= 2. \346\236\201\345\205\266\344\270\235\346\273\221\347\232\204\346\211\201\345\271\263\345\214\226\346\214\211\351\222\256 ================= */\n"
"QPushButton {\n"
"    background-color: #0078D4; \n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px; \n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #106EBE; \n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #005A9E; \n"
"}\n"
"QPushButton:disabled {\n"
"    background-color: #CCCCCC; \n"
"    color: #888888;\n"
"}\n"
"\n"
"/* ================= 3. \350\276\223\345\205\245\346\241\206\347\232\204\347\216\260\344\273\243\346\204\237 ================= */\n"
"QLineEdit, QTextEdit {\n"
"    border: 1px"
                        " solid #D1D5DB;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    background-color: #FFFFFF;\n"
"    selection-background-color: #0078D4;\n"
"}\n"
"QLineEdit:focus, QTextEdit:focus {\n"
"    border: 2px solid #0078D4; \n"
"    background-color: #FAFCFF;\n"
"}\n"
"\n"
"/* ================= 4. \345\267\246\344\276\247\351\253\230\347\272\247\345\257\274\350\210\252\346\240\217 ================= */\n"
"QListWidget, QTreeWidget {\n"
"    background-color: #FFFFFF;\n"
"    border: 1px solid #E5E7EB;\n"
"    border-radius: 8px;\n"
"    outline: none; \n"
"}\n"
"QListWidget::item, QTreeWidget::item {\n"
"    padding: 10px;\n"
"    border-radius: 4px;\n"
"    margin: 2px 4px; \n"
"}\n"
"QListWidget::item:hover, QTreeWidget::item:hover {\n"
"    background-color: #F3F4F6; \n"
"}\n"
"QListWidget::item:selected, QTreeWidget::item:selected {\n"
"    background-color: #0078D4; \n"
"    color: white;\n"
"}\n"
"\n"
"/* ================= 5. \350\241\250\346\240\274\346\236\201\345\205\266\345\271\262\345\207\200\347"
                        "\232\204\350\247\206\350\247\211 ================= */\n"
"QTableWidget {\n"
"    background-color: #FFFFFF;\n"
"    border: 1px solid #E5E7EB;\n"
"    border-radius: 8px;\n"
"    gridline-color: #F3F4F6; \n"
"    selection-background-color: #E1F0FF; \n"
"    selection-color: #000000;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #F9FAFB;\n"
"    border: none;\n"
"    border-bottom: 2px solid #0078D4; \n"
"    padding: 8px;\n"
"    font-weight: bold;\n"
"    color: #4B5563;\n"
"}\n"
"\n"
"/* ================= 6. \344\270\213\346\213\211\346\241\206\344\270\216\346\240\207\347\255\276 ================= */\n"
"QComboBox {\n"
"    border: 1px solid #D1D5DB;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    background-color: #FFFFFF;\n"
"}\n"
"QComboBox:hover {\n"
"    border: 1px solid #0078D4;\n"
"}\n"
"QLabel {\n"
"    background-color: transparent; \n"
"    color: #374151;\n"
"}"));
        gridLayout = new QGridLayout(LoginWidget);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 75, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(265, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        frame = new QFrame(LoginWidget);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(240, 320));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName("gridLayout_2");
        Laber_Login = new QLabel(frame);
        Laber_Login->setObjectName("Laber_Login");
        Laber_Login->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(Laber_Login, 0, 0, 1, 2);

        Username = new QLineEdit(frame);
        Username->setObjectName("Username");

        gridLayout_2->addWidget(Username, 1, 0, 1, 2);

        Password = new QLineEdit(frame);
        Password->setObjectName("Password");
        Password->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout_2->addWidget(Password, 2, 0, 1, 2);

        loginBtn = new QPushButton(frame);
        loginBtn->setObjectName("loginBtn");
        loginBtn->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(loginBtn, 3, 0, 1, 1);

        registerBtn = new QPushButton(frame);
        registerBtn->setObjectName("registerBtn");
        registerBtn->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(registerBtn, 3, 1, 1, 1);


        gridLayout->addWidget(frame, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(265, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 75, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QCoreApplication::translate("LoginWidget", "Form", nullptr));
        Laber_Login->setText(QCoreApplication::translate("LoginWidget", "\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        Username->setPlaceholderText(QCoreApplication::translate("LoginWidget", "\350\264\246\345\217\267", nullptr));
        Password->setPlaceholderText(QCoreApplication::translate("LoginWidget", "\345\257\206\347\240\201", nullptr));
        loginBtn->setText(QCoreApplication::translate("LoginWidget", "\347\231\273\345\275\225", nullptr));
        registerBtn->setText(QCoreApplication::translate("LoginWidget", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H

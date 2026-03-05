/********************************************************************************
** Form generated from reading UI file 'registerwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWIDGET_H
#define UI_REGISTERWIDGET_H

#include <QtCore/QLocale>
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

class Ui_RegisterWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *userEdit;
    QLabel *label_3;
    QLineEdit *pwdEdit;
    QLabel *label_4;
    QLineEdit *pwdConfirmEdit;
    QLabel *label;
    QPushButton *registerBtn;
    QPushButton *backBtn;

    void setupUi(QWidget *RegisterWidget)
    {
        if (RegisterWidget->objectName().isEmpty())
            RegisterWidget->setObjectName("RegisterWidget");
        RegisterWidget->resize(800, 500);
        RegisterWidget->setStyleSheet(QString::fromUtf8("/* --- 1. \345\205\250\345\261\200\345\237\272\347\241\200\350\256\276\345\256\232 --- */\n"
"QWidget {\n"
"    font-family: \"SF Pro Display\", \"Helvetica Neue\", \"Segoe UI\", \"Microsoft YaHei\";\n"
"    color: #1d1d1f; /* \350\213\271\346\236\234\346\240\207\345\207\206\346\267\261\347\201\260\350\211\262\346\226\207\346\234\254 */\n"
"    outline: none;  /* \345\216\273\346\216\211\347\202\271\345\207\273\346\227\266\347\232\204\350\231\232\347\272\277\346\241\206 */\n"
"}\n"
"\n"
"/* --- 2. \351\200\232\347\224\250\345\256\271\345\231\250 (\345\246\202\344\275\240\347\232\204 loginCard) --- */\n"
"/* \345\217\252\350\246\201\346\230\257 QFrame \351\203\275\344\274\232\350\207\252\345\212\250\345\217\230\346\210\220\350\277\231\347\247\215\345\215\212\351\200\217\346\230\216\347\243\250\347\240\202\350\264\250\346\204\237 */\n"
"QFrame {\n"
"    background-color: rgba(255, 255, 255, 0.7); \n"
"    border: 1px solid rgba(255, 255, 255, 0.3);\n"
"    border-radius: 18px;\n"
"}\n"
"\n"
"/* --- 3. \351\200\232"
                        "\347\224\250\350\276\223\345\205\245\346\241\206 (QLineEdit, QTextEdit) --- */\n"
"QLineEdit, QTextEdit {\n"
"    background-color: rgba(255, 255, 255, 0.5);\n"
"    border: 1px solid rgba(0, 0, 0, 0.1);\n"
"    border-radius: 10px;\n"
"    padding: 8px 12px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* \350\276\223\345\205\245\346\241\206\350\201\232\347\204\246\346\225\210\346\236\234\357\274\232\346\240\207\345\277\227\346\200\247\347\232\204\350\223\235\350\211\262\345\205\211\346\231\225 */\n"
"QLineEdit:focus, QTextEdit:focus {\n"
"    border: 2px solid #007AFF;\n"
"    background-color: rgba(255, 255, 255, 0.9);\n"
"}\n"
"\n"
"/* --- 4. \351\200\232\347\224\250\346\214\211\351\222\256 (QPushButton) --- */\n"
"QPushButton {\n"
"    background-color: #007AFF; /* \350\213\271\346\236\234\350\223\235 */\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    padding: 10px 20px;\n"
"    font-weight: 600;\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234\357\274\232\351"
                        "\242\234\350\211\262\347\225\245\345\276\256\345\212\240\346\267\261 */\n"
"QPushButton:hover {\n"
"    background-color: #0063CC;\n"
"}\n"
"\n"
"/* \346\214\211\344\270\213\357\274\232\346\230\216\346\230\276\347\232\204\345\217\215\351\246\210\346\204\237 */\n"
"QPushButton:pressed {\n"
"    background-color: #0051A8;\n"
"}\n"
"\n"
"/* \347\246\201\347\224\250\347\212\266\346\200\201\357\274\232\345\217\230\347\201\260 */\n"
"QPushButton:disabled {\n"
"    background-color: #d2d2d7;\n"
"    color: #86868b;\n"
"}\n"
"\n"
"/* --- 5. \346\240\207\347\255\276\344\270\216\346\226\207\346\234\254 (QLabel) --- */\n"
"QLabel {\n"
"    background-color: transparent;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* --- 6. \346\273\232\345\212\250\346\235\241\347\276\216\345\214\226 (QScrollBar) --- */\n"
"/* \350\256\251\346\273\232\345\212\250\346\235\241\345\203\217 iOS \344\270\200\346\240\267\347\256\200\346\264\201 */\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: rgba(0, 0, 0, 0.05);\n"
"    width"
                        ": 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: rgba(0, 0, 0, 0.2);\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: rgba(0, 0, 0, 0.3);\n"
"}"));
        gridLayout = new QGridLayout(RegisterWidget);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_2 = new QSpacerItem(20, 75, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(256, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(256, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 75, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        frame = new QFrame(RegisterWidget);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(240, 320));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName("gridLayout_2");
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        userEdit = new QLineEdit(frame);
        userEdit->setObjectName("userEdit");

        gridLayout_2->addWidget(userEdit, 1, 1, 1, 2);

        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        pwdEdit = new QLineEdit(frame);
        pwdEdit->setObjectName("pwdEdit");
        pwdEdit->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        pwdEdit->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        pwdEdit->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout_2->addWidget(pwdEdit, 2, 1, 1, 2);

        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        pwdConfirmEdit = new QLineEdit(frame);
        pwdConfirmEdit->setObjectName("pwdConfirmEdit");
        pwdConfirmEdit->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout_2->addWidget(pwdConfirmEdit, 3, 1, 1, 2);

        label = new QLabel(frame);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 3);

        registerBtn = new QPushButton(frame);
        registerBtn->setObjectName("registerBtn");

        gridLayout_2->addWidget(registerBtn, 4, 0, 1, 1);

        backBtn = new QPushButton(frame);
        backBtn->setObjectName("backBtn");

        gridLayout_2->addWidget(backBtn, 4, 2, 1, 1);


        gridLayout->addWidget(frame, 1, 1, 1, 1);


        retranslateUi(RegisterWidget);

        QMetaObject::connectSlotsByName(RegisterWidget);
    } // setupUi

    void retranslateUi(QWidget *RegisterWidget)
    {
        RegisterWidget->setWindowTitle(QCoreApplication::translate("RegisterWidget", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterWidget", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterWidget", "\346\263\250\345\206\214\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterWidget", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("RegisterWidget", "\346\263\250\345\206\214\347\225\214\351\235\242", nullptr));
        registerBtn->setText(QCoreApplication::translate("RegisterWidget", "\346\263\250\345\206\214", nullptr));
        backBtn->setText(QCoreApplication::translate("RegisterWidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWidget: public Ui_RegisterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWIDGET_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *loginCard;
    QLabel *Password;
    QLabel *Username;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 480);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8("/* =========================================\n"
"   \345\205\250\345\261\200\345\237\272\347\241\200\350\256\276\347\275\256 (\350\203\214\346\231\257\344\270\216\345\255\227\344\275\223)\n"
"========================================= */\n"
"QWidget {\n"
"    font-family: \"Microsoft YaHei\", \"Segoe UI\", sans-serif;\n"
"    font-size: 14px;\n"
"    color: #333333;\n"
"    background-color: #F5F7FA; /* \346\236\201\346\265\205\347\232\204\350\223\235\347\201\260\350\211\262\357\274\214\344\277\235\346\212\244\350\247\206\345\212\233\344\270\224\346\230\276\351\253\230\347\272\247 */\n"
"}\n"
"\n"
"/* =========================================\n"
"   \351\242\230\347\233\256\345\261\225\347\244\272\345\214\272 (\347\261\273\344\274\274\344\270\200\345\274\240\347\231\275\347\272\270)\n"
"========================================= */\n"
"QTextBrowser {\n"
"    background-color: #FFFFFF;\n"
"    border: 1px solid #E4E7ED;\n"
"    border-radius: 8px; /* \345\234\206\350\247\222\350\276\271\346\241\206 */\n"
"    pad"
                        "ding: 20px;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"/* =========================================\n"
"   \345\215\225\351\200\211\351\242\230 / \345\244\232\351\200\211\351\242\230 (\346\270\205\347\210\275\347\232\204\351\200\211\344\270\255\346\225\210\346\236\234)\n"
"========================================= */\n"
"QRadioButton, QCheckBox {\n"
"    spacing: 12px;     /* \345\234\206\345\234\210\345\222\214\346\226\207\345\255\227\347\232\204\351\227\264\350\267\235 */\n"
"    padding: 8px;\n"
"    font-size: 15px;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"    border-radius: 10px; /* \350\256\251\345\215\225\351\200\211\346\241\206\345\217\230\346\210\220\345\256\214\347\276\216\347\232\204\345\234\206\345\275\242 */\n"
"    border: 2px solid #DCDFE6;\n"
"    background-color: #FFFFFF;\n"
"}\n"
"\n"
"QRadioButton::indicator:hover {\n"
"    border: 2px solid #409EFF; /* \351\274\240\346\240\207\346\202\254\345\201\234\345\217\230\350\223\235 */\n"
"}\n"
"\n"
"QRad"
                        "ioButton::indicator:checked {\n"
"    border: 5px solid #409EFF; /* \351\200\211\344\270\255\346\227\266\350\276\271\346\241\206\345\212\240\347\262\227\357\274\214\345\275\242\346\210\220\350\223\235\345\234\206\347\202\271\347\232\204\350\247\206\350\247\211\346\225\210\346\236\234 */\n"
"    background-color: #FFFFFF;\n"
"}\n"
"\n"
"/* =========================================\n"
"   \346\231\256\351\200\232\346\214\211\351\222\256 (\344\270\212\344\270\200\351\242\230 / \344\270\213\344\270\200\351\242\230)\n"
"========================================= */\n"
"QPushButton {\n"
"    background-color: #FFFFFF;\n"
"    border: 1px solid #DCDFE6;\n"
"    color: #606266;\n"
"    border-radius: 4px;\n"
"    padding: 8px 20px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: #409EFF;\n"
"    border-color: #C6E2FF;\n"
"    background-color: #ECF5FF; /* \346\202\254\345\201\234\346\227\266\346\267\241\346\267\241\347\232\204\350\223\235\350\211\262\350\203\214\346\231\257 */\n"
"}\n"
"\n"
""
                        "QPushButton:pressed {\n"
"    color: #3A8EE6;\n"
"    border-color: #3A8EE6;\n"
"}\n"
"\n"
"/* =========================================\n"
"   \351\253\230\344\272\256\344\270\223\345\261\236\346\214\211\351\222\256 (\344\272\244\345\215\267\346\214\211\351\222\256)\n"
"   \346\263\250\346\204\217\357\274\232\345\234\250 Qt Designer \344\270\255\351\234\200\345\260\206\346\255\244\346\214\211\351\222\256\347\232\204 objectName \346\224\271\344\270\272 \"submitBtn\"\n"
"========================================= */\n"
"QPushButton#submitBtn {\n"
"    background-color: #409EFF; /* \344\270\273\351\242\230\350\223\235 */\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
"QPushButton#submitBtn:hover {\n"
"    background-color: #66B1FF;\n"
"}\n"
"\n"
"/* =========================================\n"
"   \345\267\246\344\276\247\347\255\224\351\242\230\345\215\241\346\226\271\345\235\227\346\214\211\351\222\256\n"
"   \346\263\250\346\204\217\357\274\232\345\234\250 Qt Designer \344\270\255\351\234\200\345\260"
                        "\206\350\277\231\344\272\233\346\214\211\351\222\256\347\232\204 objectName \346\224\271\344\270\272 \"gridBtn\"\n"
"========================================= */\n"
"QPushButton#gridBtn {\n"
"    background-color: #FFFFFF;\n"
"    border: 1px solid #EBEEF5;\n"
"    border-radius: 4px;\n"
"    min-width: 35px;\n"
"    min-height: 35px;\n"
"    padding: 0px;\n"
"}\n"
"\n"
"QPushButton#gridBtn:hover {\n"
"    border-color: #409EFF;\n"
"}\n"
"\n"
"/* \347\250\215\345\220\216\346\210\221\344\273\254\345\217\257\344\273\245\347\224\250 C++ \344\273\243\347\240\201\347\273\231\347\255\224\350\277\207\347\232\204\351\242\230\345\212\240\344\270\212 \"answered\" \345\261\236\346\200\247\357\274\214\350\256\251\345\256\203\345\217\230\347\273\277 */\n"
"QPushButton#gridBtn[state=\"answered\"] {\n"
"    background-color: #67C23A; /* \346\210\220\345\212\237\347\273\277 */\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"}\n"
"\n"
"/* =========================================\n"
"   \345\200\222\350\256\241\346\227\266\350"
                        "\255\246\345\221\212\346\226\207\345\255\227\n"
"   \346\263\250\346\204\217\357\274\232\345\234\250 Qt Designer \344\270\255\351\234\200\345\260\206\345\200\222\350\256\241\346\227\266\347\232\204\346\240\207\347\255\276 objectName \346\224\271\344\270\272 \"timerLabel\"\n"
"========================================= */\n"
"QLabel#timerLabel {\n"
"    color: #F56C6C; /* \350\255\246\347\244\272\347\272\242 */\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* =========================================\n"
"   \350\276\223\345\205\245\346\241\206 (\345\255\246\345\217\267\343\200\201\345\247\223\345\220\215\343\200\201\347\231\273\345\275\225\345\257\206\347\240\201)\n"
"========================================= */\n"
"QLineEdit {\n"
"    background-color: #FFFFFF;\n"
"    border: 1px solid #DCDFE6; /* \351\273\230\350\256\244\347\201\260\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 4px;        /* \350\275\273\345\276\256\345\234\206\350\247\222 */\n"
"    padding: 8px 12px;   "
                        "      /* \350\256\251\346\226\207\345\255\227\347\246\273\350\276\271\346\241\206\346\234\211\347\202\271\350\267\235\347\246\273\357\274\214\344\270\215\346\213\245\346\214\244 */\n"
"    selection-background-color: #409EFF; /* \351\200\211\344\270\255\346\226\207\345\255\227\346\227\266\347\232\204\350\203\214\346\231\257\350\211\262 */\n"
"    color: #606266;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border-color: #C0C4CC; /* \351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\350\276\271\346\241\206\347\250\215\345\276\256\345\212\240\346\267\261 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #409EFF; /* \350\216\267\345\217\226\347\204\246\347\202\271\346\227\266\357\274\214\350\276\271\346\241\206\345\217\230\346\210\220\344\270\273\351\242\230\350\223\235\350\211\262 */\n"
"    outline: none;         /* \345\216\273\346\216\211\351\273\230\350\256\244\347\232\204\350\223\235\350\211\262\345\244\226\345\234\210 */\n"
"}\n"
"\n"
"/* \345\246\202\346\236\234\344\275"
                        "\240\350\256\276\347\275\256\344\272\206\345\217\252\350\257\273\346\250\241\345\274\217\347\232\204\350\276\223\345\205\245\346\241\206 */\n"
"QLineEdit:read-only {\n"
"    background-color: #F5F7FA;\n"
"    color: #909399;\n"
"    border-color: #E4E7ED;\n"
"}\n"
"\n"
"/* \347\231\273\345\275\225\345\215\241\347\211\207\347\232\204\344\270\273\344\275\223\346\240\267\345\274\217 */\n"
"#loginCard {\n"
"    background-color: #FFFFFF;      /* \347\272\257\347\231\275\350\203\214\346\231\257 */\n"
"    border: 1px solid #DCDFE6;      /* \346\265\205\347\201\260\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 12px;            /* \345\234\206\350\247\222\346\225\210\346\236\234 */\n"
"}\n"
"\n"
"/* \345\242\236\345\212\240\346\202\254\346\265\256\346\204\237\357\274\210\345\217\257\351\200\211\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\350\276\271\346\241\206\345\217\230\350\223\235\357\274\211 */\n"
"#loginCard:hover {\n"
"    border: 1px solid #409EFF;\n"
"}\n"
"\n"
"/*"
                        " \345\234\250\344\275\240\347\232\204\346\240\267\345\274\217\350\241\250\351\207\214\346\211\276\345\210\260 QLabel \347\232\204\351\203\250\345\210\206\357\274\214\346\210\226\350\200\205\347\233\264\346\216\245\347\273\231\351\202\243\344\270\252\346\240\207\351\242\230\350\256\276\347\275\256 */\n"
"QLabel {\n"
"    background-color: transparent; /* \350\256\276\347\275\256\350\203\214\346\231\257\344\270\272\351\200\217\346\230\216 */\n"
"    border: none;                 /* \347\241\256\344\277\235\346\262\241\346\234\211\350\276\271\346\241\206\347\272\277 */\n"
"}\n"
"\n"
"QMainWindow #centralwidget {\n"
"    border-image: url(:/pic/Login_menu.jpg);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        loginCard = new QFrame(centralwidget);
        loginCard->setObjectName("loginCard");
        sizePolicy.setHeightForWidth(loginCard->sizePolicy().hasHeightForWidth());
        loginCard->setSizePolicy(sizePolicy);
        loginCard->setMinimumSize(QSize(400, 240));
        loginCard->setFrameShape(QFrame::Shape::StyledPanel);
        loginCard->setFrameShadow(QFrame::Shadow::Raised);
        Password = new QLabel(loginCard);
        Password->setObjectName("Password");
        Password->setGeometry(QRect(110, 90, 49, 14));
        Username = new QLabel(loginCard);
        Username->setObjectName("Username");
        Username->setGeometry(QRect(110, 60, 49, 14));
        lineEdit = new QLineEdit(loginCard);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(150, 50, 113, 31));
        lineEdit_2 = new QLineEdit(loginCard);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(150, 90, 113, 31));
        pushButton = new QPushButton(loginCard);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 130, 71, 31));
        label = new QLabel(loginCard);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 0, 200, 40));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        label->setFont(font);
        label->setMidLineWidth(-1);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_2 = new QPushButton(loginCard);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(210, 130, 71, 31));

        gridLayout->addWidget(loginCard, 1, 1, 2, 1);

        horizontalSpacer_2 = new QSpacerItem(185, 114, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 2, 1);

        verticalSpacer = new QSpacerItem(398, 80, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(398, 81, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(185, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 2, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\200\203\350\257\225\347\225\214\351\235\242", nullptr));
        Password->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        Username->setText(QCoreApplication::translate("MainWindow", "\350\264\246\345\217\267", nullptr));
        lineEdit_2->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216\350\277\233\345\205\245\350\200\203\350\257\225\351\241\265\351\235\242", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

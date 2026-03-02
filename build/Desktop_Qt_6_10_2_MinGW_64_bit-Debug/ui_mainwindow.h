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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *Username;
    QLabel *Password;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 480);
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
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 70, 151, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        label->setFont(font);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(330, 140, 113, 31));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(330, 180, 113, 31));
        Username = new QLabel(centralwidget);
        Username->setObjectName("Username");
        Username->setGeometry(QRect(260, 140, 49, 14));
        Password = new QLabel(centralwidget);
        Password->setObjectName("Password");
        Password->setGeometry(QRect(260, 180, 49, 14));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(317, 220, 141, 91));
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
        label->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216\350\277\233\345\205\245\350\200\203\350\257\225\351\241\265\351\235\242", nullptr));
        lineEdit_2->setText(QString());
        Username->setText(QCoreApplication::translate("MainWindow", "\350\264\246\345\217\267", nullptr));
        Password->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainmenuwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENUWIDGET_H
#define UI_MAINMENUWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenuWidget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_examCode;
    QPushButton *btn_joinExam;
    QWidget *page3;
    QWidget *widget1;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLineEdit *lineEdit_classCode;
    QPushButton *btn_joinClass;
    QTableWidget *tableWidget_myClasses;
    QWidget *page4;
    QPushButton *pushButton_5;
    QPushButton *btn_history;
    QTableWidget *tableWidget_scores;
    QWidget *page2;
    QWidget *widget2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_oldPwd;
    QLabel *label_4;
    QLineEdit *lineEdit_newPwd;
    QLabel *label_5;
    QLineEdit *lineEdit_Conform;
    QPushButton *btn_confirm;
    QWidget *widget3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Username;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *LabelTime;
    QPushButton *logoutBtn;
    QListWidget *listWidget;

    void setupUi(QWidget *MainMenuWidget)
    {
        if (MainMenuWidget->objectName().isEmpty())
            MainMenuWidget->setObjectName("MainMenuWidget");
        MainMenuWidget->resize(800, 420);
        MainMenuWidget->setStyleSheet(QString::fromUtf8("/* ================= 1. \345\205\250\345\261\200\350\203\214\346\231\257\344\270\216\345\255\227\344\275\223 ================= */\n"
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
        stackedWidget = new QStackedWidget(MainMenuWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(20, 10, 581, 361));
        page1 = new QWidget();
        page1->setObjectName("page1");
        widget = new QWidget(page1);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(210, 120, 141, 101));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_examCode = new QLineEdit(widget);
        lineEdit_examCode->setObjectName("lineEdit_examCode");

        verticalLayout_2->addWidget(lineEdit_examCode);

        btn_joinExam = new QPushButton(widget);
        btn_joinExam->setObjectName("btn_joinExam");

        verticalLayout_2->addWidget(btn_joinExam);

        stackedWidget->addWidget(page1);
        page3 = new QWidget();
        page3->setObjectName("page3");
        widget1 = new QWidget(page3);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(10, 10, 541, 351));
        gridLayout_2 = new QGridLayout(widget1);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget1);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_classCode = new QLineEdit(widget1);
        lineEdit_classCode->setObjectName("lineEdit_classCode");

        gridLayout_2->addWidget(lineEdit_classCode, 1, 0, 1, 1);

        btn_joinClass = new QPushButton(widget1);
        btn_joinClass->setObjectName("btn_joinClass");

        gridLayout_2->addWidget(btn_joinClass, 1, 1, 1, 1);

        tableWidget_myClasses = new QTableWidget(widget1);
        tableWidget_myClasses->setObjectName("tableWidget_myClasses");

        gridLayout_2->addWidget(tableWidget_myClasses, 2, 0, 1, 2);

        stackedWidget->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName("page4");
        pushButton_5 = new QPushButton(page4);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(10, 370, 68, 21));
        btn_history = new QPushButton(page4);
        btn_history->setObjectName("btn_history");
        btn_history->setGeometry(QRect(0, 0, 91, 31));
        tableWidget_scores = new QTableWidget(page4);
        tableWidget_scores->setObjectName("tableWidget_scores");
        tableWidget_scores->setGeometry(QRect(5, 31, 541, 321));
        stackedWidget->addWidget(page4);
        page2 = new QWidget();
        page2->setObjectName("page2");
        widget2 = new QWidget(page2);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(190, 65, 201, 231));
        gridLayout = new QGridLayout(widget2);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget2);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_oldPwd = new QLineEdit(widget2);
        lineEdit_oldPwd->setObjectName("lineEdit_oldPwd");

        gridLayout->addWidget(lineEdit_oldPwd, 0, 1, 1, 1);

        label_4 = new QLabel(widget2);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        lineEdit_newPwd = new QLineEdit(widget2);
        lineEdit_newPwd->setObjectName("lineEdit_newPwd");

        gridLayout->addWidget(lineEdit_newPwd, 1, 1, 1, 1);

        label_5 = new QLabel(widget2);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        lineEdit_Conform = new QLineEdit(widget2);
        lineEdit_Conform->setObjectName("lineEdit_Conform");

        gridLayout->addWidget(lineEdit_Conform, 2, 1, 1, 1);

        btn_confirm = new QPushButton(widget2);
        btn_confirm->setObjectName("btn_confirm");

        gridLayout->addWidget(btn_confirm, 3, 1, 1, 1);

        stackedWidget->addWidget(page2);
        widget3 = new QWidget(MainMenuWidget);
        widget3->setObjectName("widget3");
        widget3->setGeometry(QRect(610, 18, 171, 361));
        verticalLayout = new QVBoxLayout(widget3);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        Username = new QLabel(widget3);
        Username->setObjectName("Username");
        Username->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(Username);

        label = new QLabel(widget3);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(widget3);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_2);

        LabelTime = new QLabel(widget3);
        LabelTime->setObjectName("LabelTime");
        LabelTime->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(LabelTime);


        verticalLayout->addLayout(horizontalLayout);

        logoutBtn = new QPushButton(widget3);
        logoutBtn->setObjectName("logoutBtn");

        verticalLayout->addWidget(logoutBtn);

        listWidget = new QListWidget(widget3);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);


        retranslateUi(MainMenuWidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainMenuWidget);
    } // setupUi

    void retranslateUi(QWidget *MainMenuWidget)
    {
        MainMenuWidget->setWindowTitle(QCoreApplication::translate("MainMenuWidget", "Form", nullptr));
        lineEdit_examCode->setPlaceholderText(QCoreApplication::translate("MainMenuWidget", "\350\257\267\350\276\223\345\205\245\350\200\203\350\257\225\347\240\201", nullptr));
        btn_joinExam->setText(QCoreApplication::translate("MainMenuWidget", "\350\277\233\345\205\245\350\200\203\350\257\225", nullptr));
        label_6->setText(QCoreApplication::translate("MainMenuWidget", "\346\210\221\347\232\204\347\217\255\347\272\247", nullptr));
        btn_joinClass->setText(QCoreApplication::translate("MainMenuWidget", "\345\212\240\345\205\245\347\217\255\347\272\247", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainMenuWidget", "page3", nullptr));
        btn_history->setText(QCoreApplication::translate("MainMenuWidget", "\346\237\245\350\257\242\346\210\220\347\273\251", nullptr));
        label_3->setText(QCoreApplication::translate("MainMenuWidget", "\345\216\237\345\257\206\347\240\201\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainMenuWidget", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainMenuWidget", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        btn_confirm->setText(QCoreApplication::translate("MainMenuWidget", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        Username->setText(QCoreApplication::translate("MainMenuWidget", "Username", nullptr));
        label->setText(QCoreApplication::translate("MainMenuWidget", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("MainMenuWidget", "\345\275\223\345\211\215\346\227\266\351\227\264:", nullptr));
        LabelTime->setText(QCoreApplication::translate("MainMenuWidget", "10:00", nullptr));
        logoutBtn->setText(QCoreApplication::translate("MainMenuWidget", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainMenuWidget", "\350\200\203\350\257\225\345\244\247\345\216\205", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainMenuWidget", "\346\210\221\347\232\204\347\217\255\347\272\247", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainMenuWidget", "\346\210\220\347\273\251\346\237\245\350\257\242", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainMenuWidget", "\344\270\252\344\272\272\344\270\255\345\277\203", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class MainMenuWidget: public Ui_MainMenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENUWIDGET_H

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
#include <QtWidgets/QCalendarWidget>
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
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QListWidget *listWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *Username;
    QPushButton *logoutBtn;
    QLabel *label_2;
    QLabel *LabelTime;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QPushButton *pushButton_3;
    QPushButton *btn_joinExam;
    QLineEdit *lineEdit_examCode;
    QWidget *page3;
    QPushButton *pushButton_4;
    QWidget *page4;
    QPushButton *pushButton_5;
    QPushButton *btn_history;
    QTableWidget *tableWidget_scores;
    QWidget *page2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_oldPwd;
    QLabel *label_4;
    QLineEdit *lineEdit_newPwd;
    QLabel *label_5;
    QLineEdit *lineEdit_Conform;
    QPushButton *btn_confirm;
    QPushButton *pushButton_6;

    void setupUi(QWidget *MainMenuWidget)
    {
        if (MainMenuWidget->objectName().isEmpty())
            MainMenuWidget->setObjectName("MainMenuWidget");
        MainMenuWidget->resize(800, 500);
        pushButton_2 = new QPushButton(MainMenuWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 450, 68, 21));
        pushButton = new QPushButton(MainMenuWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 430, 68, 21));
        listWidget = new QListWidget(MainMenuWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(540, 230, 61, 81));
        layoutWidget = new QWidget(MainMenuWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(503, 10, 291, 211));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        calendarWidget = new QCalendarWidget(layoutWidget);
        calendarWidget->setObjectName("calendarWidget");

        verticalLayout->addWidget(calendarWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label);

        Username = new QLabel(layoutWidget);
        Username->setObjectName("Username");
        Username->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(Username);

        logoutBtn = new QPushButton(layoutWidget);
        logoutBtn->setObjectName("logoutBtn");

        horizontalLayout->addWidget(logoutBtn);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_2);

        LabelTime = new QLabel(layoutWidget);
        LabelTime->setObjectName("LabelTime");
        LabelTime->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(LabelTime);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(MainMenuWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(20, 10, 461, 401));
        page1 = new QWidget();
        page1->setObjectName("page1");
        pushButton_3 = new QPushButton(page1);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(390, 340, 68, 21));
        btn_joinExam = new QPushButton(page1);
        btn_joinExam->setObjectName("btn_joinExam");
        btn_joinExam->setGeometry(QRect(140, 30, 68, 21));
        lineEdit_examCode = new QLineEdit(page1);
        lineEdit_examCode->setObjectName("lineEdit_examCode");
        lineEdit_examCode->setGeometry(QRect(20, 30, 113, 20));
        stackedWidget->addWidget(page1);
        page3 = new QWidget();
        page3->setObjectName("page3");
        pushButton_4 = new QPushButton(page3);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(90, 130, 68, 21));
        stackedWidget->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName("page4");
        pushButton_5 = new QPushButton(page4);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(10, 370, 68, 21));
        btn_history = new QPushButton(page4);
        btn_history->setObjectName("btn_history");
        btn_history->setGeometry(QRect(10, 340, 68, 21));
        tableWidget_scores = new QTableWidget(page4);
        tableWidget_scores->setObjectName("tableWidget_scores");
        tableWidget_scores->setGeometry(QRect(25, 21, 391, 311));
        stackedWidget->addWidget(page4);
        page2 = new QWidget();
        page2->setObjectName("page2");
        gridLayout = new QGridLayout(page2);
        gridLayout->setObjectName("gridLayout");
        label_3 = new QLabel(page2);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_oldPwd = new QLineEdit(page2);
        lineEdit_oldPwd->setObjectName("lineEdit_oldPwd");

        gridLayout->addWidget(lineEdit_oldPwd, 0, 1, 1, 1);

        label_4 = new QLabel(page2);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        lineEdit_newPwd = new QLineEdit(page2);
        lineEdit_newPwd->setObjectName("lineEdit_newPwd");

        gridLayout->addWidget(lineEdit_newPwd, 1, 1, 1, 1);

        label_5 = new QLabel(page2);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        lineEdit_Conform = new QLineEdit(page2);
        lineEdit_Conform->setObjectName("lineEdit_Conform");

        gridLayout->addWidget(lineEdit_Conform, 2, 1, 1, 1);

        btn_confirm = new QPushButton(page2);
        btn_confirm->setObjectName("btn_confirm");

        gridLayout->addWidget(btn_confirm, 3, 1, 1, 1);

        pushButton_6 = new QPushButton(page2);
        pushButton_6->setObjectName("pushButton_6");

        gridLayout->addWidget(pushButton_6, 4, 2, 1, 1);

        stackedWidget->addWidget(page2);

        retranslateUi(MainMenuWidget);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainMenuWidget);
    } // setupUi

    void retranslateUi(QWidget *MainMenuWidget)
    {
        MainMenuWidget->setWindowTitle(QCoreApplication::translate("MainMenuWidget", "Form", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainMenuWidget", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("MainMenuWidget", "PushButton", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainMenuWidget", "\350\200\203\350\257\225\345\244\247\345\216\205", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainMenuWidget", "\346\210\221\347\232\204\350\200\203\350\257\225", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainMenuWidget", "\346\210\220\347\273\251\346\237\245\350\257\242", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainMenuWidget", "\344\270\252\344\272\272\344\270\255\345\277\203", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QCoreApplication::translate("MainMenuWidget", "\347\224\250\346\210\267\345\220\215", nullptr));
        Username->setText(QCoreApplication::translate("MainMenuWidget", "Username", nullptr));
        logoutBtn->setText(QCoreApplication::translate("MainMenuWidget", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        label_2->setText(QCoreApplication::translate("MainMenuWidget", "\345\275\223\345\211\215\346\227\266\351\227\264:", nullptr));
        LabelTime->setText(QCoreApplication::translate("MainMenuWidget", "10:00", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainMenuWidget", "page1", nullptr));
        btn_joinExam->setText(QCoreApplication::translate("MainMenuWidget", "\350\277\233\345\205\245\350\200\203\350\257\225", nullptr));
        lineEdit_examCode->setPlaceholderText(QCoreApplication::translate("MainMenuWidget", "\350\257\267\350\276\223\345\205\245\350\200\203\350\257\225\347\240\201", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainMenuWidget", "page2", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainMenuWidget", "page3", nullptr));
        btn_history->setText(QCoreApplication::translate("MainMenuWidget", "\346\237\245\350\257\242\346\210\220\347\273\251", nullptr));
        label_3->setText(QCoreApplication::translate("MainMenuWidget", "\345\216\237\345\257\206\347\240\201\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainMenuWidget", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainMenuWidget", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        btn_confirm->setText(QCoreApplication::translate("MainMenuWidget", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainMenuWidget", "page4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenuWidget: public Ui_MainMenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENUWIDGET_H

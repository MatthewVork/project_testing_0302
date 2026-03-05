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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenuWidget
{
public:
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QListWidget *listWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *Username;
    QPushButton *logoutBtn;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *MainMenuWidget)
    {
        if (MainMenuWidget->objectName().isEmpty())
            MainMenuWidget->setObjectName("MainMenuWidget");
        MainMenuWidget->resize(800, 500);
        pushButton_2 = new QPushButton(MainMenuWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 160, 68, 21));
        pushButton = new QPushButton(MainMenuWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 140, 68, 21));
        listWidget = new QListWidget(MainMenuWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(20, 60, 61, 71));
        widget = new QWidget(MainMenuWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(503, 10, 291, 211));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        calendarWidget = new QCalendarWidget(widget);
        calendarWidget->setObjectName("calendarWidget");

        verticalLayout->addWidget(calendarWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label);

        Username = new QLabel(widget);
        Username->setObjectName("Username");

        horizontalLayout->addWidget(Username);

        logoutBtn = new QPushButton(widget);
        logoutBtn->setObjectName("logoutBtn");

        horizontalLayout->addWidget(logoutBtn);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MainMenuWidget);

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
        label_3->setText(QCoreApplication::translate("MainMenuWidget", "10:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenuWidget: public Ui_MainMenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENUWIDGET_H

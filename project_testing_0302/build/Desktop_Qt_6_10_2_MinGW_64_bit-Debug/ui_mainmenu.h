/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QPushButton *pushButtonCallbackLoginMenu;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName("MainMenu");
        MainMenu->resize(800, 500);
        pushButtonCallbackLoginMenu = new QPushButton(MainMenu);
        pushButtonCallbackLoginMenu->setObjectName("pushButtonCallbackLoginMenu");
        pushButtonCallbackLoginMenu->setGeometry(QRect(440, 410, 68, 21));
        pushButton_2 = new QPushButton(MainMenu);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(440, 370, 68, 21));

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "Form", nullptr));
        pushButtonCallbackLoginMenu->setText(QCoreApplication::translate("MainMenu", "\351\200\200\345\207\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainMenu", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H

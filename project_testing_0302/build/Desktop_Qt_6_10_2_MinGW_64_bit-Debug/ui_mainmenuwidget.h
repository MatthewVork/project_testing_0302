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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenuWidget
{
public:
    QPushButton *pushButtonCallbackLoginMenu;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MainMenuWidget)
    {
        if (MainMenuWidget->objectName().isEmpty())
            MainMenuWidget->setObjectName("MainMenuWidget");
        MainMenuWidget->resize(800, 500);
        pushButtonCallbackLoginMenu = new QPushButton(MainMenuWidget);
        pushButtonCallbackLoginMenu->setObjectName("pushButtonCallbackLoginMenu");
        pushButtonCallbackLoginMenu->setGeometry(QRect(440, 410, 68, 21));
        pushButton_2 = new QPushButton(MainMenuWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(440, 370, 68, 21));

        retranslateUi(MainMenuWidget);

        QMetaObject::connectSlotsByName(MainMenuWidget);
    } // setupUi

    void retranslateUi(QWidget *MainMenuWidget)
    {
        MainMenuWidget->setWindowTitle(QCoreApplication::translate("MainMenuWidget", "Form", nullptr));
        pushButtonCallbackLoginMenu->setText(QCoreApplication::translate("MainMenuWidget", "\351\200\200\345\207\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainMenuWidget", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenuWidget: public Ui_MainMenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENUWIDGET_H

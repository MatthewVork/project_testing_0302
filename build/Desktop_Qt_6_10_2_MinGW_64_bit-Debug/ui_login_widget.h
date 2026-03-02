/********************************************************************************
** Form generated from reading UI file 'login_widget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_WIDGET_H
#define UI_LOGIN_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login_Widget
{
public:

    void setupUi(QWidget *Login_Widget)
    {
        if (Login_Widget->objectName().isEmpty())
            Login_Widget->setObjectName("Login_Widget");
        Login_Widget->resize(400, 300);

        retranslateUi(Login_Widget);

        QMetaObject::connectSlotsByName(Login_Widget);
    } // setupUi

    void retranslateUi(QWidget *Login_Widget)
    {
        Login_Widget->setWindowTitle(QCoreApplication::translate("Login_Widget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login_Widget: public Ui_Login_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_WIDGET_H

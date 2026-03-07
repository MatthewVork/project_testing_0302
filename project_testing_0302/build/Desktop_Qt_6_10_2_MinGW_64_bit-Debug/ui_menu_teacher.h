/********************************************************************************
** Form generated from reading UI file 'menu_teacher.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_TEACHER_H
#define UI_MENU_TEACHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu_Teacher
{
public:

    void setupUi(QWidget *menu_Teacher)
    {
        if (menu_Teacher->objectName().isEmpty())
            menu_Teacher->setObjectName("menu_Teacher");
        menu_Teacher->resize(400, 300);

        retranslateUi(menu_Teacher);

        QMetaObject::connectSlotsByName(menu_Teacher);
    } // setupUi

    void retranslateUi(QWidget *menu_Teacher)
    {
        menu_Teacher->setWindowTitle(QCoreApplication::translate("menu_Teacher", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu_Teacher: public Ui_menu_Teacher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_TEACHER_H

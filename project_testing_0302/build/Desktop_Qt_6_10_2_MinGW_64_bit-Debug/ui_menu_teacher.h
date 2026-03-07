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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu_Teacher
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page0;
    QLabel *label_4;
    QWidget *page1;
    QLabel *label_5;
    QWidget *page2;
    QLabel *label_6;
    QWidget *page3;
    QLabel *label_7;
    QWidget *page4;
    QLabel *label_8;
    QWidget *page5;
    QLabel *label_3;
    QTreeWidget *treeWidget_nav;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *menu_Teacher)
    {
        if (menu_Teacher->objectName().isEmpty())
            menu_Teacher->setObjectName("menu_Teacher");
        menu_Teacher->resize(800, 500);
        stackedWidget = new QStackedWidget(menu_Teacher);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(160, 20, 621, 451));
        page0 = new QWidget();
        page0->setObjectName("page0");
        label_4 = new QLabel(page0);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 20, 49, 14));
        stackedWidget->addWidget(page0);
        page1 = new QWidget();
        page1->setObjectName("page1");
        label_5 = new QLabel(page1);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 10, 49, 14));
        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName("page2");
        label_6 = new QLabel(page2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 10, 49, 14));
        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName("page3");
        label_7 = new QLabel(page3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 20, 91, 16));
        stackedWidget->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName("page4");
        label_8 = new QLabel(page4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 20, 71, 16));
        stackedWidget->addWidget(page4);
        page5 = new QWidget();
        page5->setObjectName("page5");
        label_3 = new QLabel(page5);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 20, 49, 14));
        stackedWidget->addWidget(page5);
        treeWidget_nav = new QTreeWidget(menu_Teacher);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget_nav);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget_nav);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget_nav);
        new QTreeWidgetItem(__qtreewidgetitem2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidget_nav);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        treeWidget_nav->setObjectName("treeWidget_nav");
        treeWidget_nav->setGeometry(QRect(10, 10, 121, 421));
        label = new QLabel(menu_Teacher);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 450, 49, 14));
        label_2 = new QLabel(menu_Teacher);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 450, 49, 14));

        retranslateUi(menu_Teacher);

        QMetaObject::connectSlotsByName(menu_Teacher);
    } // setupUi

    void retranslateUi(QWidget *menu_Teacher)
    {
        menu_Teacher->setWindowTitle(QCoreApplication::translate("menu_Teacher", "Form", nullptr));
        label_4->setText(QCoreApplication::translate("menu_Teacher", "\345\210\233\345\273\272\347\217\255\347\272\247", nullptr));
        label_5->setText(QCoreApplication::translate("menu_Teacher", "\345\255\246\347\224\237\345\220\215\345\215\225", nullptr));
        label_6->setText(QCoreApplication::translate("menu_Teacher", "\345\275\225\345\205\245\351\242\230\347\233\256", nullptr));
        label_7->setText(QCoreApplication::translate("menu_Teacher", "\347\273\204\345\215\267\344\270\216\345\217\221\345\270\203", nullptr));
        label_8->setText(QCoreApplication::translate("menu_Teacher", "\347\217\255\347\272\247\346\210\220\347\273\251\346\200\273\346\246\234", nullptr));
        label_3->setText(QCoreApplication::translate("menu_Teacher", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_nav->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("menu_Teacher", "\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));

        const bool __sortingEnabled = treeWidget_nav->isSortingEnabled();
        treeWidget_nav->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget_nav->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("menu_Teacher", "\347\217\255\347\272\247\347\256\241\347\220\206", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("menu_Teacher", "\345\210\233\345\273\272\347\217\255\347\272\247", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("menu_Teacher", "\345\255\246\347\224\237\345\220\215\345\215\225", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget_nav->topLevelItem(1);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("menu_Teacher", "\350\200\203\350\257\225\344\270\216\351\242\230\345\272\223", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem4->child(0);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("menu_Teacher", "\345\275\225\345\205\245\351\242\230\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem4->child(1);
        ___qtreewidgetitem6->setText(0, QCoreApplication::translate("menu_Teacher", "\347\273\204\345\215\267\344\270\216\345\217\221\345\270\203", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = treeWidget_nav->topLevelItem(2);
        ___qtreewidgetitem7->setText(0, QCoreApplication::translate("menu_Teacher", "\346\225\260\346\215\256\344\270\255\345\277\203", nullptr));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem7->child(0);
        ___qtreewidgetitem8->setText(0, QCoreApplication::translate("menu_Teacher", "\347\217\255\347\272\247\346\210\220\347\273\251\346\200\273\346\246\234", nullptr));
        QTreeWidgetItem *___qtreewidgetitem9 = treeWidget_nav->topLevelItem(3);
        ___qtreewidgetitem9->setText(0, QCoreApplication::translate("menu_Teacher", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem9->child(0);
        ___qtreewidgetitem10->setText(0, QCoreApplication::translate("menu_Teacher", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem9->child(1);
        ___qtreewidgetitem11->setText(0, QCoreApplication::translate("menu_Teacher", "\345\256\211\345\205\250\351\200\200\345\207\272", nullptr));
        treeWidget_nav->setSortingEnabled(__sortingEnabled);

        label->setText(QCoreApplication::translate("menu_Teacher", "\345\275\223\345\211\215\346\227\266\351\227\264", nullptr));
        label_2->setText(QCoreApplication::translate("menu_Teacher", "10:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu_Teacher: public Ui_menu_Teacher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_TEACHER_H

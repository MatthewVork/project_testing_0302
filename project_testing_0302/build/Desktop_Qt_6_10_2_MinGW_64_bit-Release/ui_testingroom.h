/********************************************************************************
** Form generated from reading UI file 'testingroom.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTINGROOM_H
#define UI_TESTINGROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestingRoom
{
public:
    QTextBrowser *textBrowser_question;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *widget;
    QGridLayout *gridLayout;
    QRadioButton *radio_A;
    QRadioButton *radio_B;
    QRadioButton *radio_C;
    QRadioButton *radio_D;
    QLabel *label_timer;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_prev;
    QPushButton *btn_next;
    QPushButton *btn_submit;
    QLabel *label_2;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *TestingRoom)
    {
        if (TestingRoom->objectName().isEmpty())
            TestingRoom->setObjectName("TestingRoom");
        TestingRoom->resize(800, 500);
        TestingRoom->setStyleSheet(QString::fromUtf8("/* ================= 1. \345\205\250\345\261\200\350\203\214\346\231\257\344\270\216\345\255\227\344\275\223 ================= */\n"
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
        textBrowser_question = new QTextBrowser(TestingRoom);
        textBrowser_question->setObjectName("textBrowser_question");
        textBrowser_question->setGeometry(QRect(180, 20, 501, 391));
        label = new QLabel(TestingRoom);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 40, 49, 14));
        scrollArea = new QScrollArea(TestingRoom);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 70, 160, 381));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 158, 379));
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 161, 381));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        scrollArea->setWidget(scrollAreaWidgetContents);
        radio_A = new QRadioButton(TestingRoom);
        buttonGroup = new QButtonGroup(TestingRoom);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(radio_A);
        radio_A->setObjectName("radio_A");
        radio_A->setGeometry(QRect(220, 210, 431, 18));
        radio_B = new QRadioButton(TestingRoom);
        buttonGroup->addButton(radio_B);
        radio_B->setObjectName("radio_B");
        radio_B->setGeometry(QRect(220, 250, 431, 18));
        radio_C = new QRadioButton(TestingRoom);
        buttonGroup->addButton(radio_C);
        radio_C->setObjectName("radio_C");
        radio_C->setGeometry(QRect(220, 290, 431, 18));
        radio_D = new QRadioButton(TestingRoom);
        buttonGroup->addButton(radio_D);
        radio_D->setObjectName("radio_D");
        radio_D->setGeometry(QRect(220, 330, 431, 18));
        label_timer = new QLabel(TestingRoom);
        label_timer->setObjectName("label_timer");
        label_timer->setGeometry(QRect(710, 430, 49, 14));
        layoutWidget = new QWidget(TestingRoom);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(180, 412, 501, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_prev = new QPushButton(layoutWidget);
        btn_prev->setObjectName("btn_prev");

        horizontalLayout->addWidget(btn_prev);

        btn_next = new QPushButton(layoutWidget);
        btn_next->setObjectName("btn_next");

        horizontalLayout->addWidget(btn_next);

        btn_submit = new QPushButton(layoutWidget);
        btn_submit->setObjectName("btn_submit");

        horizontalLayout->addWidget(btn_submit);

        label_2 = new QLabel(TestingRoom);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(710, 390, 53, 15));

        retranslateUi(TestingRoom);

        QMetaObject::connectSlotsByName(TestingRoom);
    } // setupUi

    void retranslateUi(QWidget *TestingRoom)
    {
        TestingRoom->setWindowTitle(QCoreApplication::translate("TestingRoom", "Form", nullptr));
        label->setText(QCoreApplication::translate("TestingRoom", "\347\255\224\351\242\230\345\215\241", nullptr));
        radio_A->setText(QCoreApplication::translate("TestingRoom", "RadioButton", nullptr));
        radio_B->setText(QCoreApplication::translate("TestingRoom", "RadioButton", nullptr));
        radio_C->setText(QCoreApplication::translate("TestingRoom", "RadioButton", nullptr));
        radio_D->setText(QCoreApplication::translate("TestingRoom", "RadioButton", nullptr));
        label_timer->setText(QCoreApplication::translate("TestingRoom", "10:00", nullptr));
        btn_prev->setText(QCoreApplication::translate("TestingRoom", "\344\270\212\344\270\200\351\242\230", nullptr));
        btn_next->setText(QCoreApplication::translate("TestingRoom", "\344\270\213\344\270\200\351\242\230", nullptr));
        btn_submit->setText(QCoreApplication::translate("TestingRoom", "\344\272\244\345\215\267", nullptr));
        label_2->setText(QCoreApplication::translate("TestingRoom", "\345\211\251\344\275\231\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestingRoom: public Ui_TestingRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTINGROOM_H

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
#include <QtWidgets/QFrame>
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
    QFrame *frame_2;
    QPushButton *pushButton_26;
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
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_prev;
    QPushButton *btn_next;
    QPushButton *btn_submit;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *TestingRoom)
    {
        if (TestingRoom->objectName().isEmpty())
            TestingRoom->setObjectName("TestingRoom");
        TestingRoom->resize(800, 500);
        TestingRoom->setStyleSheet(QString::fromUtf8(""));
        frame_2 = new QFrame(TestingRoom);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(690, 20, 101, 191));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_26 = new QPushButton(frame_2);
        pushButton_26->setObjectName("pushButton_26");
        pushButton_26->setGeometry(QRect(40, 130, 101, 51));
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
        radio_A->setGeometry(QRect(280, 200, 85, 18));
        radio_B = new QRadioButton(TestingRoom);
        buttonGroup->addButton(radio_B);
        radio_B->setObjectName("radio_B");
        radio_B->setGeometry(QRect(280, 240, 85, 18));
        radio_C = new QRadioButton(TestingRoom);
        buttonGroup->addButton(radio_C);
        radio_C->setObjectName("radio_C");
        radio_C->setGeometry(QRect(280, 290, 85, 18));
        radio_D = new QRadioButton(TestingRoom);
        buttonGroup->addButton(radio_D);
        radio_D->setObjectName("radio_D");
        radio_D->setGeometry(QRect(280, 330, 85, 18));
        label_timer = new QLabel(TestingRoom);
        label_timer->setObjectName("label_timer");
        label_timer->setGeometry(QRect(710, 240, 49, 14));
        widget1 = new QWidget(TestingRoom);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(180, 412, 501, 41));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_prev = new QPushButton(widget1);
        btn_prev->setObjectName("btn_prev");

        horizontalLayout->addWidget(btn_prev);

        btn_next = new QPushButton(widget1);
        btn_next->setObjectName("btn_next");

        horizontalLayout->addWidget(btn_next);

        btn_submit = new QPushButton(widget1);
        btn_submit->setObjectName("btn_submit");

        horizontalLayout->addWidget(btn_submit);


        retranslateUi(TestingRoom);

        QMetaObject::connectSlotsByName(TestingRoom);
    } // setupUi

    void retranslateUi(QWidget *TestingRoom)
    {
        TestingRoom->setWindowTitle(QCoreApplication::translate("TestingRoom", "Form", nullptr));
        pushButton_26->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("TestingRoom", "\347\255\224\351\242\230\345\215\241", nullptr));
        radio_A->setText(QCoreApplication::translate("TestingRoom", "RadioButton", nullptr));
        radio_B->setText(QCoreApplication::translate("TestingRoom", "RadioButton", nullptr));
        radio_C->setText(QCoreApplication::translate("TestingRoom", "RadioButton", nullptr));
        radio_D->setText(QCoreApplication::translate("TestingRoom", "RadioButton", nullptr));
        label_timer->setText(QCoreApplication::translate("TestingRoom", "TextLabel", nullptr));
        btn_prev->setText(QCoreApplication::translate("TestingRoom", "\344\270\212\344\270\200\351\242\230", nullptr));
        btn_next->setText(QCoreApplication::translate("TestingRoom", "\344\270\213\344\270\200\351\242\230", nullptr));
        btn_submit->setText(QCoreApplication::translate("TestingRoom", "\344\272\244\345\215\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestingRoom: public Ui_TestingRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTINGROOM_H

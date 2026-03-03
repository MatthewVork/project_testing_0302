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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestingRoom
{
public:
    QFrame *frame;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QFrame *line;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QPushButton *pushButton_25;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFrame *frame_2;
    QPushButton *pushButton_26;

    void setupUi(QWidget *TestingRoom)
    {
        if (TestingRoom->objectName().isEmpty())
            TestingRoom->setObjectName("TestingRoom");
        TestingRoom->resize(800, 500);
        TestingRoom->setStyleSheet(QString::fromUtf8("/* --- 1. \345\205\250\345\261\200\345\237\272\347\241\200\350\256\276\345\256\232 --- */\n"
"QWidget {\n"
"    font-family: \"SF Pro Display\", \"Helvetica Neue\", \"Segoe UI\", \"Microsoft YaHei\";\n"
"    color: #1d1d1f; /* \350\213\271\346\236\234\346\240\207\345\207\206\346\267\261\347\201\260\350\211\262\346\226\207\346\234\254 */\n"
"    outline: none;  /* \345\216\273\346\216\211\347\202\271\345\207\273\346\227\266\347\232\204\350\231\232\347\272\277\346\241\206 */\n"
"}\n"
"\n"
"/* --- 2. \351\200\232\347\224\250\345\256\271\345\231\250 (\345\246\202\344\275\240\347\232\204 loginCard) --- */\n"
"/* \345\217\252\350\246\201\346\230\257 QFrame \351\203\275\344\274\232\350\207\252\345\212\250\345\217\230\346\210\220\350\277\231\347\247\215\345\215\212\351\200\217\346\230\216\347\243\250\347\240\202\350\264\250\346\204\237 */\n"
"QFrame {\n"
"    background-color: rgba(255, 255, 255, 0.7); \n"
"    border: 1px solid rgba(255, 255, 255, 0.3);\n"
"    border-radius: 18px;\n"
"}\n"
"\n"
"/* --- 3. \351\200\232"
                        "\347\224\250\350\276\223\345\205\245\346\241\206 (QLineEdit, QTextEdit) --- */\n"
"QLineEdit, QTextEdit {\n"
"    background-color: rgba(255, 255, 255, 0.5);\n"
"    border: 1px solid rgba(0, 0, 0, 0.1);\n"
"    border-radius: 10px;\n"
"    padding: 8px 12px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* \350\276\223\345\205\245\346\241\206\350\201\232\347\204\246\346\225\210\346\236\234\357\274\232\346\240\207\345\277\227\346\200\247\347\232\204\350\223\235\350\211\262\345\205\211\346\231\225 */\n"
"QLineEdit:focus, QTextEdit:focus {\n"
"    border: 2px solid #007AFF;\n"
"    background-color: rgba(255, 255, 255, 0.9);\n"
"}\n"
"\n"
"/* --- 4. \351\200\232\347\224\250\346\214\211\351\222\256 (QPushButton) --- */\n"
"QPushButton {\n"
"    background-color: #007AFF; /* \350\213\271\346\236\234\350\223\235 */\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    padding: 10px 20px;\n"
"    font-weight: 600;\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234\357\274\232\351"
                        "\242\234\350\211\262\347\225\245\345\276\256\345\212\240\346\267\261 */\n"
"QPushButton:hover {\n"
"    background-color: #0063CC;\n"
"}\n"
"\n"
"/* \346\214\211\344\270\213\357\274\232\346\230\216\346\230\276\347\232\204\345\217\215\351\246\210\346\204\237 */\n"
"QPushButton:pressed {\n"
"    background-color: #0051A8;\n"
"}\n"
"\n"
"/* \347\246\201\347\224\250\347\212\266\346\200\201\357\274\232\345\217\230\347\201\260 */\n"
"QPushButton:disabled {\n"
"    background-color: #d2d2d7;\n"
"    color: #86868b;\n"
"}\n"
"\n"
"/* --- 5. \346\240\207\347\255\276\344\270\216\346\226\207\346\234\254 (QLabel) --- */\n"
"QLabel {\n"
"    background-color: transparent;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* --- 6. \346\273\232\345\212\250\346\235\241\347\276\216\345\214\226 (QScrollBar) --- */\n"
"/* \350\256\251\346\273\232\345\212\250\346\235\241\345\203\217 iOS \344\270\200\346\240\267\347\256\200\346\264\201 */\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: rgba(0, 0, 0, 0.05);\n"
"    width"
                        ": 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: rgba(0, 0, 0, 0.2);\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: rgba(0, 0, 0, 0.3);\n"
"}"));
        frame = new QFrame(TestingRoom);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(19, 20, 161, 461));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName("gridLayout");
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 1, 2, 1, 1);

        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout->addWidget(pushButton_4, 1, 3, 1, 1);

        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout->addWidget(pushButton_5, 1, 4, 1, 1);

        pushButton_6 = new QPushButton(frame);
        pushButton_6->setObjectName("pushButton_6");

        gridLayout->addWidget(pushButton_6, 2, 0, 1, 1);

        pushButton_7 = new QPushButton(frame);
        pushButton_7->setObjectName("pushButton_7");

        gridLayout->addWidget(pushButton_7, 2, 1, 1, 1);

        pushButton_8 = new QPushButton(frame);
        pushButton_8->setObjectName("pushButton_8");

        gridLayout->addWidget(pushButton_8, 2, 2, 1, 1);

        pushButton_9 = new QPushButton(frame);
        pushButton_9->setObjectName("pushButton_9");

        gridLayout->addWidget(pushButton_9, 2, 3, 1, 1);

        pushButton_10 = new QPushButton(frame);
        pushButton_10->setObjectName("pushButton_10");

        gridLayout->addWidget(pushButton_10, 2, 4, 1, 1);

        pushButton_11 = new QPushButton(frame);
        pushButton_11->setObjectName("pushButton_11");

        gridLayout->addWidget(pushButton_11, 3, 0, 1, 1);

        pushButton_12 = new QPushButton(frame);
        pushButton_12->setObjectName("pushButton_12");

        gridLayout->addWidget(pushButton_12, 3, 1, 1, 1);

        pushButton_13 = new QPushButton(frame);
        pushButton_13->setObjectName("pushButton_13");

        gridLayout->addWidget(pushButton_13, 3, 2, 1, 1);

        pushButton_14 = new QPushButton(frame);
        pushButton_14->setObjectName("pushButton_14");

        gridLayout->addWidget(pushButton_14, 3, 3, 1, 1);

        pushButton_15 = new QPushButton(frame);
        pushButton_15->setObjectName("pushButton_15");

        gridLayout->addWidget(pushButton_15, 3, 4, 1, 1);

        line = new QFrame(frame);
        line->setObjectName("line");
        QFont font;
        font.setFamilies({QString::fromUtf8("SF Pro Display")});
        font.setBold(false);
        line->setFont(font);
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line, 4, 0, 1, 5);

        pushButton_16 = new QPushButton(frame);
        pushButton_16->setObjectName("pushButton_16");

        gridLayout->addWidget(pushButton_16, 5, 0, 1, 1);

        pushButton_17 = new QPushButton(frame);
        pushButton_17->setObjectName("pushButton_17");

        gridLayout->addWidget(pushButton_17, 5, 1, 1, 1);

        pushButton_18 = new QPushButton(frame);
        pushButton_18->setObjectName("pushButton_18");

        gridLayout->addWidget(pushButton_18, 5, 2, 1, 1);

        pushButton_19 = new QPushButton(frame);
        pushButton_19->setObjectName("pushButton_19");

        gridLayout->addWidget(pushButton_19, 5, 3, 1, 1);

        pushButton_20 = new QPushButton(frame);
        pushButton_20->setObjectName("pushButton_20");

        gridLayout->addWidget(pushButton_20, 5, 4, 1, 1);

        pushButton_21 = new QPushButton(frame);
        pushButton_21->setObjectName("pushButton_21");

        gridLayout->addWidget(pushButton_21, 6, 0, 1, 1);

        pushButton_22 = new QPushButton(frame);
        pushButton_22->setObjectName("pushButton_22");

        gridLayout->addWidget(pushButton_22, 6, 1, 1, 1);

        pushButton_23 = new QPushButton(frame);
        pushButton_23->setObjectName("pushButton_23");

        gridLayout->addWidget(pushButton_23, 6, 2, 1, 1);

        pushButton_24 = new QPushButton(frame);
        pushButton_24->setObjectName("pushButton_24");

        gridLayout->addWidget(pushButton_24, 6, 3, 1, 1);

        pushButton_25 = new QPushButton(frame);
        pushButton_25->setObjectName("pushButton_25");

        gridLayout->addWidget(pushButton_25, 6, 4, 1, 1);

        label = new QLabel(frame);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 80));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 5);

        scrollArea = new QScrollArea(TestingRoom);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(190, 20, 411, 461));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 409, 459));
        scrollArea->setWidget(scrollAreaWidgetContents);
        frame_2 = new QFrame(TestingRoom);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(610, 20, 181, 191));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_26 = new QPushButton(frame_2);
        pushButton_26->setObjectName("pushButton_26");
        pushButton_26->setGeometry(QRect(40, 130, 101, 51));

        retranslateUi(TestingRoom);

        QMetaObject::connectSlotsByName(TestingRoom);
    } // setupUi

    void retranslateUi(QWidget *TestingRoom)
    {
        TestingRoom->setWindowTitle(QCoreApplication::translate("TestingRoom", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_9->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_10->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_11->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_12->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_13->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_14->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_15->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_16->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_17->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_18->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_19->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_20->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_21->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_22->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_23->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_24->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        pushButton_25->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("TestingRoom", "\347\255\224\351\242\230\345\215\241", nullptr));
        pushButton_26->setText(QCoreApplication::translate("TestingRoom", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestingRoom: public Ui_TestingRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTINGROOM_H

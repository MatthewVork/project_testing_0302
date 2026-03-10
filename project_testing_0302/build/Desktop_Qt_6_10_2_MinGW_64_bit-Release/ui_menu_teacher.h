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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu_Teacher
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page0;
    QLabel *label_4;
    QPushButton *btn_createClass;
    QLineEdit *lineEdit_className;
    QTableWidget *tableWidget_classes;
    QWidget *page1;
    QLabel *label_5;
    QComboBox *comboBox_myClasses;
    QPushButton *btn_searchStudents;
    QTableWidget *tableWidget_students;
    QWidget *page2;
    QLabel *label_6;
    QLabel *label_9;
    QLineEdit *lineEdit_examCode;
    QTextEdit *textEdit_question;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *lineEdit_optA;
    QLineEdit *lineEdit_optB;
    QLineEdit *lineEdit_optC;
    QLineEdit *lineEdit_optD;
    QComboBox *comboBox_answer;
    QLabel *label_15;
    QPushButton *btn_addQuestion;
    QPushButton *btn_finishExam;
    QWidget *page3;
    QLabel *label_7;
    QLabel *label_16;
    QComboBox *comboBox_examClass;
    QLabel *label_17;
    QLineEdit *lineEdit_subject;
    QLabel *label_18;
    QSpinBox *spinBox_duration;
    QPushButton *btn_generateExam;
    QLabel *label_examCodeDisplay;
    QWidget *page4;
    QLabel *label_8;
    QComboBox *comboBox_scoreClass;
    QLabel *label_19;
    QLabel *label_20;
    QComboBox *comboBox_scoreExam;
    QPushButton *btn_searchScores;
    QTableWidget *tableWidget_scores;
    QTreeWidget *treeWidget_nav;
    QLabel *label;
    QLabel *label_time;

    void setupUi(QWidget *menu_Teacher)
    {
        if (menu_Teacher->objectName().isEmpty())
            menu_Teacher->setObjectName("menu_Teacher");
        menu_Teacher->resize(800, 500);
        stackedWidget = new QStackedWidget(menu_Teacher);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(140, 10, 641, 471));
        stackedWidget->setStyleSheet(QString::fromUtf8("/* ================= 1. \345\205\250\345\261\200\350\203\214\346\231\257\344\270\216\345\255\227\344\275\223 ================= */\n"
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
        page0 = new QWidget();
        page0->setObjectName("page0");
        label_4 = new QLabel(page0);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 20, 49, 14));
        btn_createClass = new QPushButton(page0);
        btn_createClass->setObjectName("btn_createClass");
        btn_createClass->setGeometry(QRect(150, 60, 81, 31));
        lineEdit_className = new QLineEdit(page0);
        lineEdit_className->setObjectName("lineEdit_className");
        lineEdit_className->setGeometry(QRect(30, 60, 113, 31));
        tableWidget_classes = new QTableWidget(page0);
        tableWidget_classes->setObjectName("tableWidget_classes");
        tableWidget_classes->setGeometry(QRect(30, 100, 551, 301));
        stackedWidget->addWidget(page0);
        page1 = new QWidget();
        page1->setObjectName("page1");
        label_5 = new QLabel(page1);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 10, 49, 14));
        comboBox_myClasses = new QComboBox(page1);
        comboBox_myClasses->setObjectName("comboBox_myClasses");
        comboBox_myClasses->setGeometry(QRect(20, 30, 111, 22));
        btn_searchStudents = new QPushButton(page1);
        btn_searchStudents->setObjectName("btn_searchStudents");
        btn_searchStudents->setGeometry(QRect(20, 60, 111, 31));
        tableWidget_students = new QTableWidget(page1);
        tableWidget_students->setObjectName("tableWidget_students");
        tableWidget_students->setGeometry(QRect(150, 20, 441, 401));
        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName("page2");
        label_6 = new QLabel(page2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 20, 49, 14));
        label_9 = new QLabel(page2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 50, 71, 16));
        lineEdit_examCode = new QLineEdit(page2);
        lineEdit_examCode->setObjectName("lineEdit_examCode");
        lineEdit_examCode->setGeometry(QRect(110, 50, 121, 31));
        textEdit_question = new QTextEdit(page2);
        textEdit_question->setObjectName("textEdit_question");
        textEdit_question->setGeometry(QRect(80, 100, 281, 68));
        label_10 = new QLabel(page2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 100, 49, 14));
        label_11 = new QLabel(page2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 180, 49, 14));
        label_12 = new QLabel(page2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 210, 49, 14));
        label_13 = new QLabel(page2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(20, 240, 49, 14));
        label_14 = new QLabel(page2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 270, 49, 14));
        lineEdit_optA = new QLineEdit(page2);
        lineEdit_optA->setObjectName("lineEdit_optA");
        lineEdit_optA->setGeometry(QRect(80, 180, 281, 20));
        lineEdit_optB = new QLineEdit(page2);
        lineEdit_optB->setObjectName("lineEdit_optB");
        lineEdit_optB->setGeometry(QRect(80, 210, 281, 20));
        lineEdit_optC = new QLineEdit(page2);
        lineEdit_optC->setObjectName("lineEdit_optC");
        lineEdit_optC->setGeometry(QRect(80, 240, 281, 20));
        lineEdit_optD = new QLineEdit(page2);
        lineEdit_optD->setObjectName("lineEdit_optD");
        lineEdit_optD->setGeometry(QRect(80, 270, 281, 20));
        comboBox_answer = new QComboBox(page2);
        comboBox_answer->addItem(QString());
        comboBox_answer->addItem(QString());
        comboBox_answer->addItem(QString());
        comboBox_answer->addItem(QString());
        comboBox_answer->setObjectName("comboBox_answer");
        comboBox_answer->setGeometry(QRect(86, 310, 91, 31));
        label_15 = new QLabel(page2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(20, 320, 49, 14));
        btn_addQuestion = new QPushButton(page2);
        btn_addQuestion->setObjectName("btn_addQuestion");
        btn_addQuestion->setGeometry(QRect(190, 310, 171, 31));
        btn_finishExam = new QPushButton(page2);
        btn_finishExam->setObjectName("btn_finishExam");
        btn_finishExam->setGeometry(QRect(240, 50, 121, 31));
        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName("page3");
        label_7 = new QLabel(page3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 20, 91, 16));
        label_16 = new QLabel(page3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(40, 50, 49, 14));
        comboBox_examClass = new QComboBox(page3);
        comboBox_examClass->setObjectName("comboBox_examClass");
        comboBox_examClass->setGeometry(QRect(100, 50, 151, 22));
        label_17 = new QLabel(page3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(40, 80, 49, 14));
        lineEdit_subject = new QLineEdit(page3);
        lineEdit_subject->setObjectName("lineEdit_subject");
        lineEdit_subject->setGeometry(QRect(100, 80, 151, 20));
        label_18 = new QLabel(page3);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(40, 110, 49, 14));
        spinBox_duration = new QSpinBox(page3);
        spinBox_duration->setObjectName("spinBox_duration");
        spinBox_duration->setGeometry(QRect(100, 110, 151, 22));
        btn_generateExam = new QPushButton(page3);
        btn_generateExam->setObjectName("btn_generateExam");
        btn_generateExam->setGeometry(QRect(110, 150, 121, 31));
        label_examCodeDisplay = new QLabel(page3);
        label_examCodeDisplay->setObjectName("label_examCodeDisplay");
        label_examCodeDisplay->setGeometry(QRect(100, 180, 151, 41));
        stackedWidget->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName("page4");
        label_8 = new QLabel(page4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 20, 71, 16));
        comboBox_scoreClass = new QComboBox(page4);
        comboBox_scoreClass->setObjectName("comboBox_scoreClass");
        comboBox_scoreClass->setGeometry(QRect(66, 50, 141, 22));
        label_19 = new QLabel(page4);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 50, 49, 14));
        label_20 = new QLabel(page4);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(10, 80, 49, 14));
        comboBox_scoreExam = new QComboBox(page4);
        comboBox_scoreExam->setObjectName("comboBox_scoreExam");
        comboBox_scoreExam->setGeometry(QRect(66, 80, 141, 22));
        btn_searchScores = new QPushButton(page4);
        btn_searchScores->setObjectName("btn_searchScores");
        btn_searchScores->setGeometry(QRect(20, 120, 181, 31));
        tableWidget_scores = new QTableWidget(page4);
        tableWidget_scores->setObjectName("tableWidget_scores");
        tableWidget_scores->setGeometry(QRect(220, 40, 401, 371));
        stackedWidget->addWidget(page4);
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
        treeWidget_nav->setObjectName("treeWidget_nav");
        treeWidget_nav->setGeometry(QRect(10, 10, 131, 421));
        label = new QLabel(menu_Teacher);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 450, 49, 14));
        label_time = new QLabel(menu_Teacher);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(80, 450, 49, 14));

        retranslateUi(menu_Teacher);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(menu_Teacher);
    } // setupUi

    void retranslateUi(QWidget *menu_Teacher)
    {
        menu_Teacher->setWindowTitle(QCoreApplication::translate("menu_Teacher", "Form", nullptr));
        label_4->setText(QCoreApplication::translate("menu_Teacher", "\345\210\233\345\273\272\347\217\255\347\272\247", nullptr));
        btn_createClass->setText(QCoreApplication::translate("menu_Teacher", "\345\210\233\345\273\272\347\217\255\347\272\247", nullptr));
        label_5->setText(QCoreApplication::translate("menu_Teacher", "\345\255\246\347\224\237\345\220\215\345\215\225", nullptr));
        btn_searchStudents->setText(QCoreApplication::translate("menu_Teacher", "\346\237\245\346\211\276", nullptr));
        label_6->setText(QCoreApplication::translate("menu_Teacher", "\345\275\225\345\205\245\351\242\230\347\233\256", nullptr));
        label_9->setText(QCoreApplication::translate("menu_Teacher", "\350\257\267\350\276\223\345\205\245\350\200\203\350\257\225\347\240\201", nullptr));
        label_10->setText(QCoreApplication::translate("menu_Teacher", "\350\200\203\350\257\225\351\242\230\347\233\256", nullptr));
        label_11->setText(QCoreApplication::translate("menu_Teacher", "\351\200\211\351\241\271 A:", nullptr));
        label_12->setText(QCoreApplication::translate("menu_Teacher", "\351\200\211\351\241\271 B:", nullptr));
        label_13->setText(QCoreApplication::translate("menu_Teacher", "\351\200\211\351\241\271 C:", nullptr));
        label_14->setText(QCoreApplication::translate("menu_Teacher", "\351\200\211\351\241\271 D:", nullptr));
        comboBox_answer->setItemText(0, QCoreApplication::translate("menu_Teacher", "A", nullptr));
        comboBox_answer->setItemText(1, QCoreApplication::translate("menu_Teacher", "B", nullptr));
        comboBox_answer->setItemText(2, QCoreApplication::translate("menu_Teacher", "C", nullptr));
        comboBox_answer->setItemText(3, QCoreApplication::translate("menu_Teacher", "D", nullptr));

        label_15->setText(QCoreApplication::translate("menu_Teacher", "\346\255\243\347\241\256\347\255\224\346\241\210:", nullptr));
        btn_addQuestion->setText(QCoreApplication::translate("menu_Teacher", "\344\277\235\345\255\230\351\242\230\347\233\256\345\271\266\347\273\247\347\273\255\345\275\225\345\205\245", nullptr));
        btn_finishExam->setText(QCoreApplication::translate("menu_Teacher", "\345\256\214\346\210\220\345\275\225\345\205\245\345\271\266\345\260\201\345\215\267", nullptr));
        label_7->setText(QCoreApplication::translate("menu_Teacher", "\347\273\204\345\215\267\344\270\216\345\217\221\345\270\203", nullptr));
        label_16->setText(QCoreApplication::translate("menu_Teacher", "\345\217\221\345\270\203\350\214\203\345\233\264", nullptr));
        label_17->setText(QCoreApplication::translate("menu_Teacher", "\350\200\203\350\257\225\347\247\221\347\233\256", nullptr));
        label_18->setText(QCoreApplication::translate("menu_Teacher", "\350\200\203\350\257\225\346\227\266\351\227\264", nullptr));
        btn_generateExam->setText(QCoreApplication::translate("menu_Teacher", "\347\224\237\346\210\220\344\270\223\345\261\236\350\200\203\350\257\225\347\240\201", nullptr));
        label_examCodeDisplay->setText(QCoreApplication::translate("menu_Teacher", "\347\255\211\345\276\205\347\224\237\346\210\220...", nullptr));
        label_8->setText(QCoreApplication::translate("menu_Teacher", "\347\217\255\347\272\247\346\210\220\347\273\251\346\200\273\346\246\234", nullptr));
        label_19->setText(QCoreApplication::translate("menu_Teacher", "\351\200\211\346\213\251\347\217\255\347\272\247", nullptr));
        label_20->setText(QCoreApplication::translate("menu_Teacher", "\351\200\211\346\213\251\350\200\203\350\257\225", nullptr));
        btn_searchScores->setText(QCoreApplication::translate("menu_Teacher", "\346\237\245\350\257\242\350\257\245\345\234\272\350\200\203\350\257\225\346\210\220\347\273\251", nullptr));
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
        ___qtreewidgetitem10->setText(0, QCoreApplication::translate("menu_Teacher", "\345\256\211\345\205\250\351\200\200\345\207\272", nullptr));
        treeWidget_nav->setSortingEnabled(__sortingEnabled);

        label->setText(QCoreApplication::translate("menu_Teacher", "\345\275\223\345\211\215\346\227\266\351\227\264", nullptr));
        label_time->setText(QCoreApplication::translate("menu_Teacher", "10:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu_Teacher: public Ui_menu_Teacher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_TEACHER_H

/********************************************************************************
** Form generated from reading UI file 'registerwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWIDGET_H
#define UI_REGISTERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registerwidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *registerwidget)
    {
        if (registerwidget->objectName().isEmpty())
            registerwidget->setObjectName("registerwidget");
        registerwidget->resize(800, 500);
        gridLayout = new QGridLayout(registerwidget);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 75, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(256, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        frame = new QFrame(registerwidget);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(240, 320));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName("formLayout");
        label = new QLabel(frame);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::SpanningRole, label);

        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_2);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, lineEdit);

        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_3);

        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, lineEdit_2);

        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, label_4);

        lineEdit_3 = new QLineEdit(frame);
        lineEdit_3->setObjectName("lineEdit_3");

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, lineEdit_3);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");

        formLayout->setWidget(8, QFormLayout::ItemRole::SpanningRole, pushButton);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");

        formLayout->setWidget(9, QFormLayout::ItemRole::FieldRole, pushButton_2);


        gridLayout->addWidget(frame, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(256, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 75, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        retranslateUi(registerwidget);

        QMetaObject::connectSlotsByName(registerwidget);
    } // setupUi

    void retranslateUi(QWidget *registerwidget)
    {
        registerwidget->setWindowTitle(QCoreApplication::translate("registerwidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("registerwidget", "\346\263\250\345\206\214\347\225\214\351\235\242", nullptr));
        label_2->setText(QCoreApplication::translate("registerwidget", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("registerwidget", "\346\263\250\345\206\214\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("registerwidget", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("registerwidget", "\346\263\250\345\206\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("registerwidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registerwidget: public Ui_registerwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWIDGET_H

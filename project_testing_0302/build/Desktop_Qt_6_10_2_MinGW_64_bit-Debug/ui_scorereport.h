/********************************************************************************
** Form generated from reading UI file 'scorereport.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREREPORT_H
#define UI_SCOREREPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScoreReport
{
public:

    void setupUi(QWidget *ScoreReport)
    {
        if (ScoreReport->objectName().isEmpty())
            ScoreReport->setObjectName("ScoreReport");
        ScoreReport->resize(400, 300);

        retranslateUi(ScoreReport);

        QMetaObject::connectSlotsByName(ScoreReport);
    } // setupUi

    void retranslateUi(QWidget *ScoreReport)
    {
        ScoreReport->setWindowTitle(QCoreApplication::translate("ScoreReport", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScoreReport: public Ui_ScoreReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREREPORT_H

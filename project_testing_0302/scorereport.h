#ifndef SCOREREPORT_H
#define SCOREREPORT_H

#include <QWidget>

namespace Ui {
class ScoreReport;
}

class ScoreReport : public QWidget
{
    Q_OBJECT

public:
    explicit ScoreReport(QWidget *parent = nullptr);
    ~ScoreReport();

private:
    Ui::ScoreReport *ui;
};

#endif // SCOREREPORT_H

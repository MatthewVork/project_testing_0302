#include "scorereport.h"
#include "ui_scorereport.h"

ScoreReport::ScoreReport(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ScoreReport)
{
    ui->setupUi(this);
}

ScoreReport::~ScoreReport()
{
    delete ui;
}

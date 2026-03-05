#include "mainmenuwidget.h"
#include "ui_mainmenuwidget.h"

MainMenuWidget::MainMenuWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainMenuWidget)
{
    ui->setupUi(this);
}

MainMenuWidget::~MainMenuWidget()
{
    delete ui;
}

void MainMenuWidget::updateUserName(QString name)
{
    ui->Username->setText(name);
}


void MainMenuWidget::on_logoutBtn_clicked()
{
    emit signal_LogoutData();
    emit signal_callbackLoginMenu();
}


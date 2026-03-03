#include "mainmenuwidget.h"
#include "ui_mainmenuwidget.h"

MainMenuWidget::MainMenuWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainMenuWidget)
{
    ui->setupUi(this);

    connect(ui->pushButtonCallbackLoginMenu, &QPushButton::clicked, this, [this]{
        emit signal_callbackLoginMenu();
    });
}

MainMenuWidget::~MainMenuWidget()
{
    delete ui;
}

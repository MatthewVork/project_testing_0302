#include "registerwidget.h"
#include "ui_registerwidget.h"

RegisterWidget::RegisterWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegisterWidget)
{
    ui->setupUi(this);

    connect(ui->pushButton_callback_loginwidget, &QPushButton::clicked, this, [this](){
        emit signal_CallbackLoginwidget();
    });
}

RegisterWidget::~RegisterWidget()
{
    delete ui;
}

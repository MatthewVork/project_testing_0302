#include "login_widget.h"
#include "ui_login_widget.h"

Login_Widget::Login_Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login_Widget)
{
    ui->setupUi(this);
}

Login_Widget::~Login_Widget()
{
    delete ui;
}

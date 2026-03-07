#include "menu_teacher.h"
#include "ui_menu_teacher.h"

menu_Teacher::menu_Teacher(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::menu_Teacher)
{
    ui->setupUi(this);
}

menu_Teacher::~menu_Teacher()
{
    delete ui;
}

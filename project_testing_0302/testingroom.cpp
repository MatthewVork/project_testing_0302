#include "testingroom.h"
#include "ui_testingroom.h"

TestingRoom::TestingRoom(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestingRoom)
{
    ui->setupUi(this);
}

TestingRoom::~TestingRoom()
{
    delete ui;
}

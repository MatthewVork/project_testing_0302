#include "mainwindow.h"
#include <QApplication>
#include <QFont> //
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFont globalFont("Microsoft YaHei", 9);
    a.setFont(globalFont);

    MainWindow w;
    w.show();

    return a.exec();
}

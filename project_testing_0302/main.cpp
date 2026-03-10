#include "mainwindow.h"
#include <QApplication>
#include <QFont> //
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 👇 极其霸气的全局接管：强制让所有界面都用纯正的“微软雅黑”，彻底干掉那个会导致数字变乱码的 UI 版！
    QFont globalFont("Microsoft YaHei", 9);
    a.setFont(globalFont);

    MainWindow w;
    w.show();

    return a.exec();
}

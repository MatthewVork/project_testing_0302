#include "tcpclient.h"

#include <QApplication>
const QString version="1.0.1";
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TcpClient w;
    w.show();
    return a.exec();
}

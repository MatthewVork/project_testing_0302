#ifndef MENU_TEACHER_H
#define MENU_TEACHER_H

#include <QWidget>
#include "NetProtocol.h"
namespace Ui {
class menu_Teacher;
}

class menu_Teacher : public QWidget
{
    Q_OBJECT

public:
    explicit menu_Teacher(QWidget *parent = nullptr);
    void handleCreateClassResult(bool success, QString msg);
    ~menu_Teacher();

signals:
    void signal_createClassReq(QString className);
    void signal_getClassesReq();

private slots:
    void on_btn_createClass_clicked();

private:
    Ui::menu_Teacher *ui;

public slots:
    void handleGetClassesResult(QJsonArray classes);
};

#endif // MENU_TEACHER_H

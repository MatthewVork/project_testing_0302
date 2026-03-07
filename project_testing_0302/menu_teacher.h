#ifndef MENU_TEACHER_H
#define MENU_TEACHER_H

#include <QWidget>

namespace Ui {
class menu_Teacher;
}

class menu_Teacher : public QWidget
{
    Q_OBJECT

public:
    explicit menu_Teacher(QWidget *parent = nullptr);
    ~menu_Teacher();

private:
    Ui::menu_Teacher *ui;
};

#endif // MENU_TEACHER_H

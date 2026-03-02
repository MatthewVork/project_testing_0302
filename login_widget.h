#ifndef LOGIN_WIDGET_H
#define LOGIN_WIDGET_H

#include <QWidget>

namespace Ui {
class Login_Widget;
}

class Login_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Login_Widget(QWidget *parent = nullptr);
    ~Login_Widget();

private:
    Ui::Login_Widget *ui;
};

#endif // LOGIN_WIDGET_H

#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

public slots:
    void check_login();
signals:
    // --- 只需要添加这一行 ---
    void signal_showRegister();


private:
    Ui::LoginWidget *ui;
};

#endif // LOGINWIDGET_H

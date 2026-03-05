#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H

#include <QWidget>

namespace Ui {
class MainMenuWidget;
}

class MainMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenuWidget(QWidget *parent = nullptr);
    ~MainMenuWidget();


public slots:
    void on_logoutBtn_clicked();
    void updateUserName(QString name);
signals:
    void signal_callbackLoginMenu();
    void signal_LogoutData();
private:
    Ui::MainMenuWidget *ui;
};

#endif // MAINMENUWIDGET_H

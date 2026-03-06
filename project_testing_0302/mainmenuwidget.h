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
    void updateTimeLabel(QString time);
    ~MainMenuWidget();


public slots:
    void on_logoutBtn_clicked();
    void updateUserName(QString name);
    void on_btn_joinExam_clicked();
    void handleJoinExamResult(bool success, QString msg, QString subject, int duration);
signals:
    void signal_callbackLoginMenu();
    void signal_LogoutData();
    void signal_joinExamReq(QString code);
    void signal_gotoTestPage();
private:
    Ui::MainMenuWidget *ui;
};

#endif // MAINMENUWIDGET_H

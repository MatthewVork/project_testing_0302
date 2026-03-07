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
    void handleScoresResult(const QJsonObject &data);
    void handleChangePwdResult(bool success, QString msg);
    void handleResult(bool success, QString msg);
    ~MainMenuWidget();


public slots:
    void on_logoutBtn_clicked();
    void updateUserName(QString name);
    void on_btn_joinExam_clicked();
    void on_btn_confirm_clicked();
    void handleJoinExamResult(bool success, QString msg, QString subject, int duration);
signals:
    void signal_callbackLoginMenu();
    void signal_LogoutData();
    void signal_joinExamReq(QString code);
    void signal_gotoTestPage();
    void signal_getScoresReq();
    void signal_changePwdReq(QString oldPwd, QString newPwd);
    void signal_changeSuccess();
private:
    Ui::MainMenuWidget *ui;
};

#endif // MAINMENUWIDGET_H

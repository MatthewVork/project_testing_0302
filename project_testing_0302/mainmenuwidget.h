#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H

#include <QWidget>
#include <QJsonObject>
#include <QJsonArray>
#include <QTableWidget>

namespace Ui {
class MainMenuWidget;
}

class MainMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenuWidget(QWidget *parent = nullptr);
    ~MainMenuWidget();

    // ================= 供大管家调用的外部接口 =================
    void updateTimeLabel(QString time);                                             // 更新右上角时间
    void updateUserName(QString name);                                              // 更新左侧用户名

    // --- 接收服务器下发的回执 ---
    void handleJoinExamResult(bool success, QString msg, QString subject, int duration);
    void handleScoresResult(const QJsonObject &data);
    void handleChangePwdResult(bool success, QString msg);
    void handleJoinClassResult(bool success, QString msg);
    void handleGetMyClassesResult(QJsonArray classes);

signals:
    // ================= 向外发射的信号 (请求大管家协助) =================
    void signal_callbackLoginMenu();                           // 切回登录页
    void signal_LogoutData();                                  // 发送注销包
    void signal_gotoTestPage(QString code);                    // 切换到考场界面

    // --- 纯网络发包请求 ---
    void signal_joinExamReq(QString code);                     // 申请进考场
    void signal_getScoresReq();                                // 申请查所有成绩
    void signal_changePwdReq(QString oldPwd, QString newPwd);  // 申请改密码
    void signal_joinClassReq(QString code);                    // 申请加群
    void signal_getMyClassesReq();                             // 申请拉取群列表
    void signal_changeSuccess();                               // 预留信号

private slots:
    // ================= UI 按钮交互与响应 =================
    void on_logoutBtn_clicked();                               // 点注销
    void on_btn_joinExam_clicked();                            // 点进考场
    void on_btn_joinClass_clicked();                           // 点加群
    void on_btn_confirm_clicked();                             // 点改密码

private:
    Ui::MainMenuWidget *ui;

    // ================= 极其好用的内部辅助工具 =================
    void initTables();                                         // 集中初始化所有表格表头
    void appendTableRow(QTableWidget *table, const QStringList &texts); // 终极表格填装神器
};

#endif // MAINMENUWIDGET_H

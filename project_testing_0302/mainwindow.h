// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QJsonArray>

// 引入所有部门经理（子页面）的头文件
#include "loginwidget.h"
#include "registerwidget.h"
#include "mainmenuwidget.h"
#include "testingroom.h"
#include "menu_teacher.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // ================= 核心网络收包枢纽 =================
    void on_clientReadData();

private:
    Ui::MainWindow *ui;

    // ================= 核心基建组件 =================
    QTcpSocket *tcpSocket;          // 负责与服务器通信的“对讲机”

    // ================= 各部门经理 (页面指针) =================
    LoginWidget *loginPage;         // 登录页
    RegisterWidget *regPage;        // 注册页
    MainMenuWidget *menuPage;       // 学生大厅
    TestingRoom *testPage;          // 答题考场
    menu_Teacher *menuteach;        // 教师大厅

    // ================= 架构级初始化辅助函数 =================
    void initUI();                  // 负责分配页面、建全局定时器
    void initPageJumps();           // 负责页面跳转连线、数据派发连线
    void initNetwork();             // 负责所有 TCP 发包/收包的连线

signals:
    // ================= 全局系统信号 =================
    void signal_broadcastTime(QString timeStr);

    // ================= 派发给：登录/注册部门 =================
    void signal_loginResult(bool success, QString msg, int role);
    void signal_logoutResult(bool success, QString msg);
    void signal_registerResult(bool success, QString msg);

    // ================= 派发给：学生/考场部门 =================
    void signal_joinExamResult(bool success, QString msg, QString subject, int duration);
    void signal_joinClassResult(bool success, QString msg);
    void signal_getMyClassesResult(QJsonArray classes);

    // ================= 派发给：教师部门 =================
    void signal_createClassResult(bool success, QString msg);
    void signal_getClassesResult(QJsonArray classes);
    void signal_getClassStudentsResult(QJsonArray students);
    void signal_addQuestionResult(bool success, QString msg);
    void signal_publishExamResult(bool success, QString msg, QString examCode);
    void signal_getClassExamsResult(QJsonArray exams);
    void signal_getExamScoresResult(QJsonArray scores);
};

#endif // MAINWINDOW_H

// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include "loginwidget.h"    // 包含你的独立界面头文件
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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_clientReadData();
private:
    Ui::MainWindow *ui;
    // 定义成员变量，方便后续切换页面
    LoginWidget *loginPage;
    RegisterWidget *regPage;
    MainMenuWidget *menuPage;
    TestingRoom *testPage;
    QTcpSocket *tcpSocket;
    menu_Teacher *menuteach;

signals:    //存放各个窗口内的信号
    void signal_broadcastTime(QString timeStr);
    void signal_loginResult(bool success, QString msg, int role);
    void signal_logoutResult(bool success, QString msg);
    void signal_registerResult(bool success, QString msg);
    void signal_joinExamResult(bool success, QString msg, QString subject, int duration);
    void signal_createClassResult(bool success, QString msg);
    void signal_getClassesResult(QJsonArray classes);
    void signal_getClassesReq();
    void signal_joinClassResult(bool success, QString msg); // 👈 告诉学生大厅加群结果
    void signal_getMyClassesResult(QJsonArray classes);
    void signal_getClassStudentsResult(QJsonArray students); // 👈 告诉大厅查询结果
    void signal_addQuestionResult(bool success, QString msg);
    void signal_publishExamResult(bool success, QString msg, QString examCode);
    void signal_getClassExamsResult(QJsonArray exams);
    void signal_getExamScoresResult(QJsonArray scores);

public:
    void handleGetClassesResult(QJsonArray classes); // 👈 填表格的函数
};
#endif

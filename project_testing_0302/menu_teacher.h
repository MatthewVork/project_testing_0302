#ifndef MENU_TEACHER_H
#define MENU_TEACHER_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonObject>
#include <QTableWidget>
#include "NetProtocol.h"

namespace Ui {
class menu_Teacher;
}

class menu_Teacher : public QWidget
{
    Q_OBJECT

public:
    explicit menu_Teacher(QWidget *parent = nullptr);
    ~menu_Teacher();

    // ================= 供大管家调用的外部接口 =================
    void updateTimeLabel(QString time);
    void handleCreateClassResult(bool success, QString msg);
    void handleAddQuestionResult(bool success, QString msg);
    void handleGetClassStudentsResult(QJsonArray students);
    void handleGetClassesResult(QJsonArray classes);
    void handlePublishExamResult(bool success, QString msg, QString examCode);
    void handleGetClassExamsResult(QJsonArray exams);
    void handleGetExamScoresResult(QJsonArray scores);

signals:
    // ================= 纯网络发包请求 =================
    void signal_createClassReq(QString className);
    void signal_getClassStudentsReq(QString classCode);
    void signal_getClassesReq();
    void signal_addQuestionReq(QJsonObject data);
    void signal_publishExamReq(QJsonObject data);
    void signal_getClassExamsReq(QString classCode);
    void signal_getExamScoresReq(QString examCode);

    // ================= 页面切换信号 =================
    void signal_logoutReq();

private slots:
    // ================= UI 按钮交互 =================
    void on_btn_createClass_clicked();
    void on_btn_finishExam_clicked();
    void on_btn_searchStudents_clicked();
    void on_btn_addQuestion_clicked();
    void on_btn_generateExam_clicked();
    void on_comboBox_scoreClass_currentIndexChanged(int index);
    void on_btn_searchScores_clicked();

private:
    Ui::menu_Teacher *ui;

    // ================= 极其好用的内部辅助工具 =================
    void initTables();
    void initTreeMenu();
    void appendTableRow(QTableWidget *table, const QStringList &texts);
};

#endif // MENU_TEACHER_H

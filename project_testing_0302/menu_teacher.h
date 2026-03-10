#ifndef MENU_TEACHER_H
#define MENU_TEACHER_H

#include <QWidget>
#include "NetProtocol.h"
namespace Ui {
class menu_Teacher;
}

class menu_Teacher : public QWidget
{
    Q_OBJECT

public:
    explicit menu_Teacher(QWidget *parent = nullptr);
    void handleCreateClassResult(bool success, QString msg);
    void handleAddQuestionResult(bool success, QString msg);
    void handleGetClassStudentsResult(QJsonArray students);
    void handleGetClassesResult(QJsonArray classes);
    void handlePublishExamResult(bool success, QString msg, QString examCode); // 👈 接收结果，准备亮牌
    void handleGetClassExamsResult(QJsonArray exams);
    void handleGetExamScoresResult(QJsonArray scores);
    ~menu_Teacher();

signals:
    void signal_createClassReq(QString className);
    void signal_getClassStudentsReq(QString classCode);
    void signal_getClassesReq();
    void signal_addQuestionReq(QJsonObject data);
    void signal_publishExamReq(QJsonObject data);
    void signal_getClassExamsReq(QString classCode);
    void signal_getExamScoresReq(QString examCode);
    void signal_logoutReq();

private slots:
    void on_btn_createClass_clicked();

private:
    Ui::menu_Teacher *ui;

public slots:
    void on_btn_searchStudents_clicked();
    void on_btn_addQuestion_clicked();
    void on_btn_generateExam_clicked();
    void on_comboBox_scoreClass_currentIndexChanged(int index);
    void on_btn_searchScores_clicked();
};

#endif // MENU_TEACHER_H

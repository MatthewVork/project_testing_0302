#ifndef TESTINGROOM_H
#define TESTINGROOM_H

#include <QWidget>
#include <QPushButton>

struct Question {
    QString questionText;
    QString optA, optB, optC, optD;
    QString correctAnswer;
};

namespace Ui {
class TestingRoom;
}

class TestingRoom : public QWidget
{
    Q_OBJECT

public:
    explicit TestingRoom(QWidget *parent = nullptr);

    ~TestingRoom();

    void handlePaperResult(const QJsonObject &data);
    void requestPaper(QString examCode);

private:
    Ui::TestingRoom *ui;

private:
    // 动态生成答题卡，参数为题目总数
    void initAnswerCard(int totalCount);

    // 点击题号按钮后的处理槽函数
    void on_answerBtn_clicked();

    QList<Question> m_questions; // 存储所有题目
    int m_currentIndex = 0;      // 当前正在做第几题
    void showQuestion(int index); // 刷新界面显示题目的函数
    QList<QPushButton*> m_btnList;

    QMap<int, QString> m_userAnswers; // 存储用户的答案，格式为：<题号, 选项(A/B/C/D)>
    void saveCurrentAnswer();         // 保存当前屏幕上选中的答案
    void updateRadioSelection(int index); // 翻页时，恢复之前选中的答案
//
    QTimer *m_timer;         // 咱们的秒表
    int m_remainSeconds;     // 剩下的总秒数

    void startTimer(int minutes); // 启动倒计时的函数

private slots:
    void on_timer_timeout(); // 秒表每次“滴答”一下，就执行这个函数
    void on_btn_submit_clicked();
    void on_btn_next_clicked();
    void on_btn_prev_clicked();
    void on_option_clicked();


signals:
    void signal_sendData(const QByteArray &data);
};
#endif // TESTINGROOM_H

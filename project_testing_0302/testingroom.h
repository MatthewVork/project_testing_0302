#ifndef TESTINGROOM_H
#define TESTINGROOM_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>
#include <QList>
#include <QMap>
#include <QJsonObject>
#include <QByteArray>

// 极其纯粹的题目数据结构
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

    // ================= 供大管家调用的外部接口 =================
    void requestPaper(QString examCode);             // 申请获取卷子
    void handlePaperResult(const QJsonObject &data); // 接收服务器下发的卷子

signals:
    // ================= 向外发射的信号 =================
    void signal_sendData(const QByteArray &data);    // 把打包好的数据丢给大管家发送
    void signal_examFinished();                      // 通知大管家：考完了，切回大厅！

private slots:
    // ================= UI 交互与定时器槽函数 =================
    void on_btn_submit_clicked();                    // 玩家点击交卷
    void on_btn_next_clicked();                      // 下一题
    void on_btn_prev_clicked();                      // 上一题
    void on_answerBtn_clicked();                     // 点击右侧答题卡题号
    void on_option_clicked();                        // ABCD 选项点击

    void on_timer_timeout();                         // 秒表的“滴答”事件

private:
    Ui::TestingRoom *ui;

    // ================= 核心状态变量（数据中心） =================
    QString m_currentExamCode;            // 当前考试码
    QList<Question> m_questions;          // 本场考试的真实题库
    QMap<int, QString> m_userAnswers;     // 答题记录簿 <题号, 选项>
    QList<QPushButton*> m_btnList;        // 答题卡按钮全家桶
    int m_currentIndex = 0;               // 当前正在做的题号索引

    QTimer *m_timer;                      // 倒计时秒表
    int m_remainSeconds;                  // 剩余总秒数

    // ================= 内部辅助函数（脏活累活） =================
    void initAnswerCard(int totalCount);  // 动态生成右侧的答题卡按钮
    void showQuestion(int index);         // 将指定题目的文字渲染到界面
    void saveCurrentAnswer();             // 保存当前屏幕上选中的答案
    void updateRadioSelection(int index); // 翻页时，精准回显之前选过的答案

    void startTimer(int minutes);         // 启动倒计时引擎
    void processSubmit();                 // 算分与强制交卷机器
};

#endif // TESTINGROOM_H

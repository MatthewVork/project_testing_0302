#include "testingroom.h"
#include "ui_testingroom.h"
#include "NetProtocol.h"

TestingRoom::TestingRoom(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestingRoom)
{
    ui->setupUi(this);
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &TestingRoom::on_timer_timeout);

    // 统一绑定选项点击事件，实现：点选即刻保存答案 + 答题卡秒变护眼绿
    connect(ui->radio_A, &QRadioButton::clicked, this, &TestingRoom::on_option_clicked);
    connect(ui->radio_B, &QRadioButton::clicked, this, &TestingRoom::on_option_clicked);
    connect(ui->radio_C, &QRadioButton::clicked, this, &TestingRoom::on_option_clicked);
    connect(ui->radio_D, &QRadioButton::clicked, this, &TestingRoom::on_option_clicked);
}

TestingRoom::~TestingRoom() {
    delete ui;
}

// ==========================================
// 🏢 1. 考场初始化与网络通信模块
// ==========================================
void TestingRoom::requestPaper(QString examCode) {
    m_currentExamCode = examCode;
    QByteArray plainData = NetProtocol::packExamCode(MSG_GET_PAPER, examCode);
    emit signal_sendData(NetProtocol::encrypt(plainData));
}

void TestingRoom::handlePaperResult(const QJsonObject &data) {
    QJsonArray array = data["questions"].toArray();

    //清空旧题目和上一场的旧答案
    m_questions.clear();
    m_userAnswers.clear();

    // 解析新卷子
    for (int i = 0; i < array.size(); ++i) {
        QJsonObject obj = array[i].toObject();
        Question q;
        q.questionText = obj["text"].toString();
        q.optA = obj["A"].toString();
        q.optB = obj["B"].toString();
        q.optC = obj["C"].toString();
        q.optD = obj["D"].toString();
        q.correctAnswer = obj["answer"].toString();
        m_questions.append(q);
    }

    // 渲染答题卡、显示第一题、开始计时
    initAnswerCard(m_questions.size());
    if (!m_questions.isEmpty()) showQuestion(0);
    startTimer(60); // 留个伏笔：未来可以根据服务器下发的 duration 来替换这个 60
}

void TestingRoom::initAnswerCard(int totalCount) {
    QGridLayout *gridLayout = qobject_cast<QGridLayout*>(ui->widget->layout());
    if (!gridLayout) return;

    m_btnList.clear();

    // 清理界面残留的旧按钮
    QLayoutItem *child;
    while ((child = gridLayout->takeAt(0)) != nullptr) {
        if(child->widget()) delete child->widget();
        delete child;
    }

    // 动态生成新按钮
    int columnCount = 5;
    for (int i = 0; i < totalCount; ++i) {
        QPushButton *btn = new QPushButton(QString::number(i + 1), ui->widget);
        btn->setFixedSize(40, 40);
        btn->setStyleSheet("QPushButton { background-color: #f0f0f0; border-radius: 5px; font-weight: bold; }");
        btn->setProperty("index", i); // 贴上题号暗号

        gridLayout->addWidget(btn, i / columnCount, i % columnCount);
        m_btnList.append(btn);
        connect(btn, &QPushButton::clicked, this, &TestingRoom::on_answerBtn_clicked);
    }
}

// ==========================================
// 🏢 2. 答题与 UI 交互模块
// ==========================================
void TestingRoom::showQuestion(int index) {
    if (index < 0 || index >= m_questions.size()) return;

    m_currentIndex = index;
    Question q = m_questions[index];

    // 渲染题目文字
    ui->textBrowser_question->setText(QString("第 %1 题：\n%2").arg(index + 1).arg(q.questionText));
    ui->radio_A->setText(q.optA);
    ui->radio_B->setText(q.optB);
    ui->radio_C->setText(q.optC);
    ui->radio_D->setText(q.optD);

    updateRadioSelection(index);
}

void TestingRoom::on_btn_next_clicked() {
    if (m_currentIndex < m_questions.size() - 1) showQuestion(m_currentIndex + 1);
    else QMessageBox::information(this, "提示", "已经是最后一题了");
}

void TestingRoom::on_btn_prev_clicked() {
    if (m_currentIndex > 0) showQuestion(m_currentIndex - 1);
}

void TestingRoom::on_answerBtn_clicked() {
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (btn) showQuestion(btn->property("index").toInt());
}

void TestingRoom::on_option_clicked() {
    saveCurrentAnswer(); // 极其灵敏：点选任何一个选项瞬间保存
    if (m_currentIndex >= 0 && m_currentIndex < m_btnList.size()) {
        m_btnList[m_currentIndex]->setStyleSheet(
            "QPushButton { background-color: #90EE90; color: black; border-radius: 5px; font-weight: bold; }");
    }
}

void TestingRoom::saveCurrentAnswer() {
    if (ui->radio_A->isChecked()) m_userAnswers[m_currentIndex] = "A";
    else if (ui->radio_B->isChecked()) m_userAnswers[m_currentIndex] = "B";
    else if (ui->radio_C->isChecked()) m_userAnswers[m_currentIndex] = "C";
    else if (ui->radio_D->isChecked()) m_userAnswers[m_currentIndex] = "D";
}

void TestingRoom::updateRadioSelection(int index) {
    if (m_userAnswers.contains(index)) {
        QString ans = m_userAnswers[index];
        if (ans == "A") ui->radio_A->setChecked(true);
        else if (ans == "B") ui->radio_B->setChecked(true);
        else if (ans == "C") ui->radio_C->setChecked(true);
        else if (ans == "D") ui->radio_D->setChecked(true);
    } else {
        // 全面清除旧题残留勾选
        ui->buttonGroup->setExclusive(false);
        ui->radio_A->setChecked(false);
        ui->radio_B->setChecked(false);
        ui->radio_C->setChecked(false);
        ui->radio_D->setChecked(false);
        ui->buttonGroup->setExclusive(true);
    }
}

// ==========================================
// 🏢 3. 核心倒计时与交卷处理模块
// ==========================================
void TestingRoom::startTimer(int minutes) {
    m_remainSeconds = minutes * 60;
    m_timer->start(1000);
    on_timer_timeout(); // 手动触发一次，避免等待 1 秒
}

void TestingRoom::on_timer_timeout() {
    if (m_remainSeconds <= 0) {
        m_timer->stop();
        ui->label_timer->setText("00:00");
        QMessageBox::warning(this, "时间到", "考试时间已到，系统将强制交卷！");
        processSubmit();
        return;
    }
    m_remainSeconds--;
    //时间的数学运算与补零格式化
    ui->label_timer->setText(QString("%1:%2").arg(m_remainSeconds / 60, 2, 10, QChar('0')).arg(m_remainSeconds % 60, 2, 10, QChar('0')));
}

void TestingRoom::on_btn_submit_clicked() {
    if (QMessageBox::question(this, "交卷确认", "确认要交卷吗？") == QMessageBox::Yes) {
        processSubmit();
    }
}

void TestingRoom::processSubmit() {
    saveCurrentAnswer(); // 以防万一的最后一次保存
    if (m_timer->isActive()) m_timer->stop();

    // 智能算分
    int score = 0;
    int totalQuestions = m_questions.size();
    int scorePerQuestion = totalQuestions > 0 ? (100 / totalQuestions) : 0;

    for (int i = 0; i < totalQuestions; ++i) {
        if (m_userAnswers.value(i) == m_questions[i].correctAnswer) {
            score += scorePerQuestion;
        }
    }

    // 打包加密发送
    QJsonObject root, submitData;
    submitData["exam_code"] = m_currentExamCode;
    submitData["score"] = score;
    root["type"] = MSG_SUBMIT_EXAM;
    root["data"] = submitData;
    emit signal_sendData(NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));

    // 善后工作
    QMessageBox::information(this, "考试结束", QString("批改完成！\n你的最终得分是：%1 分").arg(score));
    m_userAnswers.clear();      // 清空当前答案缓存
    emit signal_examFinished(); // 通知大管家切页面
}

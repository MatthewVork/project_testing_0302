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

    connect(ui->radio_A, &QRadioButton::clicked, this, &TestingRoom::on_option_clicked);
    connect(ui->radio_B, &QRadioButton::clicked, this, &TestingRoom::on_option_clicked);
    connect(ui->radio_C, &QRadioButton::clicked, this, &TestingRoom::on_option_clicked);
    connect(ui->radio_D, &QRadioButton::clicked, this, &TestingRoom::on_option_clicked);
}

TestingRoom::~TestingRoom()
{
    delete ui;
}

void TestingRoom::initAnswerCard(int totalCount) {
    QGridLayout *gridLayout = qobject_cast<QGridLayout*>(ui->widget->layout());
    if (!gridLayout) {
        qDebug() << "布局错误：请在 Designer 里给 widget 设置网格布局";
        return;
        m_btnList.clear();
    }

    // 拆除防线：先把界面上可能残留的旧按钮全部删掉
    QLayoutItem *child;
    while ((child = gridLayout->takeAt(0)) != nullptr) {
        if(child->widget()) {
            delete child->widget();
        }
        delete child;
    }

    // 根据真实数量生成新按钮
    int columnCount = 5;
    for (int i = 0; i < totalCount; ++i) {
        QPushButton *btn = new QPushButton(QString::number(i + 1), ui->widget);
        btn->setFixedSize(40, 40);
        btn->setStyleSheet("QPushButton { background-color: #f0f0f0; border-radius: 5px; font-weight: bold; }");

        btn->setProperty("index", i); // 贴上题号标签

        int row = i / columnCount;
        int col = i % columnCount;

        m_btnList.append(btn);
        gridLayout->addWidget(btn, row, col); // 按网格坐标放入

        connect(btn, &QPushButton::clicked, this, &TestingRoom::on_answerBtn_clicked);
    }
}


void TestingRoom::requestPaper(QString examCode) {

    m_currentExamCode = examCode;   //保存考试码
    // 1. 打包请求（使用你 NetProtocol 里的打包工具）
    QByteArray plainData = NetProtocol::packExamCode(MSG_GET_PAPER, examCode);

    // 2. 加密并发射信号给 MainWindow（假设你已经在大厅拿到了考试码）
    emit signal_sendData(NetProtocol::encrypt(plainData));
}

void TestingRoom::handlePaperResult(const QJsonObject &data) {
    // 1. 获取服务器发来的题目 JSON 数组
    QJsonArray array = data["questions"].toArray();

    // 2. 清空本地旧题库（防止第二场考试和第一场叠加）
    m_questions.clear();

    // 3. 循环解析真实数据，存进列表
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

    // 4. 重点：根据真实题目的数量，动态生成答题卡！
    initAnswerCard(m_questions.size());

    // 5. 重点：立刻把第一题的文字“打印”到界面上！
    if (!m_questions.isEmpty()) {
        showQuestion(0);
    } else {
        qDebug() << "警告：服务器发来的卷子是空的！";
    }

    startTimer(60);
}

void TestingRoom::on_answerBtn_clicked() {
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (btn) {
        int targetIndex = btn->property("index").toInt();

        // 保存当前题目的答案（防止切题时丢了）
        saveCurrentAnswer();

        // 显示新题目
        showQuestion(targetIndex);
    }
}

void TestingRoom::showQuestion(int index) {
    // 防御性判断，防止越界崩溃
    if (index < 0 || index >= m_questions.size()) return;

    m_currentIndex = index;
    Question q = m_questions[index]; // 从真实的题库列表里拿出这道题

    // 👇 真正把题目文字塞进你 UI 控件的地方
    ui->textBrowser_question->setText(QString("第 %1 题：\n%2").arg(index + 1).arg(q.questionText));
    ui->radio_A->setText(q.optA);
    ui->radio_B->setText(q.optB);
    ui->radio_C->setText(q.optC);
    ui->radio_D->setText(q.optD);

    // 恢复这道题之前选过的答案（如果有的话）
    updateRadioSelection(index);
}

void TestingRoom::on_btn_next_clicked() {
    if (m_currentIndex < m_questions.size() - 1) {
        saveCurrentAnswer();
        showQuestion(m_currentIndex + 1);
    } else {
        QMessageBox::information(this, "提示", "已经是最后一题了");
    }
}

void TestingRoom::on_btn_prev_clicked() {
    if (m_currentIndex > 0) {
        saveCurrentAnswer();
        showQuestion(m_currentIndex - 1);
    }
}

// 1. 保存当前这道题选了啥
void TestingRoom::saveCurrentAnswer() {
    // 检查界面上到底哪个选项被点亮了
    if (ui->radio_A->isChecked()) {
        m_userAnswers[m_currentIndex] = "A";
    } else if (ui->radio_B->isChecked()) {
        m_userAnswers[m_currentIndex] = "B";
    } else if (ui->radio_C->isChecked()) {
        m_userAnswers[m_currentIndex] = "C";
    } else if (ui->radio_D->isChecked()) {
        m_userAnswers[m_currentIndex] = "D";
    }
}

// 2. 切题的时候，把以前选过的答案重新勾上
void TestingRoom::updateRadioSelection(int index) {
    // 如果这道题之前做过，并且存了答案
    if (m_userAnswers.contains(index)) {
        QString ans = m_userAnswers[index];
        if (ans == "A") ui->radio_A->setChecked(true);
        else if (ans == "B") ui->radio_B->setChecked(true);
        else if (ans == "C") ui->radio_C->setChecked(true);
        else if (ans == "D") ui->radio_D->setChecked(true);
    } else {
        // 如果是没做过的新题，确保四个按钮全是空着的（清理上一题残留的勾选）
        ui->buttonGroup->setExclusive(false);
        ui->radio_A->setChecked(false);
        ui->radio_B->setChecked(false);
        ui->radio_C->setChecked(false);
        ui->radio_D->setChecked(false);
        ui->buttonGroup->setExclusive(true);
    }
}

// 启动倒计时
void TestingRoom::startTimer(int minutes) {
    m_remainSeconds = minutes * 60; // 把分钟换算成秒
    m_timer->start(1000);           // 启动！每 1000 毫秒走一次

    // 手动调用一次，让界面立刻显示 60:00，而不是等1秒后才显示
    on_timer_timeout();
}

// 每秒钟执行一次的“滴答”操作
void TestingRoom::on_timer_timeout() {
    // 1. 检查是不是没时间了
    if (m_remainSeconds <= 0) {
        m_timer->stop();
        ui->label_timer->setText("00:00"); // ⚠️注意：这里假设你的控件叫 label_timer
        QMessageBox::warning(this, "时间到", "考试时间已到，系统将自动交卷！");

        // 留个伏笔：以后在这里调用你自动交卷的函数
        // emit signal_submitExam();
        return;
    }

    // 2. 时间减 1 秒
    m_remainSeconds--;

    // 3. 数学计算：算出几分几秒
    int m = m_remainSeconds / 60;
    int s = m_remainSeconds % 60;

    // 4. 格式化成 00:00 的高级写法
    // arg(数值, 占据几位, 进制, 补齐字符) -> 保证 5 秒显示为 05
    QString timeStr = QString("%1:%2")
                          .arg(m, 2, 10, QChar('0'))
                          .arg(s, 2, 10, QChar('0'));

    // 5. 显示到界面上
    // ⚠️ 如果你用的是 QLabel，就用这句：
    ui->label_timer->setText(timeStr);
}

void TestingRoom::on_btn_submit_clicked() {
    // 1. 弹窗让考生确认，防止手滑点错
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "交卷确认", "确认要结束考试并交卷吗？",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return; // 后悔了，继续考
    }

    // 2. 极其关键：把当前停留在屏幕上，还没来得及按“下一题”的答案保存下来！
    saveCurrentAnswer();

    // 3. 停止倒计时
    if (m_timer->isActive()) {
        m_timer->stop();
    }

    // 4. 开始疯狂批改试卷（算分）
    int score = 0;
    int totalQuestions = m_questions.size();

    // 假设满分 100 分，算出每题多少分
    int scorePerQuestion = totalQuestions > 0 ? (100 / totalQuestions) : 0;

    for (int i = 0; i < totalQuestions; ++i) {
        // 如果这道题考生做了，并且答案等于正确答案
        if (m_userAnswers.contains(i) && m_userAnswers[i] == m_questions[i].correctAnswer) {
            score += scorePerQuestion; // 加分！
        }
    }

    // 5. 弹出最终成绩单
    QMessageBox::information(this, "考试结束", QString("批改完成！\n你的最终得分是：%1 分").arg(score));

    // 👇 新增：把成绩打包发给服务器
    QJsonObject submitData;
    submitData["exam_code"] = m_currentExamCode;
    submitData["score"] = score;

    QJsonObject root;
    root["type"] = MSG_SUBMIT_EXAM;
    root["data"] = submitData;

    emit signal_sendData(NetProtocol::encrypt(QJsonDocument(root).toJson(QJsonDocument::Compact)));

    // 6. 退出考场，清理战场（方便下一次进考场）
    m_userAnswers.clear();

    // 可选：发射一个信号给 MainWindow，让它把界面切回“大厅”
    emit signal_examFinished();
}

void TestingRoom::on_option_clicked() {
    // 1. 既然考生点选了答案，我们顺手立刻保存，防止丢失
    saveCurrentAnswer();

    // 2. 从小本子里找到当前这道题对应的按钮，给它刷上护眼绿！
    if (m_currentIndex >= 0 && m_currentIndex < m_btnList.size()) {
        m_btnList[m_currentIndex]->setStyleSheet(
            "QPushButton { "
            "background-color: #90EE90; " /* 浅绿色 */
            "color: black; "              /* 黑色字体 */
            "border-radius: 5px; "
            "font-weight: bold; "
            "}"
            );
    }
}

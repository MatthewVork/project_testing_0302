#include <QMessageBox>
#include "menu_teacher.h"
#include "ui_menu_teacher.h"

menu_Teacher::menu_Teacher(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::menu_Teacher)
{
    ui->setupUi(this);

    initTables();
    initTreeMenu();
}

menu_Teacher::~menu_Teacher() {
    delete ui;
}

// ==========================================
// 🏢 1. UI 初始化与辅助神器模块
// ==========================================
void menu_Teacher::initTables() {
    ui->tableWidget_classes->setColumnCount(2);
    ui->tableWidget_classes->setHorizontalHeaderLabels(QStringList() << "班级名称" << "班级邀请码");
    ui->tableWidget_classes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget_students->setColumnCount(1);
    ui->tableWidget_students->setHorizontalHeaderLabels(QStringList() << "学生账号");
    ui->tableWidget_students->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget_scores->setColumnCount(3);
    ui->tableWidget_scores->setHorizontalHeaderLabels(QStringList() << "学生账号" << "考试分数" << "交卷时间");
    ui->tableWidget_scores->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void menu_Teacher::initTreeMenu() {
    ui->treeWidget_nav->expandAll();
    connect(ui->treeWidget_nav, &QTreeWidget::itemClicked, this, [this](QTreeWidgetItem *item, int column){
        QString text = item->text(0);
        if (item->childCount() > 0) {
            item->setExpanded(!item->isExpanded());
            return;
        }

        if (text == "创建班级") ui->stackedWidget->setCurrentIndex(0);
        else if (text == "学生名单") ui->stackedWidget->setCurrentIndex(1);
        else if (text == "录入题目") ui->stackedWidget->setCurrentIndex(2);
        else if (text == "组卷与发布") ui->stackedWidget->setCurrentIndex(3);
        else if (text == "班级成绩总榜") ui->stackedWidget->setCurrentIndex(4);
        else if (text == "修改密码") ui->stackedWidget->setCurrentIndex(5);
        else if (text == "安全退出") {
            if (QMessageBox::question(this, "退出确认", "确定要退出教师系统吗？") == QMessageBox::Yes) {
                emit signal_logoutReq();
            }
        }
    });
}

//填表函数
void menu_Teacher::appendTableRow(QTableWidget *table, const QStringList &texts) {
    int row = table->rowCount();
    table->insertRow(row);
    for (int i = 0; i < texts.size(); ++i) {
        QTableWidgetItem *item = new QTableWidgetItem(texts[i]);
        item->setTextAlignment(Qt::AlignCenter);
        table->setItem(row, i, item);
    }
}

// ==========================================
// 🏢 2. 外部接口 (大管家调用)
// ==========================================
void menu_Teacher::updateTimeLabel(QString time) {
    if (ui->label_time) ui->label_time->setText(time);
}

void menu_Teacher::handleCreateClassResult(bool success, QString msg) {
    if (success) {
        QMessageBox::information(this, "创建结果", msg);
        ui->lineEdit_className->clear();
        emit signal_getClassesReq(); // 建班成功立刻刷新
    } else QMessageBox::warning(this, "创建失败", msg);
}

void menu_Teacher::handleGetClassesResult(QJsonArray classes) {
    ui->comboBox_scoreClass->clear();
    ui->comboBox_scoreClass->addItem("🌍 全网公开（任何人凭码可考）", "");
    ui->comboBox_myClasses->clear();
    ui->comboBox_examClass->clear();
    ui->comboBox_examClass->addItem("🌍 全网公开（任何人凭码可考）", "");
    ui->tableWidget_classes->setRowCount(0);

    for(int i = 0; i < classes.size(); ++i) {
        QJsonObject obj = classes[i].toObject();
        QString name = obj["class_name"].toString();
        QString code = obj["class_code"].toString();

        appendTableRow(ui->tableWidget_classes, QStringList() << name << code);
        ui->comboBox_scoreClass->addItem(name, code);
        ui->comboBox_myClasses->addItem(name, code);
        ui->comboBox_examClass->addItem(name, code);
    }
}

void menu_Teacher::handleGetClassStudentsResult(QJsonArray students) {
    ui->tableWidget_students->setRowCount(0);
    for(int i = 0; i < students.size(); ++i) {
        //渲染函数
        appendTableRow(ui->tableWidget_students, QStringList() << students[i].toObject()["username"].toString());
    }
}

void menu_Teacher::handleAddQuestionResult(bool success, QString msg) {
    if (success) {
        QMessageBox::information(this, "成功", msg);
        ui->textEdit_question->clear();
        ui->lineEdit_optA->clear();
        ui->lineEdit_optB->clear();
        ui->lineEdit_optC->clear();
        ui->lineEdit_optD->clear();
        ui->comboBox_answer->setCurrentIndex(0);
        ui->textEdit_question->setFocus();
    } else QMessageBox::warning(this, "失败", msg);
}

void menu_Teacher::handlePublishExamResult(bool success, QString msg, QString examCode) {
    if (success) {
        ui->label_examCodeDisplay->setText(examCode);
        ui->label_examCodeDisplay->setStyleSheet("color: #E74C3C; font-weight: bold; font-size: 28px;");
        QMessageBox::information(this, "生成成功", "考试码已生成！\n请复制该码，并前往左侧【录入题目】界面为该考试加题。");
    } else QMessageBox::warning(this, "生成失败", msg);
}

void menu_Teacher::handleGetClassExamsResult(QJsonArray exams) {
    ui->comboBox_scoreExam->clear();
    for(int i = 0; i < exams.size(); ++i) {
        QJsonObject obj = exams[i].toObject();
        QString code = obj["exam_code"].toString();
        QString subject = obj["subject"].toString();
        ui->comboBox_scoreExam->addItem(QString("%1 (码: %2)").arg(subject).arg(code), code);
    }
}

void menu_Teacher::handleGetExamScoresResult(QJsonArray scores) {
    ui->tableWidget_scores->setRowCount(0);
    for (int i = 0; i < scores.size(); ++i) {
        QJsonObject obj = scores[i].toObject();
        int row = ui->tableWidget_scores->rowCount();
        ui->tableWidget_scores->insertRow(row);

        QTableWidgetItem *userItem = new QTableWidgetItem(obj["username"].toString());
        QTableWidgetItem *scoreItem = new QTableWidgetItem(QString::number(obj["score"].toInt()) + " 分");
        QTableWidgetItem *timeItem = new QTableWidgetItem("已交卷");

        userItem->setTextAlignment(Qt::AlignCenter);
        scoreItem->setTextAlignment(Qt::AlignCenter);
        timeItem->setTextAlignment(Qt::AlignCenter);
        scoreItem->setForeground(QBrush(QColor("#E74C3C"))); // 给分数标个醒目的红色

        ui->tableWidget_scores->setItem(row, 0, userItem);
        ui->tableWidget_scores->setItem(row, 1, scoreItem);
        ui->tableWidget_scores->setItem(row, 2, timeItem);
    }
}

// ==========================================
// 🏢 3. UI 玩家主动交互模块
// ==========================================
void menu_Teacher::on_btn_createClass_clicked() {
    QString className = ui->lineEdit_className->text().trimmed();
    if (className.isEmpty()) { QMessageBox::warning(this, "提示", "班级名称不能为空！"); return; }
    emit signal_createClassReq(className);
}

void menu_Teacher::on_btn_searchStudents_clicked() {
    QString code = ui->comboBox_myClasses->currentData().toString();
    if(code.isEmpty()) { QMessageBox::warning(this, "提示", "请先选择一个有效的班级！"); return; }
    emit signal_getClassStudentsReq(code);
}

void menu_Teacher::on_btn_addQuestion_clicked() {
    QString code = ui->lineEdit_examCode->text().trimmed();
    QString question = ui->textEdit_question->toPlainText().trimmed();
    QString optA = ui->lineEdit_optA->text().trimmed();
    QString optB = ui->lineEdit_optB->text().trimmed();
    QString optC = ui->lineEdit_optC->text().trimmed();
    QString optD = ui->lineEdit_optD->text().trimmed();
    QString answer = ui->comboBox_answer->currentText();

    if(code.isEmpty() || question.isEmpty() || optA.isEmpty() || optB.isEmpty() || optC.isEmpty() || optD.isEmpty()) {
        QMessageBox::warning(this, "提示", "请将考试码、题目和选项填写完整！"); return;
    }

    QJsonObject qData;
    qData["exam_code"] = code; qData["question_text"] = question;
    qData["option_A"] = optA;  qData["option_B"] = optB;
    qData["option_C"] = optC;  qData["option_D"] = optD;
    qData["correct_answer"] = answer;
    emit signal_addQuestionReq(qData);
}

void menu_Teacher::on_btn_generateExam_clicked() {
    QString classCode = ui->comboBox_examClass->currentData().toString();
    QString subject = ui->lineEdit_subject->text().trimmed();
    int duration = ui->spinBox_duration->value();

    if (subject.isEmpty() || duration <= 0) {
        QMessageBox::warning(this, "提示", "请正确填写科目和大于0的时长！"); return;
    }

    QJsonObject reqData;
    reqData["class_code"] = classCode; reqData["subject"] = subject; reqData["duration"] = duration;
    emit signal_publishExamReq(reqData);
}

void menu_Teacher::on_comboBox_scoreClass_currentIndexChanged(int index) {
    if (index < 0) return;
    emit signal_getClassExamsReq(ui->comboBox_scoreClass->itemData(index).toString());
}

void menu_Teacher::on_btn_searchScores_clicked() {
    QString examCode = ui->comboBox_scoreExam->currentData().toString();
    if (examCode.isEmpty()) { QMessageBox::warning(this, "提示", "请先在上方选择一场考试！"); return; }
    emit signal_getExamScoresReq(examCode);
}

void menu_Teacher::on_btn_finishExam_clicked() {
    ui->lineEdit_examCode->clear();
    QMessageBox::information(this, "封卷成功", "本套试卷已成功锁定！\n如需出新卷子，请前往【组卷与发布】生成新考试码。");
}

#include <QMessageBox>
#include "mainmenuwidget.h"
#include "ui_mainmenuwidget.h"
#include "NetProtocol.h"

MainMenuWidget::MainMenuWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainMenuWidget)
{
    ui->setupUi(this);

    // 1. 左侧导航栏与右侧页面的丝滑联动
    connect(ui->listWidget, &QListWidget::currentRowChanged,
            ui->stackedWidget, &QStackedWidget::setCurrentIndex);

    // 2. 智能刷新机制：切到成绩页(索引2)就自动发包要成绩
    connect(ui->listWidget, &QListWidget::currentRowChanged, this, [this](int row){
        if (row == 2) emit signal_getScoresReq();
    });

    // 3. 集中初始化界面上所有的表格
    initTables();
}

MainMenuWidget::~MainMenuWidget() {
    delete ui;
}

// ==========================================
// 🏢 1. UI 初始化与辅助神器模块
// ==========================================
void MainMenuWidget::initTables() {
    // 初始化【我的班级】表格
    ui->tableWidget_myClasses->setColumnCount(3);
    ui->tableWidget_myClasses->setHorizontalHeaderLabels(QStringList() << "班级名称" << "指导教师" << "班级代码");
    ui->tableWidget_myClasses->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 初始化【成绩查询】表格
    ui->tableWidget_scores->setColumnCount(4);
    ui->tableWidget_scores->setHorizontalHeaderLabels(QStringList() << "考试科目" << "考试码" << "最终得分" << "交卷时间");
    ui->tableWidget_scores->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

//自动填表函数
void MainMenuWidget::appendTableRow(QTableWidget *table, const QStringList &texts) {
    int row = table->rowCount();
    table->insertRow(row);
    for (int i = 0; i < texts.size(); ++i) {
        QTableWidgetItem *item = new QTableWidgetItem(texts[i]);
        item->setTextAlignment(Qt::AlignCenter);
        table->setItem(row, i, item);
    }
}

// ==========================================
// 🏢 2. 外部接口模块 (供大管家操控)
// ==========================================
void MainMenuWidget::updateUserName(QString name) {
    ui->Username->setText(name);
}

void MainMenuWidget::updateTimeLabel(QString time) {
    if (ui->LabelTime) ui->LabelTime->setText(time);
}

// ==========================================
// 🏢 3. 玩家主动操作交互模块
// ==========================================
void MainMenuWidget::on_btn_joinExam_clicked() {
    QString code = ui->lineEdit_examCode->text().trimmed();
    if (code.isEmpty()) { QMessageBox::warning(this, "提示", "请输入考试码！"); return; }
    emit signal_joinExamReq(code);
}

void MainMenuWidget::on_btn_joinClass_clicked() {
    QString code = ui->lineEdit_classCode->text().trimmed();
    if (code.isEmpty()) { QMessageBox::warning(this, "提示", "班级邀请码不能为空！"); return; }
    emit signal_joinClassReq(code);
}

void MainMenuWidget::on_btn_confirm_clicked() {
    QString oldPwd = ui->lineEdit_oldPwd->text();
    QString newPwd = ui->lineEdit_newPwd->text();
    QString confirmPwd = ui->lineEdit_Conform->text();

    if (oldPwd.isEmpty() || newPwd.isEmpty() || confirmPwd.isEmpty()) {
        QMessageBox::warning(this, "提示", "密码不能为空！"); return;
    }
    if (newPwd != confirmPwd) {
        QMessageBox::warning(this, "提示", "两次输入的新密码不一致，请重新输入！"); return;
    }
    emit signal_changePwdReq(oldPwd, newPwd);
}

void MainMenuWidget::on_logoutBtn_clicked() {
    if (QMessageBox::question(this, "退出确认", "确定要注销并退出当前账号吗？") == QMessageBox::Yes) {
        emit signal_LogoutData();
        emit signal_callbackLoginMenu();
    }
}

// ==========================================
// 🏢 4. 服务器回执被动响应模块
// ==========================================
void MainMenuWidget::handleJoinExamResult(bool success, QString msg, QString subject, int duration) {
    if (success) {
        QMessageBox::information(this, "进入考场", msg + "\n科目：" + subject + "\n考试时长：" + QString::number(duration) + "分钟");
        QString realCode = ui->lineEdit_examCode->text().trimmed();
        emit signal_gotoTestPage(realCode);

        ui->lineEdit_examCode->clear(); // UX优化：进考场后把大厅的输入框清空
    } else {
        QMessageBox::warning(this, "进场失败", msg);
    }
}

void MainMenuWidget::handleScoresResult(const QJsonObject &data) {
    ui->tableWidget_scores->setRowCount(0); // 清空旧数据
    QJsonArray array = data["scores"].toArray();

    if (array.isEmpty()) {
        QMessageBox::information(this, "提示", "你还没有参加过任何考试哦！快去考一场吧！");
        return;
    }

    for (int i = 0; i < array.size(); ++i) {
        QJsonObject obj = array[i].toObject();
        QString subject = obj["subject"].toString();
        if (subject.isEmpty()) subject = "未知科目";

        appendTableRow(ui->tableWidget_scores, QStringList()
                                                   << subject
                                                   << obj["exam_code"].toString()
                                                   << QString::number(obj["score"].toInt())
                                                   << obj["submit_time"].toString());
    }
}

void MainMenuWidget::handleJoinClassResult(bool success, QString msg) {
    if (success) {
        QMessageBox::information(this, "加入成功", msg);
        ui->lineEdit_classCode->clear();
        emit signal_getMyClassesReq();
    } else {
        QMessageBox::warning(this, "加入失败", msg);
    }
}

void MainMenuWidget::handleGetMyClassesResult(QJsonArray classes) {
    ui->tableWidget_myClasses->setRowCount(0);

    for (int i = 0; i < classes.size(); ++i) {
        QJsonObject obj = classes[i].toObject();
        appendTableRow(ui->tableWidget_myClasses, QStringList()
                                                      << obj["class_name"].toString()
                                                      << obj["teacher_name"].toString()
                                                      << obj["class_code"].toString());
    }
}

void MainMenuWidget::handleChangePwdResult(bool success, QString msg) {
    if (success) {
        QMessageBox::information(this, "修改成功", msg);
        ui->lineEdit_oldPwd->clear();
        ui->lineEdit_newPwd->clear();
        ui->lineEdit_Conform->clear();

        emit signal_LogoutData();
        emit signal_callbackLoginMenu();
    } else {
        QMessageBox::warning(this, "修改失败", msg);
    }
}

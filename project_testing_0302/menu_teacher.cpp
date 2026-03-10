#include "menu_teacher.h"
#include "ui_menu_teacher.h"

menu_Teacher::menu_Teacher(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::menu_Teacher)
{
    ui->setupUi(this);
    ui->tableWidget_classes->setColumnCount(2);
    ui->tableWidget_classes->setHorizontalHeaderLabels(QStringList() << "班级名称" << "班级邀请码");
    ui->tableWidget_classes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 让这两列自动拉伸填满整个表格
    // 强制初始化 Page 1 学生名单表格的列数和表头
    ui->tableWidget_students->setColumnCount(1);
    ui->tableWidget_students->setHorizontalHeaderLabels(QStringList() << "学生账号");
    ui->tableWidget_students->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget_scores->setColumnCount(3);
    ui->tableWidget_scores->setHorizontalHeaderLabels(QStringList() << "学生账号" << "考试分数" << "交卷时间");
    ui->tableWidget_scores->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 默认展开所有树节点（让老师一进来就能看到所有功能）
    ui->treeWidget_nav->expandAll();

    // 核心路由逻辑：监听树形菜单的点击动作
    connect(ui->treeWidget_nav, &QTreeWidget::itemClicked, this, [this](QTreeWidgetItem *item, int column){

        // 1. 获取老师刚才点击的那个选项的文字
        QString text = item->text(0);

        // 2. 如果点击的是“大类”（也就是底下还有子节点的项），就只做展开/折叠，不切页面
        if (item->childCount() > 0) {
            item->setExpanded(!item->isExpanded());
            return;
        }

        // 3. 如果点击的是“小类”，就开始智能匹配文字，切换到对应的 page 索引
        // ⚠️ 注意：这里的索引 (0, 1, 2...) 必须和你在右侧 StackedWidget 里建的 page 顺序完全对应！
        if (text == "创建班级") {
            ui->stackedWidget->setCurrentIndex(0);
        }
        else if (text == "学生名单") {
            ui->stackedWidget->setCurrentIndex(1);
        }
        else if (text == "录入题目") {
            ui->stackedWidget->setCurrentIndex(2);
        }
        else if (text == "组卷与发布") {
            ui->stackedWidget->setCurrentIndex(3);
        }
        else if (text == "班级成绩总榜") {
            ui->stackedWidget->setCurrentIndex(4);
        }
        else if (text == "修改密码") {
            ui->stackedWidget->setCurrentIndex(5);
        }
        else if (text == "安全退出") {
            // 这里不需要切页面，直接弹窗确认并退出
            int ret = QMessageBox::question(this, "退出确认", "确定要退出教师系统吗？");
            if (ret == QMessageBox::Yes) {
                emit signal_logoutReq(); // 以后咱们在这里发信号让大管家退回登录页
                qDebug() << "老师点击了安全退出！";
            }
        }
    });
}

menu_Teacher::~menu_Teacher()
{
    delete ui;
}

void menu_Teacher::on_btn_createClass_clicked()
{
    // 1. 拿到输入框里的字，顺便去掉两头多余的空格
    QString className = ui->lineEdit_className->text().trimmed();

    // 2. 防呆校验：如果不输入名字就点按钮，直接拦截
    if (className.isEmpty()) {
        QMessageBox::warning(this, "提示", "班级名称不能为空！");
        return;
    }

    // 3. 名字没问题，通过刚刚建的信号把名字扔给大管家
    emit signal_createClassReq(className);
}

void menu_Teacher::handleCreateClassResult(bool success, QString msg) {
    if (success) {
        QMessageBox::information(this, "创建结果", msg);
        ui->lineEdit_className->clear();

        // 👇 加上这一句极其关键的代码！建班成功后，立刻向大管家要最新数据！
        emit signal_getClassesReq();

    } else {
        QMessageBox::warning(this, "创建失败", msg);
    }
}

void menu_Teacher::handleGetClassesResult(QJsonArray classes) {
    // 1. 清空旧数据
    ui->comboBox_scoreClass->clear();
    ui->comboBox_scoreClass->addItem("🌍 全网公开（任何人凭码可考）", "");
    ui->tableWidget_classes->setRowCount(0);
    ui->comboBox_myClasses->clear();
    ui->comboBox_examClass->clear(); // 👈 新增 1：清空咱们刚画的“发布范围”下拉框

    // 👇 新增 2：给“发布范围”加上第一个默认神级选项！隐藏的 code 设为空字符串 ""
    ui->comboBox_examClass->addItem("🌍 全网公开（任何人凭码可考）", "");

    // 2. 遍历发回来的班级数组
    for(int i = 0; i < classes.size(); ++i) {
        QJsonObject obj = classes[i].toObject();
        QString name = obj["class_name"].toString();
        QString code = obj["class_code"].toString();

        // ---- 填 Page 0 的表格 ----
        int row = ui->tableWidget_classes->rowCount();
        ui->tableWidget_classes->insertRow(row);
        ui->tableWidget_classes->setItem(row, 0, new QTableWidgetItem(name));
        ui->tableWidget_classes->setItem(row, 1, new QTableWidgetItem(code));
        ui->comboBox_scoreClass->addItem(name, code);

        // ---- 填 Page 1 和 Page 3 的下拉框 ----
        ui->comboBox_myClasses->addItem(name, code);
        ui->comboBox_examClass->addItem(name, code); // 👈 新增 3：把班级也同步塞进 Page 3 的下拉框里！
    }
}

void menu_Teacher::on_btn_searchStudents_clicked() // 你的按钮名字可能不一样，用你实际生成的
{
    // 🪄 核心魔法：拿到下拉框当前选中项背后“隐藏”的 6 位 class_code！
    QString code = ui->comboBox_myClasses->currentData().toString();

    if(code.isEmpty()) {
        QMessageBox::warning(this, "提示", "请先选择一个有效的班级！");
        return;
    }

    // 把班级码扔给大管家
    emit signal_getClassStudentsReq(code);
}

void menu_Teacher::handleGetClassStudentsResult(QJsonArray students) {
    // 1. 清空旧数据
    ui->tableWidget_students->setRowCount(0);

    // 2. 遍历学生数组，一行行填进表格
    for(int i = 0; i < students.size(); ++i) {
        QJsonObject obj = students[i].toObject();
        QString studentName = obj["username"].toString();

        int row = ui->tableWidget_students->rowCount();
        ui->tableWidget_students->insertRow(row);
        ui->tableWidget_students->setItem(row, 0, new QTableWidgetItem(studentName));
    }
}

void menu_Teacher::on_btn_addQuestion_clicked() // 使用你实际的按钮名字
{
    QString code = ui->lineEdit_examCode->text().trimmed();
    QString question = ui->textEdit_question->toPlainText().trimmed(); // 注意多行文本框是用 toPlainText()
    QString optA = ui->lineEdit_optA->text().trimmed();
    QString optB = ui->lineEdit_optB->text().trimmed();
    QString optC = ui->lineEdit_optC->text().trimmed();
    QString optD = ui->lineEdit_optD->text().trimmed();
    QString answer = ui->comboBox_answer->currentText();

    // 基础防呆：啥都不填不准提交
    if(code.isEmpty() || question.isEmpty() || optA.isEmpty() || optB.isEmpty() || optC.isEmpty() || optD.isEmpty()) {
        QMessageBox::warning(this, "提示", "请将考试码、题目和选项填写完整！");
        return;
    }

    QJsonObject qData;
    qData["exam_code"] = code;
    qData["question_text"] = question;
    qData["option_A"] = optA;
    qData["option_B"] = optB;
    qData["option_C"] = optC;
    qData["option_D"] = optD;
    qData["correct_answer"] = answer;

    emit signal_addQuestionReq(qData);
}

void menu_Teacher::handleAddQuestionResult(bool success, QString msg) {
    if (success) {
        QMessageBox::information(this, "成功", msg);

        // 👇 UX 核心逻辑：清空题目和选项，唯独保留第一行的“考试码”！
        ui->textEdit_question->clear();
        ui->lineEdit_optA->clear();
        ui->lineEdit_optB->clear();
        ui->lineEdit_optC->clear();
        ui->lineEdit_optD->clear();
        ui->comboBox_answer->setCurrentIndex(0); // 恢复下拉框到第一个选项(A)

        // 让鼠标光标自动跳回题干输入框，老师可以直接双手不离键盘敲下一题！
        ui->textEdit_question->setFocus();
    } else {
        QMessageBox::warning(this, "失败", msg);
    }
}

void menu_Teacher::on_btn_generateExam_clicked() // 确认是你的按钮名字
{
    // 🪄 核心魔法：提取隐藏在下拉框背后的“班级码” (如果是全网公开，提取出来的就是 "")
    QString classCode = ui->comboBox_examClass->currentData().toString();
    QString subject = ui->lineEdit_subject->text().trimmed();
    int duration = ui->spinBox_duration->value();

    // 防呆校验
    if (subject.isEmpty()) {
        QMessageBox::warning(this, "提示", "考试科目不能为空！");
        return;
    }
    if (duration <= 0) {
        QMessageBox::warning(this, "提示", "考试时间必须大于0分钟！");
        return;
    }

    // 打包发走
    QJsonObject reqData;
    reqData["class_code"] = classCode;
    reqData["subject"] = subject;
    reqData["duration"] = duration;

    emit signal_publishExamReq(reqData);
}

void menu_Teacher::handlePublishExamResult(bool success, QString msg, QString examCode) {
    if (success) {
        // 1. 在那个大 Label 上极其醒目地展示 6 位考试码！
        ui->label_examCodeDisplay->setText(examCode);
        // 顺手给它上个色，让它看起来更高级（比如番茄红）
        ui->label_examCodeDisplay->setStyleSheet("color: #E74C3C; font-weight: bold; font-size: 28px;");

        QMessageBox::information(this, "生成成功", "考试码已生成！\n请复制该码，并前往左侧【录入题目】界面为该考试加题。");
    } else {
        QMessageBox::warning(this, "生成失败", msg);
    }
}

void menu_Teacher::on_comboBox_scoreClass_currentIndexChanged(int index) // 确认名字对不对
{
    // 防呆：如果是清空下拉框触发的，直接跳过
    if (index < 0) return;

    // 拿到当前选中的班级码，扔给大管家去查考试
    QString classCode = ui->comboBox_scoreClass->itemData(index).toString();
    emit signal_getClassExamsReq(classCode);
}

void menu_Teacher::handleGetClassExamsResult(QJsonArray exams) {
    ui->comboBox_scoreExam->clear(); // 先清空旧的考试

    for(int i = 0; i < exams.size(); ++i) {
        QJsonObject obj = exams[i].toObject();
        QString code = obj["exam_code"].toString();
        QString subject = obj["subject"].toString();

        // 👇 核心绝招：把考试码直接拼在标题上显示给老师看！同时把纯净的 code 藏在背后！
        QString displayText = QString("%1 (码: %2)").arg(subject).arg(code);
        ui->comboBox_scoreExam->addItem(displayText, code);
    }
}

void menu_Teacher::on_btn_searchScores_clicked() // 确认名字对不对
{
    // 拿到隐藏在考试下拉框背后的 6 位真实考试码
    QString examCode = ui->comboBox_scoreExam->currentData().toString();

    if (examCode.isEmpty()) {
        QMessageBox::warning(this, "提示", "请先在上方选择一场考试！");
        return;
    }

    // 扔给大管家去要成绩
    emit signal_getExamScoresReq(examCode);
}

void menu_Teacher::handleGetExamScoresResult(QJsonArray scores) {
    ui->tableWidget_scores->setRowCount(0); // 清空旧数据

    for (int i = 0; i < scores.size(); ++i) {
        QJsonObject obj = scores[i].toObject();
        QString username = obj["username"].toString();
        QString score = QString::number(obj["score"].toInt());
        QString submitTime = "已交卷"; // 咱们之前如果没存交卷时间，就写个占位符，看着也霸气！

        int row = ui->tableWidget_scores->rowCount();
        ui->tableWidget_scores->insertRow(row);
        ui->tableWidget_scores->setItem(row, 0, new QTableWidgetItem(username));

        // 分数这一列搞点特殊待遇
        QTableWidgetItem* scoreItem = new QTableWidgetItem(score + " 分");
        scoreItem->setForeground(QBrush(QColor("#E74C3C"))); // 给分数标个醒目的红色
        ui->tableWidget_scores->setItem(row, 1, scoreItem);

        ui->tableWidget_scores->setItem(row, 2, new QTableWidgetItem(submitTime));
    }
}

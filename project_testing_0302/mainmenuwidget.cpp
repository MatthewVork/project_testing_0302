#include "mainmenuwidget.h"
#include "ui_mainmenuwidget.h"
#include "NetProtocol.h"

MainMenuWidget::MainMenuWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainMenuWidget)
{
    ui->setupUi(this);
    connect(ui->listWidget, &QListWidget::currentRowChanged,
            ui->stackedWidget, &QStackedWidget::setCurrentIndex);

    connect(ui->listWidget, &QListWidget::currentRowChanged, this, [this](int row){
        // ⚠️ 注意：这里的 row 是左侧列表的索引（从 0 开始算）
        // 按照你截图里的顺序："考试大厅"(0), "我的考试"(1), "成绩查询"(2)
        // 如果你的“成绩查询”排在第 3 位，那它的索引就是 2。你可以根据实际情况调整这个数字！
        if (row == 2) {
            emit signal_getScoresReq(); // 发现切到了成绩页，瞬间自动发信号去拉取成绩！
        }
    });

}

MainMenuWidget::~MainMenuWidget()
{
    delete ui;
}

void MainMenuWidget::updateUserName(QString name)
{
    ui->Username->setText(name);
}

void MainMenuWidget::on_logoutBtn_clicked()
{
    emit signal_LogoutData();
    emit signal_callbackLoginMenu();
}

void MainMenuWidget::updateTimeLabel(QString time) {
    if (ui->LabelTime) { //防止段错误
        ui->LabelTime->setText(time);
    } else {
        qDebug() << "警告：找不到 LabelTime 组件！";
    }
}

void MainMenuWidget::on_btn_joinExam_clicked()
{
    // 获取输入框里的内容，去掉首尾空格
    QString code = ui->lineEdit_examCode->text().trimmed();

    if (code.isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入考试码！");
        return;
    }

    // 把考试码通过信号发给 MainWindow，让它去走网络发送
    emit signal_joinExamReq(code);
}

void MainMenuWidget::handleJoinExamResult(bool success, QString msg, QString subject, int duration) {
    if (success) {
        // 验证成功！弹窗提示
        QMessageBox::information(this, "进入考场",
                                 msg + "\n科目：" + subject + "\n考试时长：" + QString::number(duration) + "分钟");

        // 以后就在这里发射一个信号给 MainWindow，让它把 StackedWidget 切到第 3 页（答题页）
        emit signal_gotoTestPage();
    } else {
        // 验证失败（比如输错了考试码）
        QMessageBox::warning(this, "进场失败", msg);
    }
}

// 接收到服务器发来的成绩单后，弹窗展示
// 接收到服务器发来的成绩单后，填入表格展示
void MainMenuWidget::handleScoresResult(const QJsonObject &data) {
    QJsonArray array = data["scores"].toArray();

    // 1. 初始化表格的列数和表头文字
    ui->tableWidget_scores->setColumnCount(4);
    ui->tableWidget_scores->setHorizontalHeaderLabels(QStringList() << "考试科目" << "考试码" << "最终得分" << "交卷时间");

    // 让表格的列宽自动拉伸填满空白
    ui->tableWidget_scores->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 2. 根据服务器发来的成绩数量，动态设置表格有多少行
    ui->tableWidget_scores->setRowCount(array.size());

    if (array.isEmpty()) {
        QMessageBox::information(this, "提示", "你还没有参加过任何考试哦！快去考一场吧！");
        return;
    }

    // 3. 循环遍历，把成绩一行一行填进表格里
    for(int i = 0; i < array.size(); ++i) {
        QJsonObject obj = array[i].toObject();
        QString subject = obj["subject"].toString();
        if(subject.isEmpty()) subject = "未知科目"; // 防御性处理

        QString code = obj["exam_code"].toString();
        QString scoreStr = QString::number(obj["score"].toInt());
        QString timeStr = obj["submit_time"].toString();

        // 生成每一格的数据
        QTableWidgetItem *itemSubject = new QTableWidgetItem(subject);
        QTableWidgetItem *itemCode = new QTableWidgetItem(code);
        QTableWidgetItem *itemScore = new QTableWidgetItem(scoreStr);
        QTableWidgetItem *itemTime = new QTableWidgetItem(timeStr);

        // 让文字居中显示（强迫症福音）
        itemSubject->setTextAlignment(Qt::AlignCenter);
        itemCode->setTextAlignment(Qt::AlignCenter);
        itemScore->setTextAlignment(Qt::AlignCenter);

        // 塞进第 i 行对应的列里 (0列:科目, 1列:考试码, 2列:分数)
        ui->tableWidget_scores->setItem(i, 0, itemSubject);
        ui->tableWidget_scores->setItem(i, 1, itemCode);
        ui->tableWidget_scores->setItem(i, 2, itemScore);
        ui->tableWidget_scores->setItem(i, 3, itemTime);
    }
}

// 玩家点击大厅 page2 里的“修改密码”按钮
void MainMenuWidget::on_btn_confirm_clicked() {
    // 1. 拿取你界面上三个输入框的值（严格匹配了你的 Conform 拼写）
    QString oldPwd = ui->lineEdit_oldPwd->text();
    QString newPwd = ui->lineEdit_newPwd->text();
    QString confirmPwd = ui->lineEdit_Conform->text();

    // 2. 基础防呆校验
    if (oldPwd.isEmpty() || newPwd.isEmpty() || confirmPwd.isEmpty()) {
        QMessageBox::warning(this, "提示", "密码不能为空！");
        return;
    }
    if (newPwd != confirmPwd) {
        QMessageBox::warning(this, "提示", "两次输入的新密码不一致，请重新输入！");
        return;
    }

    // 3. 没问题了，把旧密码和新密码打包发出去
    emit signal_changePwdReq(oldPwd, newPwd);
}

// 收到服务器修改结果后
void MainMenuWidget::handleChangePwdResult(bool success, QString msg) {
    if (success) {
        QMessageBox::information(this, "修改成功", msg);

        // 清空输入框的内容
        ui->lineEdit_oldPwd->clear();
        ui->lineEdit_newPwd->clear();
        ui->lineEdit_Conform->clear();

        //密码改完，强制发一个下线包给服务器，清空在线状态
        emit signal_LogoutData();
        // 密码改了，发信号让 MainWindow 强制切回登录页！
        emit signal_callbackLoginMenu();
    } else {
        QMessageBox::warning(this, "修改失败", msg);
    }
}

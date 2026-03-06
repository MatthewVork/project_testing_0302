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

// 考生点击“查询历史成绩”按钮
void MainMenuWidget::on_btn_history_clicked() {
    emit signal_getScoresReq(); // 发信号给大管家，让他去跑腿
}

// 接收到服务器发来的成绩单后，弹窗展示
void MainMenuWidget::handleScoresResult(const QJsonObject &data) {
    QJsonArray array = data["scores"].toArray();

    if (array.isEmpty()) {
        QMessageBox::information(this, "历史成绩", "你还没有参加过任何考试哦！快去考一场吧！");
        return;
    }

    // 拼接成绩单文本
    QString msg = "你的历史考试成绩如下：\n\n";
    for(int i = 0; i < array.size(); ++i) {
        QJsonObject obj = array[i].toObject();
        QString subject = obj["subject"].toString();
        if(subject.isEmpty()) subject = "未知科目"; // 防御性处理

        msg += QString("📚 科目：%1 (代码:%2)\n   🏆 得分：%3 分\n\n")
                   .arg(subject)
                   .arg(obj["exam_code"].toString())
                   .arg(obj["score"].toInt());
    }

    QMessageBox::information(this, "历史成绩", msg);
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

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


#include <QMessageBox>
#include <QTimer>

#include "loginwidget.h"
#include "ui_loginwidget.h"

QString LoginUsername = "123";
QString LoginPassword = "123";

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    // 连接按钮点击事件。注意：请务必确认 Designer 里的 objectName 确实是 pushButton_Register
    connect(ui->pushButton_Login, &QPushButton::clicked, this, [this]() {
        check_login();  //检查信号
    });

    connect(ui->pushButton_Register, &QPushButton::clicked, this, [this](){
        emit signal_showRegister(); // 发射信号
    });
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::check_login()
{
    if(ui->Username->text() == LoginUsername)
    {
        // 1. 创建一个临时的弹窗对象（不要用静态方法）
        QMessageBox *autoCloseBox = new QMessageBox(this);
        autoCloseBox->setWindowTitle("登录成功");
        autoCloseBox->setText("验证通过，正在进入系统...");
        autoCloseBox->setIcon(QMessageBox::Information);

        // 去掉标准按钮，让它看起来更像一个纯提示栏（可选）
        autoCloseBox->setStandardButtons(QMessageBox::NoButton);

        // 2. 显示弹窗（非阻塞方式）
        autoCloseBox->show();

        // 3. 核心：设置一个 2 秒（2000毫秒）后的定时任务
        QTimer::singleShot(2000, autoCloseBox, [autoCloseBox, this]() {
            autoCloseBox->close();      // 关闭弹窗
            autoCloseBox->deleteLater(); // 销毁内存（非常重要！）

            // 这里写你下一步的逻辑，比如跳转到考试界面
            // emit signal_enterExam();
        });
    }
    else
    {
        QMessageBox::information(this, "登录失败", "请重新输入密码，" + LoginUsername);
    }
}

#include <QMessageBox>
#include <QTimer>
#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "NetProtocol.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
}

LoginWidget::~LoginWidget() {
    delete ui;
}

// ==========================================
// 🏢 1. UI 按钮交互逻辑
// ==========================================
void LoginWidget::on_loginBtn_clicked() {
    // 把两头的空格去除
    QString user = ui->Username->text().trimmed();
    QString pwd = ui->Password->text().trimmed();

    if (user.isEmpty() || pwd.isEmpty()) {
        QMessageBox::warning(this, "错误", "缺少登录信息，请重新输入！");
        return; // 👈 必须斩断后路！严禁向下执行发包！
    }

    //打包逻辑
    QByteArray plainData = NetProtocol::packUserAndPass(MSG_LOGIN, user, pwd);
    emit SecureData(NetProtocol::encrypt(plainData));
}

void LoginWidget::on_registerBtn_clicked() {
    emit signal_showRegister();
}

// ==========================================
// 🏢 2. 处理服务器下发的登录回执
// ==========================================
void LoginWidget::handleLoginResult(bool success, QString msg, int role) {
    if (success) {
        QMessageBox *autoCloseBox = new QMessageBox(this);
        autoCloseBox->setWindowTitle("登录成功");
        autoCloseBox->setText("验证通过，正在进入系统...");
        autoCloseBox->setIcon(QMessageBox::Information);
        autoCloseBox->setStandardButtons(QMessageBox::NoButton);
        autoCloseBox->show();

        // 提前把用户名发给大厅准备好
        emit signal_RecordUsername(ui->Username->text());

        // 1秒后自动关闭弹窗，并通知大管家切页面
        QTimer::singleShot(1000, autoCloseBox, [this, autoCloseBox, role]() {
            autoCloseBox->close();
            autoCloseBox->deleteLater();

            ui->Username->clear(); // 极其贴心的 UX：清空输入框，防止注销退回登录页时账号密码还在
            ui->Password->clear();

            emit signal_LoginSuccess(role); // 告诉大管家：切页面！
        });
    } else {
        QMessageBox::warning(this, "登录失败", msg);
        ui->Password->clear(); // UX 细节：密码错误只清空密码，保留用户名！
    }
}

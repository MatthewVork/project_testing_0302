#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include <QWidget>
#include <QByteArray>

namespace Ui {
class RegisterWidget;
}

class RegisterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWidget(QWidget *parent = nullptr);
    ~RegisterWidget();

    // ================= 供大管家调用的接口 =================
    void handleRegisterResult(bool success, QString msg);

signals:
    // ================= 向外发射的信号 =================
    void signal_CallbackLoginwidget();           // 切回登录页
    void signal_RegisterData(const QByteArray &data);  // 发送打包数据

private slots:
    // ================= UI 交互 =================
    void on_registerBtn_clicked();
    void on_backBtn_clicked();

private:
    Ui::RegisterWidget *ui;
};

#endif // REGISTERWIDGET_H

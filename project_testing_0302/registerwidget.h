#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include <QWidget>

namespace Ui {
class RegisterWidget;
}

class RegisterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWidget(QWidget *parent = nullptr);
    ~RegisterWidget();

public slots:
    void on_registerBtn_clicked();
    void on_backBtn_clicked();
    void handleRegisterResult(bool success, QString msg);

signals:
    void signal_CallbackLoginwidget();
    void signal_RegisterData(QByteArray);


private:
    Ui::RegisterWidget *ui;
};

#endif // REGISTERWIDGET_H

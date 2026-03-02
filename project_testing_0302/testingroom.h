#ifndef TESTINGROOM_H
#define TESTINGROOM_H

#include <QWidget>

namespace Ui {
class TestingRoom;
}

class TestingRoom : public QWidget
{
    Q_OBJECT

public:
    explicit TestingRoom(QWidget *parent = nullptr);
    ~TestingRoom();

private:
    Ui::TestingRoom *ui;
};

#endif // TESTINGROOM_H

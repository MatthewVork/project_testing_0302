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
                // emit signal_logoutReq(); // 以后咱们在这里发信号让大管家退回登录页
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
    // 1. 清空 Page 0 的表格 和 Page 1 的下拉框
    ui->tableWidget_classes->setRowCount(0);
    ui->comboBox_myClasses->clear(); // 👈 新增：清空下拉框旧数据

    // 2. 遍历发回来的班级数组
    for(int i = 0; i < classes.size(); ++i) {
        QJsonObject obj = classes[i].toObject();
        QString name = obj["class_name"].toString();
        QString code = obj["class_code"].toString();

        // ---- 填 Page 0 的表格 (你原来写的代码) ----
        int row = ui->tableWidget_classes->rowCount();
        ui->tableWidget_classes->insertRow(row);
        ui->tableWidget_classes->setItem(row, 0, new QTableWidgetItem(name));
        ui->tableWidget_classes->setItem(row, 1, new QTableWidgetItem(code));

        // ---- 👇 新增：填 Page 1 的下拉框 ----
        // 神仙操作：明面上显示班级名字 (name)，暗地里把班级码 (code) 绑在它身上！
        ui->comboBox_myClasses->addItem(name, code);
    }
}

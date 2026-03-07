#include "menu_teacher.h"
#include "ui_menu_teacher.h"
#include "NetProtocol.h"

menu_Teacher::menu_Teacher(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::menu_Teacher)
{
    ui->setupUi(this);

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

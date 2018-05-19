#include "popstargame.h"
#include "ui_popstargame.h"
#include<QMessageBox>
PopStarGame::PopStarGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopStarGame)
{
    ui->setupUi(this);
    m_Dialog=NULL;
    m_pixBK=NULL;


    InitCtrls();
}

PopStarGame::~PopStarGame()
{
    delete ui;
}
// 初始化控件函数
void PopStarGame::InitCtrls()
{
    // 设置窗口风格
    this->setWindowTitle("PopStar3.0");
    this->setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);

    // 加载背景图片
    m_pixBK=new QPixmap(382,514);
    m_pixBK->load(":/new/prefix1/res/StarGame.bmp");

    // 动态申请游戏窗口
    m_Dialog=new Dialog(this);
    m_bSart=true;

    //  设置按钮透明
    ui->btn_StartGame->setStyleSheet("background:transparent;border-with:0;border-style:outset;");
    ui->btn_GameInstruction->setStyleSheet("background:transparent;border-with:0;border-style:outset;");
    ui->btn_GameVersion->setStyleSheet("background:transparent;border-with:0;border-style:outset;");
    ui->btn_ExitGame->setStyleSheet("background:transparent;border-with:0;border-style:outset;");
}
// 绘图函数
void PopStarGame::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,382,514,*m_pixBK);
}
// 关闭窗口事件
void PopStarGame::closeEvent(QCloseEvent *e)
{

}
// 开始游戏
void PopStarGame::on_btn_StartGame_clicked()
{
    if(NULL==m_Dialog)
    {
        m_Dialog=new Dialog(this);
        m_Dialog->exec();
    }
    else
    {
         m_Dialog->exec();
    }
    delete m_Dialog;
    m_Dialog=NULL;

    /*
    if(m_bSart)
    {
        if(NULL==m_Dialog)
        {
            m_Dialog=new Dialog(this);

        }
        m_Dialog->exec();
        delete m_Dialog;
        m_Dialog=NULL;
        m_bSart=false;
    }
    else
    {
        if(m_Dialog!=NULL)
        {
            delete m_Dialog;
            m_Dialog=NULL;
        }
        m_Dialog=new Dialog(this);
        m_Dialog->exec();
        delete m_Dialog;
        m_Dialog=NULL;
        m_bSart=true;
    }
*/
}
// 游戏介绍
void PopStarGame::on_btn_GameInstruction_clicked()
{
    QString strText="消灭星星是目前各种平台上一款非常火爆的游戏，游戏主要就是鼠标点击图中的星星然后相邻的星星然后消除，上方的星星则落下来，如果一列的消完之后则整列都会向右移动.\n"
                    "每一次消灭的星星越多，得分越高。每关的得分只要超过了目标分数就会过关。如果每关最后剩余的星星没有可消灭的连在一块的并且分数没有过关则失败.\n"
                    "若果过关之后，最后没有星星剩余，则做奖励.";
    QMessageBox::information(this,"应用程序提示",strText,tr("确定"));
}
// 游戏版本.
void PopStarGame::on_btn_GameVersion_clicked()
{
    QString strText="PopStar3.0 游戏版权归ARRAYLI所拥有，任何人不得用于商业用途,不得侵权.\n"
                    "若您在操作的过程，发现任何Bug，请及时向ARRAYLI反馈。ARRAYLI将对其本版进行升级.";
    QMessageBox::information(this,"应用程序提示",strText,tr("确定"));
}
// 退出游戏
void PopStarGame::on_btn_ExitGame_clicked()
{
    int res=QMessageBox::question(this,"应用程序提示","您确定要退出游戏吗？",tr("确定"),tr("取消"),0,1);
    if(res==0)
    {
        this->close();
        delete m_Dialog;
        m_Dialog=NULL;

    }
}

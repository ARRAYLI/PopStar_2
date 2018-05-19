#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "star.h"

#include<QPixmap>
#include<QDateTime>
#include<QPainter>
#include<QMouseEvent>
#include<QRect>
#include "bluestar.h"
#include "greenstar.h"
#include "redstar.h"
#include "yellowstatr.h"
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include "musicthrd.h"
#include "videothrd.h"

const int LEN=10;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    struct StarArray
    {
        int data;       // 存放星星的数据
        bool    willRemove;     // 是否是将要要删除  true 将要删除   false 不被删除
    };
public:
    void StarGame();        // 开始游戏
    void ExitGame();        // 退出游戏
private:
    void InitCtrls();       // 初始化控件
    void InitData();        // 初始化数据
    void Srand();           // 产生随机数，给数组赋值
    void DrawStar();        // 画星星

    int  GetIndexY(int yPos);        // 获取当前鼠标位置的y下标
    int  GetIndexX(int xPos);       // 获取当前鼠标位置的x下标
    void ChangeIndex(QPoint e);             // 转换星星数组下标
    void CheckMoveStar(int x,int y,int &count);          // 查找将要删除的星星消灭星星

    void KillStar();            // 消灭星星
    bool   CheckMove(int col);         // 检查是否下落
    void StarDown();                // 星星下落
    bool  CheckGameOver();          // 检查游戏是否结束
    int   findWillRemove(int x,int y);      // 寻找将被移除的星星
    int   findMaxRightCol();            // 找到最右边的空列号
    void  MoveCol();                    // 把空列向右移动
    bool  JudgeColBlank(int col);              // 判断该列是否为空列
    int   GetBlankCol();                // 获取空列个数

    int GetScoreSeg(int count);     // 获取消灭星星的分数段
    int  SetGradeSocre(int grade);      // 设置关数的目标分数
    bool    JudgeSuccNext();            // 判断是否进入下一关
    int   CaclCurrScore(int count);              // 计算当前分数
    void ShowScoreGUI(int count);            // 显示分数界面
    void InitMedia();       // 初始化媒体资源

protected:
    void paintEvent(QPaintEvent *e);        // 窗口绘制事件
    void mousePressEvent(QMouseEvent *e);       // 鼠标按下事件
    void mouseMoveEvent(QMouseEvent *e);        // 鼠标移动事件
    void closeEvent(QCloseEvent *e);        //窗口关闭事件
    void sleep(unsigned int msec);     // 主线程等待子线程不阻塞函数
private slots:
    void on_btn_Vedio_clicked();

    void on_btn_Music_clicked();

private:
    Ui::Dialog *ui;
    StarArray  m_arrayStar[LEN][LEN];        //记录星星的数组  0 无星星 1 red  2 green 3 blue 4 yellow
    QPixmap  *m_pixBK;                  // 背景图片
    QPixmap   *m_pixMusicUp;              // 音乐打开图片
    QPixmap   *m_pixMusicDown;              // 音乐关闭图片
    QPixmap   *m_pixVoiceUp;              // 声音打开图片
    QPixmap   *m_pixVoiceDown;              // 声音关闭图片
    int       m_Height;                 // 画布高度
    int       m_width;                  // 画布宽度
    RedStar  *m_rStar;                  // 红星星
    BlueStar  *m_BlueStar;   // 蓝星星
    YellowStatr *m_yStar;   // 黄星星
    GreenStar   *m_gStar;   // 绿星星
    int         m_Border;   // 星星距离顶部的距离
    int         m_starWidth;    // 星星的宽度
    int         m_starHeight;   // 星星的高度
    int         m_X;        // 鼠标位置在数组中所在横坐标位置
    int         m_Y;        // 鼠标位置在数组中所在纵坐标位置
    int         m_nCount;           // 记录相同星星的个数
    int         m_nGoalScore;       // 记录目标分数
    int         m_nCurrScore;       // 记录当前分数
    int         m_nTotalScore;      // 记录总分数
    int         m_nGrade;           // 记录等级
    int        m_bSuccGrade;       // 是否通关   1 通关  0 没有通关  -1 不显示
    bool        m_bMusic;           // true 音乐开着  false 音乐暂停
    bool        m_bVideo;           // true 声音开着  false 声音关闭

    MusicThrd   *m_MusicThrd;
    VideoThrd   *m_VedioThrd;
    QMediaPlayer    *m_MedVedi;
    QMediaPlaylist  *m_MedMusList;
    QMediaPlayer    *m_MedMusic;
    QMediaPlaylist  *m_MedVedList;
};

#endif // DIALOG_H

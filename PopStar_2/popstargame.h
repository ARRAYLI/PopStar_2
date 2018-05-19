#ifndef POPSTARGAME_H
#define POPSTARGAME_H

#include <QDialog>
#include "dialog.h"
#include<QPixmap>
#include<QPainter>
#include<QPaintEvent>

namespace Ui {
class PopStarGame;
}

class PopStarGame : public QDialog
{
    Q_OBJECT

public:
    explicit PopStarGame(QWidget *parent = 0);
    ~PopStarGame();
private:
    void InitCtrls();       // 初始化控件函数
protected:
    void paintEvent(QPaintEvent *e);        // 绘图函数
    void closeEvent(QCloseEvent *e);        // 关闭窗口事件
private slots:
    void on_btn_StartGame_clicked();        // 开始游戏

    void on_btn_GameInstruction_clicked();      //  游戏介绍

    void on_btn_GameVersion_clicked();          // 游戏版本

    void on_btn_ExitGame_clicked();         // 退出游戏

private:
    Ui::PopStarGame *ui;
    Dialog          *m_Dialog;
    QPixmap         *m_pixBK;       // 背景图片
    bool            m_bSart;        // 开始游戏
};

#endif // POPSTARGAME_H

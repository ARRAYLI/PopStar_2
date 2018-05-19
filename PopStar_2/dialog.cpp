#include "dialog.h"
#include "ui_dialog.h"
#include<QDebug>
#include<QMessageBox>
#include<QTime>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    m_Height=514;
    m_width=382;
    m_Border=137;
    m_starHeight=37;
    m_starWidth=37;

    m_nCurrScore=0;         // 当前分数刚开始为0分
    m_nGoalScore=1000;      // 第一关开始起目标分数为1000分
    m_nTotalScore=0;        // 总分刚开始为0分
    m_nGrade=1;             // 记录关数
    m_bSuccGrade=-1;     // 刚开始没有通关

    m_pixMusicUp=new QPixmap(61,51);
    m_pixMusicUp->load(":/new/prefix1/res/Up1.bmp");

    m_pixMusicDown=new QPixmap(61,51);
    m_pixMusicDown->load(":/new/prefix1/res/XUp1.bmp");

    m_pixVoiceUp=new QPixmap(61,51);
    m_pixVoiceUp->load(":/new/prefix1/res/bkUp1.bmp");

    m_pixVoiceDown=new QPixmap(61,51);
    m_pixVoiceDown->load(":/new/prefix1/res/bkDwon1.bmp");

    m_rStar=new RedStar;
    m_BlueStar=new BlueStar;
    m_yStar=new YellowStatr;
    m_gStar=new GreenStar;

    m_pixBK=new QPixmap(m_width,m_Height);
    m_pixBK->load(":/new/prefix1/res/BK.bmp");

    m_bMusic=true;
    m_bVideo=true;
    m_MedMusic=NULL;
    m_MedVedi=NULL;

    m_MusicThrd=NULL;
    m_VedioThrd=NULL;

    //设置窗口关闭时，所有对象销毁
 //   this->setAttribute(Qt::WA_DeleteOnClose,true);

    // 初始化媒体资源
    //  InitMedia();

    InitCtrls();
    InitData();
}

Dialog::~Dialog()
{
    if(m_MusicThrd!=NULL)
    {
        m_MusicThrd->quit();
       m_MusicThrd->wait();

        delete m_MusicThrd;
        m_MusicThrd=NULL;
    }
    if(m_VedioThrd!=NULL)
    {
        m_VedioThrd->quit();
        m_VedioThrd->wait();
        delete m_VedioThrd;
        m_VedioThrd=NULL;
    }
    delete ui;
}
  // 开始游戏
void Dialog::StarGame()
{
    m_nCurrScore=0;         // 当前分数刚开始为0分
    m_nGoalScore=1000;      // 第一关开始起目标分数为1000分
    m_nTotalScore=0;        // 总分刚开始为0分
    m_nGrade=1;             // 记录关数
    m_bSuccGrade=-1;     // 刚开始没有通关
    m_bMusic=true;
    m_bVideo=true;

    InitData();
    ShowScoreGUI(m_nCount);

}
   // 退出游戏
void Dialog::ExitGame()
{
    if(m_MusicThrd!=NULL)
    {
        m_MusicThrd->quit();
        m_MusicThrd->wait();

        delete m_MusicThrd;
        m_MusicThrd=NULL;
    }
    if(m_VedioThrd!=NULL)
    {
        m_VedioThrd->quit();
        m_VedioThrd->wait();
        delete m_VedioThrd;
        m_VedioThrd=NULL;
    }
}

// 初始化控件
void Dialog::InitCtrls()
{

    // 固定窗口大小
    this->setFixedSize(382,514);
    // 设置窗口风格
    this->setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);

    // 窗口标题
    this->setWindowTitle("PopStar");

    // 设置控件的样式
    // ui->lineEdit_4->setStyleSheet("background:transparent;border-width:0px;border-style:outset");
    ui->lineEdit_Grade->setStyleSheet("background:transparent;border-width:0px;border-style:outset;font-size:18px;color:rgb(0,255,0);font:bold");
    ui->lineEdit_isSuccess->setStyleSheet("background:transparent;border-width:0px;border-style:outset;font-size:16px;color:rgb(0,255,0);font:bold");
    ui->lineEdit_CurrScore->setStyleSheet("background:transparent;border-width:0px;border-style:outset;font-size:22px;color:rgb(0,0,255);");
    ui->lineEdit_GoalScore->setStyleSheet("background:transparent;border-width:0px;border-style:outset;font-size:18px;color:rgb(0,255,0);font:bold");
    ui->lineEdit_TotalScore->setStyleSheet("background:transparent;border-width:0px;border-style:outset;font-size:20px;color:rgb(0,255,0);font:bold");
    ui->btn_Music->setStyleSheet("background:transparent;border-with:0;border-style:outset;");
    ui->btn_Vedio->setStyleSheet("background:transparent;border-with:0;border-style:outset;");

    // 设置控件的初始数据
    ui->lineEdit_CurrScore->setText(QString::number(m_nCurrScore));
    ui->lineEdit_Grade->setText(QString::number(m_nGrade));
    ui->lineEdit_GoalScore->setText(QString::number(m_nGoalScore));
    ui->lineEdit_TotalScore->setText(QString::number(m_nTotalScore));

    m_MusicThrd=new MusicThrd(m_bMusic,this);
    m_MusicThrd->start();
    m_MusicThrd->setMusicPlay(m_bMusic);
    m_MusicThrd->run();

    m_VedioThrd=new VideoThrd(m_bVideo,this);
    m_VedioThrd->start();
    //   m_VedioThrd->setStarCount(0);

}
// 初始化数据
void Dialog::InitData()
{

    // 给数组初始化
    for(int i=0;i<LEN;i++)
    {

        for(int j=0;j<LEN;j++)
        {
            m_arrayStar[i][j].data=0;
            m_arrayStar[i][j].willRemove=false;
        }
    }

    // 初始化随机种子
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    Srand();
}

// 初始化媒体
void Dialog::InitMedia()
{
    // 初始化Media设备

    m_MedMusList=new QMediaPlaylist;
    m_MedMusList->addMedia(QUrl::fromLocalFile("D:\\QtCode\\PopStar_2\\res\\岑宁儿 - 追光者.mp3"));
    m_MedMusList->addMedia(QUrl::fromLocalFile("D:\\QtCode\\PopStar_2\\res\\李佳思 - TheStar.mp3"));
    m_MedMusList->addMedia(QUrl::fromLocalFile("D:\\QtCode\\PopStar_2\\res\\Maroon 5 - Sugar (Clean).mp3"));
    m_MedMusList->setCurrentIndex(1);

    qDebug()<<m_MedMusList->currentIndex();

    // 初始化音乐
    m_MedMusic=new QMediaPlayer;
    m_MedMusic->setMedia(m_MedMusList);

    m_MedMusList->setPlaybackMode(QMediaPlaylist::Loop);
    //岑宁儿 - 追光者.mp3
    m_MedMusic->setVolume(100);

    if(m_bMusic)
    {
        m_MedMusic->play();
    }
    else
    {
        m_MedMusic->stop();
    }


    //    qDebug()<<m_MedMusList->currentIndex();
    /*
    m_MedVedList=new QMediaPlaylist;
    m_MedMusList->addMedia(QUrl::fromLocalFile("D:\\QtCode\\PopStar_2\\res\\222.mp3"));
    m_MedMusList->addMedia(QUrl::fromLocalFile("D:\\QtCode\\PopStar_2\\res\\unbelievable.mp3"));
    m_MedMusList->addMedia(QUrl::fromLocalFile("D:\\QtCode\\PopStar_2\\res\\222.wav"));
    m_MedMusList->setCurrentIndex(1);
*/


    // 初始化声音
    m_MedVedi=new QMediaPlayer;
    //   m_MedVedi->setMedia(m_MedVedList);
    m_MedVedi->setMedia(QUrl::fromLocalFile("D:\\QtCode\\PopStar_2\\res\\222.mp3"));
    //    m_MedVedList->setPlaybackMode(QMediaPlaylist::Loop);
    m_MedVedi->setVolume(100);
    m_MedVedi->play();

}

// 产生随机数，给数组赋值
void Dialog::Srand()
{
    for(int i=0;i<LEN;i++)
    {

        for(int j=0;j<LEN;j++)
        {
            m_arrayStar[i][j].data=qrand()%4+1;
            m_arrayStar[i][j].willRemove=true;

        }
    }
}

// 画星星
void Dialog::DrawStar()
{
    QPainter painter(this);

    // 画声音
    if(m_bVideo)
    {

        painter.drawPixmap(270,1,61,51,*m_pixVoiceUp);
    }
    else
    {
        painter.drawPixmap(270,1,61,51,*m_pixVoiceDown);
    }


    // 画音乐
    if(m_bMusic)
    {

        painter.drawPixmap(328,1,61,51,*m_pixMusicUp);
    }
    else
    {
        painter.drawPixmap(328,1,61,51,*m_pixMusicDown);
    }
    this->update();

    // 画星星
    for(int i=0;i<LEN;i++)
    {
        for(int j=0;j<LEN;j++)
        {

            int m_X=i*m_starWidth+5;
            int m_Y=j*m_starHeight+m_Border-32;

            if(m_arrayStar[i][j].data!=0)
            {
                switch(m_arrayStar[i][j].data)
                {
                case 1:
                    painter.drawPixmap(m_X,m_Y,m_starWidth,m_starHeight,m_rStar->m_pixStar);
                    break;
                case 2:
                    painter.drawPixmap(m_X,m_Y,m_starWidth,m_starHeight,m_gStar->m_pixStar);
                    break;
                case 3:
                    painter.drawPixmap(m_X,m_Y,m_starWidth,m_starHeight,m_BlueStar->m_pixStar);
                    break;
                case 4:
                    painter.drawPixmap(m_X,m_Y,m_starWidth,m_starHeight,m_yStar->m_pixStar);
                    break;
                default:
                    break;
                }
                this->update();
            }

        }
    }

}

// 获取当前鼠标位置的y下标
int Dialog::GetIndexX(int xPos)
{
    // return xPos
    return (xPos-5)/m_starWidth;
}

// 获取当前鼠标位置的x下标
int Dialog::GetIndexY(int yPos)
{
    return (yPos-32)/m_starHeight-2;
}

// 转换星星数组下标
void Dialog::ChangeIndex(QPoint e)
{
    m_X=GetIndexX(e.x());
    m_Y=GetIndexY(e.y());
}

// 查找将要删除的星星
void Dialog::CheckMoveStar(int x,int y,int &count)
{
    /*
        x相当于纵轴，y相当于横轴

    */

    // 鼠标点击的位置在星星外面 ，不做任何操作
    if(x<0||x>=LEN||y<0||y>=LEN||m_arrayStar[x][y].data==0)
        return;

    count++;

    // 判断鼠标点击的当前星星的位置的上方是否有相同的星星,若有相同的星星，则数组位置置为0
    // 上方
    if(y-1>=0&&x<LEN&&m_arrayStar[x][y-1].data==m_arrayStar[x][y].data&&m_arrayStar[x][y-1].willRemove!=false)
    {
        // 当前位置的星星置为空
        // m_preStarCol=m_arrayStar[x][y];
        m_arrayStar[x][y].willRemove=false;
        m_arrayStar[x][y-1].willRemove=false;
        // 继续向上找，是否有相同颜色的星星
        CheckMoveStar(x,y-1,count);
        //      m_arrayStar[x][y-1]=0;
    }

    // 左方
    if(x-1>=0&&x<LEN&&m_arrayStar[x-1][y].data==m_arrayStar[x][y].data&&m_arrayStar[x-1][y].willRemove!=false)
    {
        // 当前位置的星星置为空
        m_arrayStar[x][y].willRemove=false;

        m_arrayStar[x-1][y].willRemove=false;
        // 继续向上找，是否有相同颜色的星星
        CheckMoveStar(x-1,y,count);
        //  m_arrayStar[x-1][y]=0;
    }

    // 右方
    if(x>=0&&x+1<=LEN&&m_arrayStar[x+1][y].data==m_arrayStar[x][y].data&&m_arrayStar[x+1][y].willRemove!=false)
    {
        // 当前位置的星星置为空
        m_arrayStar[x][y].willRemove=false;
        m_arrayStar[x+1][y].willRemove=false;
        // 继续向上找，是否有相同颜色的星星
        CheckMoveStar(x+1,y,count);
        //   m_arrayStar[x+1][y]=0;
    }

    // 下方
    if(y>=0&&y+1<=LEN&&m_arrayStar[x][y+1].data==m_arrayStar[x][y].data&&m_arrayStar[x][y+1].willRemove!=false)
    {
        // 当前位置的星星置为空
        m_arrayStar[x][y].willRemove=false;
        m_arrayStar[x][y+1].willRemove=false;
        // 继续向上找，是否有相同颜色的星星
        CheckMoveStar(x,y+1,count);
        //   m_arrayStar[x][y+1]=0;
    }
}

// 消灭星星
void Dialog::KillStar()
{
    // 检查数组中的星星是否被标记过
    if(m_nCount>=3)
    {
        for(int i=0;i<LEN;i++)
        {
            for(int j=0;j<LEN;j++)
            {
                if(m_arrayStar[i][j].willRemove==false)
                {

                    m_arrayStar[i][j].data=0;
                }
            }
        }
    }
    else
    {
        // 恢复被标记过的星星的可被删除性能
        for(int i=0;i<LEN;i++)
        {
            for(int j=0;j<LEN;j++)
            {
                if(m_arrayStar[i][j].willRemove==false)
                {

                    m_arrayStar[i][j].willRemove=true;
                }
            }
        }
        //   m_MedVedList->setCurrentIndex(3);
        //   m_MedVedi->play();
        m_nCount=0;
    }
}

// 检查是否下落
bool Dialog::CheckMove(int col)
{
    int count=0;
    for(int j=0;j<LEN;j++)
    {
        if(m_arrayStar[col][j].willRemove==false)
        {
            count++;
        }
    }
    if(count>=1)            // 只要没一列上面有星星存在，则下落
    {
        return true;
    }
    else                    // 若这一列上面没有星星存在，
    {
        return false;
    }
}

// 星星下落
void Dialog::StarDown()
{
    StarArray temp[LEN];       // 临时数组用来控制星星下落

    for(int i=0;i<LEN;i++)    // 总共有10列
    {
        int   k=0;          // k用来控制临时数组的下标
        if(CheckMove(i))            // 检查第i列是否可以下落,把第一列的所有星星下落到底部
        {
            // 先给临时数组初始化
            for(int m=0;m<LEN;m++)
            {
                temp[m].data=0;         // 给数组域部分设置为0，没有星星
                temp[m].willRemove=false;       // 设置数组所在星星的可悲删除性为  false 表示为已删除   true 表示没有被删除
            }

            // 把第i列赋值给临时数组，进行赋值
            for(int j=LEN-1;j>=0;j--)
            {
                if(m_arrayStar[i][j].willRemove!=false)
                {
                    temp[LEN-k-1]=m_arrayStar[i][j];
                    k++;
                }

            }

            // 把临时数组中的内容复制给这一列
            for(int j=LEN-1;j>=0;j--)
            {
                m_arrayStar[i][j]=temp[j];
            }
            this->update();
        }
    }
}

// 检查游戏是否结束
bool Dialog::CheckGameOver()
{
    for(int i=0;i<LEN;i++)
    {
        for(int j=0;j<LEN;j++)
        {
            if(findWillRemove(i,j)>=3)
            {
                return false;
            }
        }
    }
    return true;
}

// 寻找将被移除的星星
int Dialog::findWillRemove(int x, int y)
{
    int count=0;
    CheckMoveStar(x,y,count);

    //  把被标记过有相同的星星连在一起的被删除的属性改为 改回true;

    for(int i=0;i<LEN;i++)
    {
        for(int j=0;j<LEN;j++)
        {
            if(m_arrayStar[i][j].willRemove==false&&m_arrayStar[i][j].data!=0)
            {
                m_arrayStar[i][j].willRemove=true;
            }

        }
    }
    return count;
}
// 找到最右边的空列号
int Dialog:: findMaxRightCol()
{
    int col=-1;     // 找到最右边的空列
    for(int i=0;i<LEN;i++)
    {
        if(JudgeColBlank(i))
        {
            col=i;
        }
    }
    // 如果最右边列为第0列，则不需要移动
    if(col==0)
    {
        return -1;
    }
    else
    {
        return col;
    }
}

// 把空列向右移动
void Dialog::MoveCol()
{
    int MaxRCol=findMaxRightCol();     // 记录最右边的空列
    //   int BlankCol=GetBlankCol();     // 记录空列个数

    StarArray temp[MaxRCol+1][LEN];    // 申请一个临时存放移动后的数组

    // 初始化临时数组
    for(int i=0;i<MaxRCol+1;i++)
    {
        for(int j=0;j<LEN;j++)
        {
            temp[i][j].data=0;
            temp[i][j].willRemove=false;
        }
    }

    int k=MaxRCol;

    if(k>0)
    {
        // 移动数组的列

        // 总共有MaxRCol列
        for(int i=MaxRCol;i>=0;i--)
        {
            // 判断第i列是否为空列，若为空列，则不需要移动 ,如果为空列，则移动到新数组中
            if(JudgeColBlank(i)==false)
            {
                // 移动列
                for(int j=0;j<LEN;j++)
                {
                    temp[k][j]=m_arrayStar[i][j];
                }
                k--;
            }

        }



        // 把移动后的数组赋值回去
        for(int i=MaxRCol;i>=0;i--)
        {
            for(int j=0;j<LEN;j++)
            {
                m_arrayStar[i][j]=temp[i][j];

            }
        }
        this->update();

    }
}

// 判断该列是否为空列
bool Dialog::JudgeColBlank(int col)
{
    int count=0;
    for(int i=0;i<LEN;i++)
    {
        if(m_arrayStar[col][i].data==0&&m_arrayStar[col][i].willRemove==false)
        {
            count++;
        }
    }

    if(count==10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 获取空列个数
int Dialog::GetBlankCol()
{
    int count=0;
    for(int i=0;i<LEN;i++)
    {
        if(JudgeColBlank(i))
        {
            count++;
        }
    }
    return count;
}
// 获取消灭星星的分数段
int Dialog::GetScoreSeg(int count)
{
    int score=0;
    switch(count)
    {
    case 0:
    case 1:
    case 2:
        score=0;
        break;
    case 3:
        score=40;
        break;
    case 4:
        score=60;
        break;
    case 5:
        score=80;
        break;
    case 6:
        score=100;
        break;
    case 7:
        score=120;
        break;
    case 8:
        score=140;
        break;
    case 9:
        score=160;
        break;
    case 10:
        score=180;
        break;
    default:
        score=200;
        break;
    }
    return score;

}
// 设置关数的目标分数
int Dialog::SetGradeSocre(int grade)
{
    m_nGoalScore=(grade-1)*100+1000;
}
// 判断是否进入下一关
bool Dialog::JudgeSuccNext()
{
    if(m_nCurrScore>=m_nGoalScore)
    {
        return true;
    }
    else
    {
        return false;
    }

}
// 计算当前分数
int Dialog::CaclCurrScore(int count)
{
    int score=GetScoreSeg(count);
    return score;
}
// 显示分数界面
void Dialog::ShowScoreGUI(int count)
{
    // 计算当前分数
    int score=CaclCurrScore(count);
    m_nCurrScore+=score;
    m_nTotalScore+=score;
    // 判断当前分数是否通关

    // 设置控件的初始数据
    ui->lineEdit_CurrScore->setText(QString::number(m_nCurrScore));
    ui->lineEdit_TotalScore->setText(QString::number(m_nTotalScore));
    ui->lineEdit_GoalScore->setText(QString::number(m_nGoalScore));
    ui->lineEdit_Grade->setText(QString::number(m_nGrade));
    if(JudgeSuccNext())
    {
        m_bSuccGrade=1;

        ui->lineEdit_isSuccess->setText(QString("已过关!"));

        if(!CheckGameOver())
        {
            return;
        }
        else
        {
            int res=QMessageBox::question(this,"应用程序提示","请问您是否要进入下一关？",tr("确定"),tr("取消"),0,1);
            if(res==1)
            {
                this->close();
                return;
            }
        }
        m_nGrade++;
        m_nCurrScore=0;
        m_bSuccGrade=-1;
        SetGradeSocre(m_nGrade);
        InitData();
        this->update();

        ui->lineEdit_GoalScore->setText(QString::number(m_nGoalScore));
        ui->lineEdit_CurrScore->setText(QString::number(m_nCurrScore));
        ui->lineEdit_TotalScore->setText(QString::number(m_nTotalScore));
        ui->lineEdit_Grade->setText(QString::number(m_nGrade));

        if(m_bSuccGrade==0)
        {
            ui->lineEdit_isSuccess->setText(QString("未过关!"));
        }
        else if(m_bSuccGrade==1)
        {
            ui->lineEdit_isSuccess->setText(QString("已过关!"));

        }
        else if(m_bSuccGrade==-1)
        {
            ui->lineEdit_isSuccess->setText(QString(""));
        }

    }

    if(CheckGameOver()&&!JudgeSuccNext())
    {
        m_bSuccGrade=0;
    }
    if(!CheckGameOver()&&!JudgeSuccNext())
    {
        m_bSuccGrade=-1;
    }\
    if(m_bSuccGrade==0)
    {
        ui->lineEdit_isSuccess->setText(QString("未过关!"));
    }
    else if(m_bSuccGrade==1)
    {
        ui->lineEdit_isSuccess->setText(QString("已过关!"));

    }
    else if(m_bSuccGrade==-1)
    {
        ui->lineEdit_isSuccess->setText(QString(""));
    }
}

// 窗口绘制事件
void Dialog::paintEvent(QPaintEvent *e)
{

    // 加载背景图片
    QPainter painter(this);

    painter.drawPixmap(0,0,m_width,m_Height,*m_pixBK);

    DrawStar();
    //   MusicAndVoid();

}

// 鼠标按下事件

void Dialog::mousePressEvent(QMouseEvent *e)
{
    if(CheckGameOver())
    {
        MoveCol();
        int res=QMessageBox::information(this,"应用程序提示","您的最高得分是："+QString::number(m_nTotalScore));
        if(res=QMessageBox::Yes)
        {
            res=QMessageBox::question(this,"应用程序提示","游戏结束,请问您是否要退出?",tr("确定"),tr("取消"),0,1);
            if(res==0)
            {
                if(m_MusicThrd==NULL&&m_VedioThrd==NULL)
                {
                    return;
                }
                if(m_MusicThrd!=NULL)
                {
                    m_MusicThrd->quit();
                    m_MusicThrd->wait();

                    delete m_MusicThrd;
                    m_MusicThrd=NULL;
                }
                if(m_VedioThrd!=NULL)
                {
                    m_VedioThrd->quit();
                    m_VedioThrd->wait();
                    delete m_VedioThrd;
                    m_VedioThrd=NULL;
                }

                this->close();
            }
        }

    }
    MoveCol();
    m_nCount=0;

    ChangeIndex(e->pos());

    qDebug()<<"m_X="<<m_X<<",m_Y="<<m_Y;

    CheckMoveStar(m_X,m_Y,m_nCount);

    KillStar();

    // m_VedioThrd->msleep(500);
    StarDown();
    SetGradeSocre(m_nGrade);
    ShowScoreGUI(m_nCount);
    MoveCol();

    m_VedioThrd->setStarCount(m_nCount);
    m_VedioThrd->run();
    sleep(100);
}
// 鼠标移动事件
void Dialog::mouseMoveEvent(QMouseEvent *e)
{

    //  m_CurrPoint=e->pos();.  .....
    //  qDebug()<<"x="<<m_CurrPoint.x()<<",y="<<m_CurrPoint.y();

    //   qDebug()<<"x="<<e->pos().x()<<",y="<<e->pos().y();
}
//窗口关闭事件
void Dialog::closeEvent(QCloseEvent *e)
{
    switch(QMessageBox::information(this,tr("应用和程序提示"),tr("您确定要退出此界面吗?"),tr("确定"),tr("取消"),0,1))
    {
    case 0:

        m_bVideo=false;
        m_bMusic=false;
        if(m_MusicThrd==NULL&&m_VedioThrd==NULL)
        {
            return;
        }
        if(m_MusicThrd!=NULL)
        {
            m_MusicThrd->quit();
           m_MusicThrd->wait();

            delete m_MusicThrd;
            m_MusicThrd=NULL;
        }
        if(m_VedioThrd!=NULL)
        {
    //        m_VedioThrd->quit();
    //        m_VedioThrd->wait();
            delete m_VedioThrd;
            m_VedioThrd=NULL;
        }
     e->accept();
        break;
    case 1:

    default:
        e->ignore();
        break;

    }
}
// 主线程等待子线程不阻塞函数
void Dialog::sleep(unsigned int msec)
{
    QTime dieTime=QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

void Dialog::on_btn_Vedio_clicked()
{
    if(m_bVideo)
    {
        m_bVideo=false;
        //   m_MedVedi->pause();
        m_VedioThrd->setVedioPlay(m_bVideo);
        m_VedioThrd->run();
        sleep(100);
        //  m_VedioThrd->msleep(500);
    }

    else
    {
        m_bVideo=true;
        m_VedioThrd->setVedioPlay(m_bVideo);
        m_VedioThrd->run();
        sleep(100);
        //    m_VedioThrd->msleep(500);
    }

}

void Dialog::on_btn_Music_clicked()
{
    if(m_bMusic)
    {
        m_bMusic=false;
        //    m_MedMusic->pause();

    }

    else
    {
        m_bMusic=true;
        //     m_MedMusic->play();
    }
    m_MusicThrd->setMusicPlay(m_bMusic);
    m_MusicThrd->run();
}

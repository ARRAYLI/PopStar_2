#include "videothrd.h"

VideoThrd::VideoThrd(bool vedio,QObject * parent)
    :QThread(parent)
{
    m_bVideo=vedio;
    m_MedVediWin=NULL;
    m_MedVediDWin=NULL;
    m_MeVediFilure=NULL;


    m_count=0;
    InitMedia();
}

VideoThrd::~VideoThrd()
{
    if(m_MeVediFilure!=NULL)
    {
     delete m_MeVediFilure;
     m_MeVediFilure=NULL;
    }
    if(m_MedVediWin!=NULL)
    {
        delete m_MedVediWin;
        m_MedVediWin=NULL;
    }
    if(m_MedVediDWin!=NULL)
    {
        delete m_MedVediDWin;
        m_MedVediDWin=NULL;
    }
}

void VideoThrd::setStarCount(int count)
{
    m_count=count;
}
void VideoThrd::run()
{
    if(m_bVideo)
    {

        if(m_count<3)
        {
            m_MeVediFilure->play();
        }
        else if(m_count>=3&&m_count<5)
        {
            m_MedVediWin->play();
        }
        if(m_count>=5)
        {
            m_MedVediDWin->play();
        }

        /*



        */
        if(m_MeVediFilure->state()!=QMediaPlayer::PlayingState)
        {
            m_MeVediFilure->pause();

        }
        else if(m_MedVediWin->state()!=QMediaPlayer::PlayingState)
        {   m_MedVediWin->pause();

        }
        else if(m_MedVediDWin->state()!=QMediaPlayer::PlayingState)
        {
            m_MedVediDWin->pause();
        }

    }

    else
    {
        m_MedVediDWin->stop();
        m_MedVediWin->stop();
        m_MeVediFilure->stop();
    }


    //    connect(m_MeVediFilure,SIGNAL(state()),this,SLOT(sf));

}


// 初始化媒体资源
void VideoThrd::InitMedia()
{
    // 3颗星星以下的声音

    m_MeVediFilure=new QMediaPlayer;
     m_MeVediFilure->setMedia(QUrl::fromLocalFile("D:\\QtCode\\PopStar_2\\res\\222.wav"));
 //   m_MeVediFilure->setMedia(QUrl::fromLocalFile("../PopStar_2/res/222.wav"));
  //  m_MeVediFilure->setMedia(QUrl::fromLocalFile("./res/222.wav"));
    m_MeVediFilure->setVolume(100);

    // 3-5颗星星的声音
    m_MedVediWin=new QMediaPlayer;
    m_MedVediWin->setMedia(QUrl::fromLocalFile("D:\\QtCode\\PopStar_2\\res\\222.mp3"));

  //  m_MedVediWin->setMedia(QUrl::fromLocalFile("../PopStar_2/res/222.mp3"));
   //     m_MedVediWin->setMedia(QUrl::fromLocalFile("./res/222.mp3"));
    m_MedVediWin->setVolume(100);

    // 大于等于5颗星星的声音
    m_MedVediDWin=new QMediaPlayer;
  //:/new/prefix1/res/unbelievable.mp3
 //    m_MedVediDWin->setMedia(QUrl::fromLocalFile("../PopStar_2/res/unbelievable.mp3"));
 //  m_MedVediDWin->setMedia(QUrl::fromLocalFile("./res/unbelievable.mp3"));
    m_MedVediDWin->setMedia(QUrl::fromLocalFile("D:\\QtCode\\PopStar_2\\res\\unbelievable.mp3"));
    m_MedVediDWin->setVolume(100);
}
// 消灭3个以下的星星声音
void VideoThrd::KillStarFailure()
{
    if(m_count<3)
    {
        m_MeVediFilure->play();
    }

}
// 消灭3-5之间的声音
void VideoThrd::KillStarWin()
{

}
// 消灭5个以上星星的声音（包含5个星星）
void VideoThrd::KillStarDWin()
{

}

bool VideoThrd::setVedioPlay(bool vedio)
{
    m_bVideo=vedio;
}


#include "musicthrd.h"

MusicThrd::MusicThrd(bool music,QObject * parent):
    QThread(parent)
{
    /*
    m_MedMusic=new QMediaPlayer;
    m_MedMusic->setMedia(QUrl::fromLocalFile("D:\\QtCode\\PopStar_2\\res\\岑宁儿 - 追光者.mp3"));
    m_MedMusic->setVolume(100);
    */

    m_bMusic=music;
    InitMedia();
}

MusicThrd::~MusicThrd()
{
    if(m_MedMusic!=NULL)
    {
     delete m_MedMusic;
     m_MedMusic=NULL;
    }
    if(m_MedMusList!=NULL)
    {
        delete m_MedMusList;
        m_MedMusList=NULL;
    }


}
  // 初始化媒体资源
void MusicThrd::InitMedia()
{
    // 初始化Media设备

    m_MedMusList=new QMediaPlaylist;


 //   m_MedMusList->addMedia(QUrl::fromLocalFile("../PopStar_2/res/岑宁儿 - 追光者.mp3"));



    m_MedMusList->addMedia(QUrl::fromLocalFile("../PopStar_2/res/李佳思 - TheStar.mp3"));
   m_MedMusList->addMedia(QUrl::fromLocalFile("../PopStar_2/res/Maroon 5 - Sugar (Clean).mp3"));
    m_MedMusList->setCurrentIndex(1);


    /*
    m_MedMusList->addMedia(QUrl::fromLocalFile("./res/岑宁儿 - 追光者.mp3"));

   m_MedMusList->addMedia(QUrl::fromLocalFile("./res/李佳思 - TheStar.mp3"));
   m_MedMusList->addMedia(QUrl::fromLocalFile("./res/Maroon 5 - Sugar (Clean).mp3"));
*/


/*
    m_MedMusList->addMedia(QUrl::fromLocalFile("D:\\QtCode\\PopStar_2\\res\\岑宁儿 - 追光者.mp3"));
    m_MedMusList->addMedia(QUrl::fromLocalFile("D:\\QtCode\\PopStar_2\\res\\Maroon 5 - Sugar (Clean).mp3"));

    m_MedMusList->addMedia(QUrl::fromLocalFile("D:\\QtCode\\PopStar_2\\res\\李佳思 - TheStar.mp3"));

    m_MedMusList->setCurrentIndex(1);
*/

    qDebug()<<m_MedMusList->currentIndex();

    // 初始化音乐
    m_MedMusic=new QMediaPlayer;
    m_MedMusic->setMedia(m_MedMusList);

    m_MedMusList->setPlaybackMode(QMediaPlaylist::Loop);
    //岑宁儿 - 追光者.mp3
    m_MedMusic->setVolume(80);

    /*
    if(m_bMusic)
    {
        m_MedMusic->play();
    }
    else
    {
        m_MedMusic->stop();
    }
    */
    this->run();

}

bool MusicThrd::setMusicPlay(bool music)
{
   m_bMusic=music;
}

void MusicThrd::run()
{
    if(m_bMusic)
    {
       m_MedMusic->play();
    }
    else
    {
        m_MedMusic->pause();
    }
}


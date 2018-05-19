#ifndef MUSICTHRD_H
#define MUSICTHRD_H

#include <QObject>
#include <QWidget>
#include<QThread>
#include<QMediaPlayer>
#include<QMediaPlaylist>

class MusicThrd : public QThread
{
    Q_OBJECT
public:
    MusicThrd(bool music,QObject * parent = 0);
    ~MusicThrd();
private:
   void InitMedia();       // 初始化媒体资源
public:
    void run();
    bool setMusicPlay(bool music);
private:
  //  QMediaPlayer   *m_MedMusic;
    bool            m_bMusic;
    QMediaPlaylist  *m_MedMusList;
    QMediaPlayer    *m_MedMusic;
};

#endif // MUSICTHRD_H

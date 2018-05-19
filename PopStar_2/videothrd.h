#ifndef VIDEOTHRD_H
#define VIDEOTHRD_H

#include <QObject>
#include <QWidget>
#include<QThread>
#include<QMediaPlayer>
#include<QMediaPlaylist>

class VideoThrd : public QThread
{
    Q_OBJECT
public:
    VideoThrd(bool vedio,QObject * parent = 0);
    ~VideoThrd();
public:
    void run();
    void setStarCount(int count);
    bool setVedioPlay(bool vedio);
private:
    void InitMedia();       // 初始化媒体资源
    void KillStarFailure();  // 消灭3个以下的星星声音
    void KillStarWin();         // 消灭3-5之间的声音
    void KillStarDWin();        // 消灭5个以上星星的声音（包含5个星星）

private:
    bool        m_bVideo;           // true 声音开着  false 声音关闭
    QMediaPlayer    *m_MedVediWin;      // 消灭3星星数量在>=3  <5
    QMediaPlayer    *m_MedVediDWin;     // 消灭星星数量在 >=5
    QMediaPlayer    *m_MeVediFilure;    // 消灭星星数量在<3
    int             m_count;
    int             m_index;
};

#endif // VIDEOTHRD_H

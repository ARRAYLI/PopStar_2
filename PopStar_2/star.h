#ifndef STAR_H
#define STAR_H

#include <QObject>
#include <QWidget>
#include<QPixmap>


class Star : public QWidget
{
    Q_OBJECT
public:
    explicit Star(QWidget *parent = 0);
    ~Star();

signals:

public slots:
public:
    bool  m_showStar;       // 是否显示星星
    int   m_Index;          // 标记星星的颜色
    QPixmap m_pixStar;      // 星星画布
};

#endif // STAR_H

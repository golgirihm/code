#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QMediaPlayer>

class Health : public QGraphicsTextItem
{
public:
    Health();

    void decrease();
    qint32 getHealth();

private:
    qint32 health;
//    QMediaPlayer *ouchMediaPlayer;
};

#endif // HEALTH_H

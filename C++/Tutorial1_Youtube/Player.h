#ifndef PLAYER
#define PLAYER

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QElapsedTimer>
#include <QMediaPlayer>

class Player: public QGraphicsPixmapItem
{
public:
    Player(QGraphicsView *parentView = 0);

    void keyPressEvent(QKeyEvent *event);

private:
    QElapsedTimer *shotTimer;
    QMediaPlayer *gunshotMediaPlayer;
};

#endif // PLAYER


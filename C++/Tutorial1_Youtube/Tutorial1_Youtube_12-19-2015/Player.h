#ifndef PLAYER
#define PLAYER

#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QElapsedTimer>
#include <QMediaPlayer>

class Player: public QGraphicsRectItem
{
public:
    Player();
    Player(QGraphicsView *parentView = 0);
    Player(QGraphicsRectItem *parentRectItem = 0);

    void keyPressEvent(QKeyEvent *event);

private:
    QElapsedTimer *shotTimer;
    QMediaPlayer *gunshotMediaPlayer;
};

#endif // PLAYER


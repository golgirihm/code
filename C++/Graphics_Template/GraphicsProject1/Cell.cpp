#include <QKeyEvent>
#include <QGraphicsScene>
#include <QElapsedTimer>
#include <QUrl>
#include "Cell.h"
#include "Bullet.h"
#include "Enemy.h"

#define PLAYER_WIDTH 35
#define PLAYER_HEIGHT 70

#define PX_PLAYER_PADDING 15
#define PX_PLAYER_MOVEMENT 50
#define MIN_SHOT_INTERVAL 100


Player::Player()
{
    setRect(0, 0, PLAYER_WIDTH, PLAYER_HEIGHT);
    setFlag(QGraphicsItem::ItemIsFocusable);
    shotTimer = new QElapsedTimer;
//    gunshotMediaPlayer = new QMediaPlayer;
//    gunshotMediaPlayer->setMedia(QUrl("qrc:/sounds/gunshot.mp3"));
//    gunshotMediaPlayer->setVolume(85);
}

Player::Player(QGraphicsView *parentView)
{
   setRect(0, 0, PLAYER_WIDTH, PLAYER_HEIGHT);
   setFlag(QGraphicsItem::ItemIsFocusable);
   shotTimer = new QElapsedTimer;
//   gunshotMediaPlayer = new QMediaPlayer;
//   gunshotMediaPlayer->setMedia(QUrl("qrc:/sounds/gunshot.mp3"));

   if(parentView) setPos((parentView->width() - rect().width())/2, parentView->height() - rect().height() - PX_PLAYER_PADDING);
}


void Player::keyPressEvent(QKeyEvent *event)
{
    qreal newX = x();
    qreal newY = y();

    switch(event->key())
    {
    case Qt::Key_Left:
        newX -= PX_PLAYER_MOVEMENT;
        break;
    case Qt::Key_Right:
        newX += PX_PLAYER_MOVEMENT;
        break;
    case Qt::Key_Up:
        newY -= PX_PLAYER_MOVEMENT;
        break;
    case Qt::Key_Down:
        newY += PX_PLAYER_MOVEMENT;
        break;
    case Qt::Key_Space:
    {
        if(shotTimer->isValid() && shotTimer->elapsed() > MIN_SHOT_INTERVAL)
            shotTimer->invalidate();

        if(!shotTimer->isValid())
        {
            shotTimer->start();

            // create a bullet
            Bullet *bullet = new Bullet(this);
            scene()->addItem(bullet);

            // play gunshot sound
//            if(gunshotMediaPlayer->state() == QMediaPlayer::PlayingState)
//                gunshotMediaPlayer->setPosition(0);
//            else if(gunshotMediaPlayer->state() == QMediaPlayer::StoppedState)
//                gunshotMediaPlayer->play();
        }


        break;
    }
    default:
        break;
    }


    // stay inside scene horizontally
    if(newX < 0)
        newX = 0;
    else if(newX + rect().width() > scene()->width())
        newX = scene()->width() - rect().width();

    // stay inside scene vertically
    if(newY < 0)
        newY = 0;
    else if(newY + rect().height() > scene()->height())
        newY = scene()->height() - rect().height();

    // update rectangle position
    setPos(newX, newY);
}
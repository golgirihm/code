#include <QTimer>
#include <QGraphicsScene>
#include <QTime>
#include "Enemy.h"
#include "Game.h"


#define ENEMY_WIDTH 70
#define ENEMY_HEIGHT 70
#define ENEMY_PERIOD 10
#define PX_ENEMY_MOVEMENT 2
#define PX_ENEMY_START_Y 0


#include <QDebug>

/* GLOBAL VARIABLE: Game *game
  this is used to decrement the health when enemies exit the scne inside the Enemy::move() function
*/
extern Game *game;

Enemy::Enemy(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    // create an enemy at the top of the scene with a random x coordinate
    qsrand((uint)QTime::currentTime().msec());
    quint16 randX = qrand() % (800 - ENEMY_WIDTH);
    setPos(randX, PX_ENEMY_START_Y);

    // draw the enemy
    setPixmap(QPixmap(":/images/enemy.PNG"));
    setScale(0.7);
//    setRect(0, 0, ENEMY_WIDTH, ENEMY_HEIGHT);

    // fire the enemy
    movementTimer = new QTimer;
    connect(movementTimer, &QTimer::timeout, this, &Enemy::move);
    movementTimer->start(ENEMY_PERIOD);

}

Enemy::~Enemy()
{
    scene()->removeItem(this);
    delete movementTimer;
}

void Enemy::move()
{
    // move enemy down
    setPos(x(), y() + PX_ENEMY_MOVEMENT);

    // enemy moved off the sreen
    if(y() + pixmap().height() > scene()->height())
    {
        // decrease the health
        game->health->decrease();

        // delete this enemy
        delete this;
    }
}

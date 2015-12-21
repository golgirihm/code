#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <typeinfo>
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"


#define BULLET_WIDTH 10
#define BULLET_HEIGHT 50
#define BULLET_PERIOD 12
#define PX_BULLET_MOVEMENT 7
#define PX_BULLET_PADDING 15


#include <QDebug>



/* GLOBAL VARIABLE: Game *game
  this is used to increment the score on collisions inside the Bullet::move() function
*/
extern Game *game;


Bullet::Bullet(QGraphicsPixmapItem *parentPixmapItem)
{
    // draw the bullet
    setPixmap(QPixmap(":/images/bullet.png"));
    setScale(0.7);
//    setRect(0, 0, BULLET_WIDTH, BULLET_HEIGHT);

    // fire the bullet
    movementTimer = new QTimer;
    connect(movementTimer, &QTimer::timeout, this, &Bullet::move);
    movementTimer->start(BULLET_PERIOD);

    if(parentPixmapItem) setPos(parentPixmapItem->x() + (parentPixmapItem->pixmap().width() - pixmap().width())/2, parentPixmapItem->y() - pixmap().height() - PX_BULLET_PADDING);
}

Bullet::~Bullet()
{
    scene()->removeItem(this);
    delete movementTimer;
}



void Bullet::move()
{
    // if bullet collides with enemy, destroy bullet and enemy
    QList<QGraphicsItem *> collidingItems = this->collidingItems();
    for(int i = 0, n = collidingItems.size(); i < n; ++i)
    {
        if( typeid(*(collidingItems[i])) == typeid(Enemy) )
        {
            // increase the score
            game->score->increase();

            // remove them both
            delete collidingItems[i];
            delete this;
            return;
        }
    }


    // move bullet up
    setPos(x(), y() - PX_BULLET_MOVEMENT);

    // delete the bullet when it moves off the sreen
    if(y() +  pixmap().height() < 0)
        delete this;
}

#ifndef ENEMY
#define ENEMY

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Enemy(QGraphicsItem *parent = 0);
    ~Enemy();

public slots:
    void move();

protected:
    QTimer *movementTimer;


};

#endif // ENEMY


#ifndef BULLET
#define BULLET

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Bullet(QGraphicsPixmapItem *parentPixmapItem = 0);
    ~Bullet();

public slots:
    void move();

protected:
    QTimer *movementTimer;


};

#endif // BULLET


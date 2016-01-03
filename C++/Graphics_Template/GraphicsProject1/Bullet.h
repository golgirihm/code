#ifndef BULLET
#define BULLET

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Bullet(QGraphicsRectItem *parentRectItem = 0);
    ~Bullet();

public slots:
    void move();

protected:
    QTimer *movementTimer;


};

#endif // BULLET


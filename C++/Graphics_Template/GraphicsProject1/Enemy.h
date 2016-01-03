#ifndef ENEMY
#define ENEMY

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>

class Enemy: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Enemy();
    ~Enemy();

public slots:
    void move();

protected:
    QTimer *movementTimer;


};

#endif // ENEMY


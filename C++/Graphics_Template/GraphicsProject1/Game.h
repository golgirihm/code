#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer>
#include "Cell.h"
#include "Score.h"
#include "Health.h"

class Game : public QGraphicsView
{

    Q_OBJECT

public:
   Game();
   ~Game();

public slots:
   void spawnEnemy();

private:
   QGraphicsScene *gameScene;
   Player *player;

};

#endif // GAME_H


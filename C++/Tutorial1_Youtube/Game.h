#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer>
#include "Player.h"
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
   QTimer *spawnTimer;
   QMediaPlayer *backgroundMediaPlayer;



public: // TODO: make these private
   Score *score;
   Health *health;

};

#endif // GAME_H


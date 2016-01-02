//! [1]
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QWidget>
#include <QMediaPlayer>
#include <QUrl>
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
//! [1]


#define TOTAL_WIDTH 800
#define TOTAL_HEIGHT 600
#define SPAWN_RATE 800
#define TEXT_PADDING 25

#include <QDebug>

Game::Game()
{
    // create scene
    gameScene = new QGraphicsScene;
    gameScene->setSceneRect(0,0,TOTAL_WIDTH,TOTAL_HEIGHT);

    // use gameScene as the scene to visualize
    setScene(gameScene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(TOTAL_WIDTH,TOTAL_HEIGHT);

    // create player
    player = new Player(this);
    player->setFocus();

    // create score and health
    score = new Score();
    health = new Health();
    health->setPos(health->x(), health->y() + TEXT_PADDING);

    // spawn enemies
    spawnTimer = new QTimer;
    connect(spawnTimer, &QTimer::timeout, this, &Game::spawnEnemy);
    spawnTimer->start(SPAWN_RATE);

    // fill scene and show view
    gameScene->addItem(player);
    gameScene->addItem(score);
    gameScene->addItem(health);
    show();

    // play background music
    backgroundMediaPlayer = new QMediaPlayer;
    backgroundMediaPlayer->setMedia(QUrl("qrc:/sounds/bg_music_8bit.mp3"));
    backgroundMediaPlayer->setVolume(50);
    backgroundMediaPlayer->play();
}

Game::~Game()
{
    delete gameScene;
    delete player;
    delete spawnTimer;
    delete score;
}

void Game::spawnEnemy()
{
    // create an enemy
    Enemy *enemy = new Enemy;
    gameScene->addItem(enemy);
}

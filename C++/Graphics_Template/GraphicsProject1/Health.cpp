#include "Health.h"
#include <QFont>

Health::Health()
{
    // initialize health to 0
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));

    // set up media player
//    ouchMediaPlayer = new QMediaPlayer;
//    ouchMediaPlayer->setMedia(QUrl("qrc:/sounds/ouch.wav"));


}

void Health::decrease()
{
    --health;
    setPlainText(QString("Health: ") + QString::number(health));

//    if(ouchMediaPlayer->state() == QMediaPlayer::PlayingState)
//        ouchMediaPlayer->setPosition(0);
//    else if(ouchMediaPlayer->state() == QMediaPlayer::StoppedState)
//        ouchMediaPlayer->play();
}

qint32 Health::getHealth()
{
    return health;
}



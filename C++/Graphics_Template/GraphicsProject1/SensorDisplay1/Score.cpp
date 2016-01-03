#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    // initialize score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));

    // set up media player
//    successMediaPlayer = new QMediaPlayer;
//    successMediaPlayer->setMedia(QUrl("qrc:/sounds/success.wav"));
//    successMediaPlayer->setVolume(50);
}

void Score::increase()
{
    ++score;
    setPlainText(QString("Score: ") + QString::number(score));

//    if(successMediaPlayer->state() == QMediaPlayer::PlayingState)
//        successMediaPlayer->setPosition(0);
//    else if(successMediaPlayer->state() == QMediaPlayer::StoppedState)
//        successMediaPlayer->play();
}

qint32 Score::getScore()
{
    return score;
}

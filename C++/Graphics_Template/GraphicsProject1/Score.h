#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QMediaPlayer>

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent = 0);
    void increase();
    qint32 getScore();

private:
    qint32 score;
//    QMediaPlayer *successMediaPlayer;
};

#endif // SCORE_H

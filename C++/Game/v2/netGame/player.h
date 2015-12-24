#ifndef PLAYER_H
#define PLAYER_H

#define DEFAULT_USERNAME ""

#include <QObject>

#include <QMainWindow>


struct playerinfo
{
    QString userName;
    qint8 playerNumber;
//    cardstack Hand;
};

class player : public QMainWindow
{
    Q_OBJECT

public:
    player(QWidget *parent = 0);
    ~player();

public slots:

protected:
    playerinfo *info;

};

#endif // PLAYER_H

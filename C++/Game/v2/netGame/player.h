#ifndef PLAYER_H
#define PLAYER_H

#define DEFAULT_USERNAME ""


#include <QMainWindow>


struct playerinfo
{
    QString userName;
    qint8 playerNumber;
//    cardstack Hand;
};

class player : public QObject
{
    Q_OBJECT

public:
    player();
    ~player();

public slots:

protected:
    playerinfo *info;

protected slots:

};

#endif // PLAYER_H

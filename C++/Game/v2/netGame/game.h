#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "host.h"
#include "guest.h"



#include <QMainWindow>
// GUI includes
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QPushButton>



class game : public QMainWindow
{
    Q_OBJECT
public:
    game(QWidget *parent = 0);
    ~game();

    enum PLAYERTYPE : quint8 {NONE, HOST, GUEST};

private slots:
    void buttonClicked(QAbstractButton *button);
    void switchPlayerTypeTo(PLAYERTYPE newType);

private:
    PLAYERTYPE playerType;

    player *gamePlayer;
    host *gameHost;
    guest *gameGuest;

    // GUI variables
    QWidget *centralWidget;
    QGridLayout *layout;
    QButtonGroup *bg_mainmenu;
    QPushButton *pb_hostGame;
    QPushButton *pb_joinGame;
};

#endif // GAME_H

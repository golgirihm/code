#ifndef GAME_H
#define GAME_H

#include <QMainWindow>

class player;
class host;
class guest;

// GUI widgets
class QStackedWidget;
class QLayout;
class QGridLayout;
class QVBoxLayout;
class QHBoxLayout;
class QAbstractButton;
class QButtonGroup;
class QPushButton;
class QComboBox;
class QTextEdit;
class QLineEdit;
class QTextBrowser;
class QLabel;
class QFont;
class QSize;

class game : public QMainWindow
{
    Q_OBJECT
public:
    game(QWidget *parent = 0);
    ~game();

    enum PLAYERTYPE : quint8 {NONE, HOST, GUEST};

    QString getLobbyIPAddress();
    quint16 getLobbyPort();
    QString getLobbyEnteredUserName();
    void setLobbyIPAddress(QString newIP);
    void setLobbyPort(quint16 newPort);
    void setLobbyUserName(QString newUserName);
    void setLobbyInfoText(QString InfoText);
    void setLobbyCurrentUsersText(QString CurrentUsersText);

private slots:
    void setPlayerTypeTo(PLAYERTYPE newType);
    void screen0ButtonClicked(QAbstractButton *button);

private:
    // private functions
    void setUpScreen0();
    void setUpScreen1();
    void setUpScreen2();

    // player type (host/guest)
    PLAYERTYPE playerType;

    // pointers to the player of this game
    player *gamePlayer;
    host *gameHost;
    guest *gameGuest;

    // general GUI variables
    QStackedWidget *centralStackedWidget;
    QWidget *tempcentralWidget;
    QGridLayout *tempLayout;
    QComboBox *pageComboBox;
    QWidget *screenWidget[3];
    QLayout *screenLayout[3];
    QGridLayout *gl;
    QVBoxLayout *vl;
    QHBoxLayout *hl;

    // cosmetics
    QFont font_title;
    QFont font_header;
    QFont font_distinct;
    QSize size_tbInitial;

    //![0] screen 0 widgets
    QButtonGroup *bg_mainmenu;
    QPushButton *pb_hostGame;
    QPushButton *pb_joinGame;
    //![0]


    //![1] screen 1 widgets
    QGridLayout *gl_lobbyUsers,
    *gl_lobbyNetworkInfo,
    *gl_lobbyMainButtons;

    QLabel *l_lobby,
    *l_lobbyIPAddress,
    *l_lobbyPortNumber,
    *l_lobbyCurrentUsers,
    *l_lobbyCurrentUsernameDisp,
    *l_lobbyCurrentUsername,
    *l_lobbyEnterUserName;

    QTextBrowser *tb_lobbyInfo,
    *tb_lobbyCurrentUsers;

    QLineEdit *le_lobbyEnterUserName,
    *le_lobbyIPAddress,
    *le_lobbyPortNumber;

    QPushButton *pb_changeUserName,
    *pb_accept,
    *pb_start;
    //![1]


    //![2] screen 2 widgets
    QLineEdit *le_chatInput;
    QPushButton *pb_sendChat;
    //![2]

signals:
    void userNameChangeRequested();
};

#endif // GAME_H

#ifndef GAMEUI_H
#define GAMEUI_H

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

class gameUI : public QMainWindow
{
    Q_OBJECT
public:
    gameUI(QWidget *parent = 0);
    ~gameUI();

    enum PLAYERTYPE : quint8 {NONE, HOST, GUEST};

signals:
    void lobbyNetworkTextChanged();
    void lobbyEnterUserNameTextChanged();
    void userNameChangeRequested();
    void acceptSettingsClicked();
    void hostStartClicked();

public slots:

    // screen 1
    QString getLobbyIPAddressString();
    QString getLobbyPortString();
    QString getLobbyEnteredUserName();
    void setLobbyIPAddress(QString newIP);
    void setLobbyPort(quint16 newPort);
    void setLobbyEnterUserNameText(QString enteredNameText);
    void setLobbyCurrentUserName(QString newUserName);
    void setLobbyText(QString lobbyText);
    void setLobbyInfoText(QString infoText);
    void setLobbyCurrentUsersText(QString currentUsersText);
    void setLobbyIPAddressEnabled(bool enabled);
    void setLobbyPortEnabled(bool enabled);
    void setLobbyUserNameEnabled(bool enabled);
    void setLobbyChangeUserNameEnabled(bool enabled);
    void setLobbyAcceptEnabled(bool enabled);
    void setLobbyStartEnabled(bool enabled);

    // screen 2

private slots:
    void screen0ButtonClicked(QAbstractButton *button);
    void setPlayerTypeTo(PLAYERTYPE newType);

private:
    // private functions
    void setUpCosmetics();
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

    //![0]
    // screen 0 widgets
    QButtonGroup *bg_mainmenu;
    QPushButton *pb_hostGame;
    QPushButton *pb_joinGame;
    //![0]


    //![1]
    // screen 1 widgets
    QGridLayout *gl_lobbyUsers,
    *gl_lobbyNetworkInfo;

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


    //![2]
    // screen 2 widgets
    QLineEdit *le_chatInput;
    QPushButton *pb_sendChat;
    //![2]
};

#endif // GAMEUI_H

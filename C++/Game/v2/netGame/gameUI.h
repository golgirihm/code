#ifndef GAMEUI_H
#define GAMEUI_H

#include <QMainWindow>
#include <QWidget>

#define NUMBER_OF_SCREENS 3

namespace Ui {
class form_startscreen;
class form_lobby;
class form_maingame;
}

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

#include <QHostAddress>


class gameUI : public QMainWindow
{
    Q_OBJECT

//    /// allow player, host, and guest to access all gamueUI members
//    friend class player;
//    friend class host;
//    friend class guest;

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

    /// \todo: remove
    QPushButton *get_pb1_accept();
    QPushButton *get_pb1_changeUserName();


    /// screen 1
    QHostAddress get_le1_IPAddress();
    int get_le1_portNumber();
    QString get_le1_enterUserName();
    void set_le1_IPAddress(QHostAddress newIP);
    void set_le1_portNumber(quint16 newPort);
    void set_le1_enterUserName(QString enteredNameText);
    void set_l1_currentUsername(QString newUserName);
    void set_l1_lobby(QString lobbyText);
    void set_tb1_info(QString infoText);
    void set_tb1_currentUsers(QString currentUsersText);
    void setEnabled_le1_IPAddress(bool enabled);
    void setEnabled_le1_portNumber(bool enabled);
    void setEnabled_le1_enterUserName(bool enabled);
    void setEnabled_pb1_changeUserName(bool enabled);
    void setEnabled_pb1_accept(bool enabled);
    void setEnabled_pb1_start(bool enabled);

    /// screen 2


private slots:
    void ui0buttonclicked(QAbstractButton *button);
    void setPlayerTypeTo(PLAYERTYPE newType);

private:
    /// private functions
    void setUpCosmetics();
    void setUpUi0();
    void setUpUi1();
    void setUpUi2();

    /// player type (host/guest)
    PLAYERTYPE playerType;

    /// pointers to the player of this game
    player *gamePlayer;
    host *gameHost;
    guest *gameGuest;

    /// general GUI variables
    QStackedWidget *centralStackedWidget;
    QWidget *screenWidget[NUMBER_OF_SCREENS];
    Ui::form_startscreen *ui0;
    Ui::form_lobby *ui1;
    Ui::form_maingame *ui2;

    /// cosmetics
    QFont font_title;
    QFont font_header;
    QFont font_distinct;
    QSize size_tbInitial;

    /// \todo: REMOVE
    QWidget *tempcentralWidget;
    QLayout *tempLayout;
    QComboBox *pageComboBox;
};

#endif // GAMEUI_H

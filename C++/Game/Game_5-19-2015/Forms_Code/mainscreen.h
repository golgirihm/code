#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QDialog>

#include "../cardstack.h"

namespace Ui {
class mainscreen;
}

class mainscreen : public QDialog
{
    Q_OBJECT

public:
    explicit mainscreen(QWidget *parent = 0);
    ~mainscreen();
    void AppendToChatRoom(QString msg);
    QString GetChatInput();
    void ClearChatInput();
    void setUserName(QString UserName);

private:
    Ui::mainscreen *ui;

public slots:
    void SetHand(cardstack *Hand);
    void SetPlayersStatus(QString PlayersDisplay);
    void SetDeckCount(int NumDeckCards);
    void SetPlayedCard(card FaceUpCard);

signals:
    void ChatMessageReady();

};

#endif // MAINSCREEN_H

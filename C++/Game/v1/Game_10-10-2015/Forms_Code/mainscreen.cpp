#include "mainscreen.h"
#include "ui_mainscreen.h"

#include <QDebug>

mainscreen::mainscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainscreen)
{
    ui->setupUi(this);

    connect(ui->pb_send, SIGNAL(clicked()), this, SIGNAL(ChatMessageReady()));
}

mainscreen::~mainscreen()
{
//    qDebug() << "~mainscreen()";
    delete ui;
}

void mainscreen::AppendToChatRoom(QString msg)
{
    ui->tb_chat_output->append(msg);
}

QString mainscreen::GetChatInput()
{
    return ui->le_chat_input->text();
}

void mainscreen::ClearChatInput()
{
    ui->le_chat_input->clear();
}

void mainscreen::setUserName(QString UserName)
{
    ui->l_username->setText(UserName);
}

void mainscreen::SetHand(cardstack *Hand)
{
    int NumberInHand = Hand->NumberOfCards();
    ui->cb_choose_card->clear();

    QString CardsInHand = QString("Cards\n") +
                          QString("------");

    QString HandCard;
    for(int i = 0; i < NumberInHand; ++i)
    {
        HandCard = Hand->Look(i).CompressedString();
        CardsInHand += "\n " + HandCard;
        ui->cb_choose_card->addItem(HandCard);
    }

    ui->tb_your_hand->setText(CardsInHand);
}

void mainscreen::SetPlayersStatus(QString PlayersDisplay)
{
    ui->tb_player_list->setText(PlayersDisplay);
}

void mainscreen::SetDeckCount(int NumDeckCards)
{
    ui->tb_deck_cards->setText(QString::number(NumDeckCards) + " cards");
}

void mainscreen::SetPlayedCard(card FaceUpCard)
{
    ui->tb_playstack_card->setText(FaceUpCard.CompressedString());
}

#include "cardstack.h"
#include <QTime>
#include "card.h"

cardstack::cardstack(QObject *parent): QObject(parent)
{


}

cardstack::cardstack(const card& OnlyCard, QObject *parent) : QObject(parent)
{
    this->AddCard(OnlyCard);
}

cardstack::cardstack(const cardstack &other, QObject *parent) : QObject(parent)
{
    this->cards = other.cards;
    emit StackChanged(this);
}

cardstack::~cardstack()
{
    //    qDebug() << "~cardstack()";
}

cardstack &cardstack::operator =(const cardstack &other)
{
    this->cards = other.cards;
    emit StackChanged(this);
    return *this;
}

void cardstack::ToStandardDeck()
{
    card temp;

    for(int i = 0; i < NUMSUITS_STD; ++i)
    {
        for(int j = 0; j < NUMRANKS_STD; ++j)
        {
            temp.setCard(RANKS_STD[j], SUITS_STD[i]);
            cards.append(temp);
        }
    }

    emit StackChanged(this);
}

void cardstack::AddCard(const card &newCard)
{
    cards.append(newCard);
    emit StackChanged(this);
}

void cardstack::ClearStack()
{
    cards.clear();
    emit StackChanged(this);
}

void cardstack::Shuffle()
{
    qDebug() << "Shuffling . . .";

    int NumCards = this->NumberOfCards();

    // avoid division by zero during qrand() % Length
    if(!NumCards) return;

    // seed random numbers
    qsrand((uint)QTime::currentTime().msec());

    int i, j, inc = 1;
    int iterations = NumCards * RandShuf::SWEEPS;
    for(i = 0, j = 0; i < iterations; ++i)
    {
        cards.swap(j, qrand() % NumCards);

        j += inc;

        if(j == NumCards - 1 || j == 0)
            inc *= -1;
    }
}

card cardstack::Look(int position)
{
    // if deck has at least one card, and the selected position is valid
    if(position < NumberOfCards() && position >= 0)
        return cards[position];

    qDebug() << "warning, empty card handed out by Look(), no card at position " << position;
    return card();
}

card cardstack::TopCard()
{
    // look at the top card of the deck
    return this->Look(this->NumberOfCards() - 1);
}

card cardstack::TakeCard(int position)
{
    card RemovedCard;

    // if deck has at least one card, and the selected position is valid
    if(position < NumberOfCards() && position >= 0)
    {
        RemovedCard = cards.at(position);
        cards.removeAt(position);
        emit StackChanged(this);
        return RemovedCard;
    }

    qDebug() << "warning, empty card handed out by TakeCard(), no card at position " << position;
    return RemovedCard;
}

card cardstack::TakeTopCard()
{
    // take the top card from the deck
    return TakeCard(NumberOfCards() - 1);
}

int cardstack::NumberOfCards()
{
    return cards.length();
}

void cardstack::PrintCards()
{
    for(int i = 0; i < NumberOfCards(); ++i)
        qDebug() << "card " << i << "\t" << " is " << cards[i].getRankQChar() << " of " << cards[i].getSuitQChar();
}

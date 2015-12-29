#include "cardstack.h"
#include "card.h"
#include <QTime>

cardstack::cardstack()
{

}

cardstack::cardstack(const card& OnlyCard)
{
    addCard(OnlyCard);
    emit stackChanged(this);
}

cardstack::~cardstack()
{
    //    qDebug() << "~cardstack()";
}

cardstack &cardstack::operator =(const cardstack &other)
{
    cards = other.cards;
    emit stackChanged(this);
    return *this;
}

void cardstack::toStandardDeck()
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

    emit stackChanged(this);
}

void cardstack::addCard(const card &newCard)
{
    cards.append(newCard);
    emit stackChanged(this);
}

void cardstack::addCard(const QChar &NewRank, const QChar &NewSuit)
{
    // use other overload
    card temp(NewRank, NewSuit);
    addCard(temp);
}

void cardstack::clearStack()
{
    cards.clear();
    emit stackChanged(this);
}

void cardstack::shuffle()
{
    qDebug() << "Shuffling . . .";

    int NumCards = numberOfCards();

    // avoid division by zero during qrand() % Length
    if(!NumCards) return;

    // seed random numbers
    qsrand((uint)QTime::currentTime().msec());

    qint32 i, j, inc = 1;
    qint32 iterations = NumCards * SHUFFLE_SWEEPS;
    for(i = 0, j = 0; i < iterations; ++i)
    {
        cards.swap(j, qrand() % NumCards);

        j += inc;

        if(j == NumCards - 1 || j == 0)
            inc *= -1;
    }
}

card cardstack::look(int position) const
{
    // if deck has at least one card, and the selected position is valid
    if(position < numberOfCards() && position >= 0)
        return cards[position];

    qDebug() << "warning, empty card handed out by Look(), no card at position " << position;
    return card();
}

card cardstack::topCard() const
{
    // look at the top card of the deck
    return look(numberOfCards() - 1);
}

card cardstack::bottomCard() const
{
    // look at the bottom card of the deck
    return look(0);
}

card cardstack::takeCard(int position)
{
    card RemovedCard;

    // if deck has at least one card, and the selected position is valid
    if(position < numberOfCards() && position >= 0)
    {
        RemovedCard = cards.at(position);
        cards.removeAt(position);
        emit stackChanged(this);
        return RemovedCard;
    }

    qDebug() << "warning, empty card handed out by TakeCard(), no card at position " << position;
    return RemovedCard;
}

card cardstack::takeTopCard()
{
    // take the top card from the deck
    return takeCard(numberOfCards() - 1);
}

card cardstack::takeBottomCard()
{
    // take the bottom card from the deck
    return takeCard(0);
}

int cardstack::numberOfCards() const
{
    return cards.length();
}

QString cardstack::compressedString() const
{
    QString CardString;

    for(int i = 0; i < numberOfCards(); ++i)
        CardString += cards[i].compressedString();

    return CardString;
}

void cardstack::printCards() const
{
    for(int i = 0; i < numberOfCards(); ++i)
        qDebug() << "card " << i << "\t" << " is " << cards[i].getRankQChar() << " of " << cards[i].getSuitQChar();
}


QDataStream& operator <<(QDataStream &out, const cardstack &stack)
{
    return out << stack.compressedString().toLatin1();
}


void operator >>(QDataStream &in, cardstack &stack)
{
    char* Latin1_StackString;
    in >> Latin1_StackString;

    QString StackString(Latin1_StackString);

    // find out the length of the string to parse
    quint16 StringLength = StackString.length();

    if(StringLength % 2)
    {
        --StringLength;
        qDebug() << "Warning, QDataStream &operator >>(QDataStream &in, cardstack &stack): CHARACTER TAKEN OFF END OF STRING RECEIVED FROM STREAM, ODD NUMBER OF CHARS";
    }

    // parse string from stream and add to stack
    for(quint16 i = 0; i < StringLength; i += 2)
        stack.addCard(StackString[i], StackString[i+1]);
}

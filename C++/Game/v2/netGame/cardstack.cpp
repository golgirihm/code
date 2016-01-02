#include "cardstack.h"
#include "card.h"
#include <QTime>

const card cardstack::EMPTY_CARD;

cardstack::cardstack()
{

}

cardstack::cardstack(const card& OnlyCard)
{
    addCard(OnlyCard);
}

cardstack::cardstack(const cardstack &other) : QObject(this)
{
    *this = other;
}

cardstack::~cardstack()
{
//    qDebug() << "~cardstack()";
}

cardstack &cardstack::operator=(const cardstack &other)
{
    cards = other.cards;
    emit stackChanged(this);
    return *this;
}

bool cardstack::operator==(const cardstack &other)
{
    if(numberOfCards() != other.numberOfCards())
        return false;

    for(quint32 i = 0; i < numberOfCards(); ++i)
    {
        if((cards.at(i) != other.cards.at(i)))
            return false;
    }

    return true;
}

bool cardstack::operator!=(const cardstack &other)
{
    return !(*this == other);
}

void cardstack::toStandardDeck()
{
    card temp;

    for(quint32 i = 0; i < NUMSUITS_STD; ++i)
    {
        for(quint32 j = 0; j < NUMRANKS_STD; ++j)
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

void cardstack::addCard(const card::R_t &NewRank, const card::S_t &NewSuit)
{
    // use other overload
    addCard(card(NewRank, NewSuit));
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

    qint32 i, curPos, inc = 1;
    qint32 iterations = NumCards * cardstack::SHUFFLE_SWEEPS;
    for(i = 0, curPos = 0; i < iterations; ++i)
    {
        cards.swap(curPos, qrand() % NumCards);

        // add to or subtract from the current position in the cardstack
        curPos += inc;

        // switch direction
        if((curPos == NumCards - 1) || (curPos == 0))
            inc *= -1;
    }

    emit stackChanged(this);
}

const card &cardstack::look(const quint32 &position) const
{
    // if deck has at least one card, and the selected position is valid
    if(position < numberOfCards())
        return cards[position];

    qDebug() << "warning, empty card handed out by Look(), no card at position " << position;
    return cardstack::EMPTY_CARD;
}

const card &cardstack::topCard() const
{
    // look at the top card of the deck
    return look(numberOfCards() - 1);
}

const card &cardstack::bottomCard() const
{
    // look at the bottom card of the deck
    return look(0);
}

const card cardstack::takeCard(const quint32 &position)
{
    card RemovedCard;

    // if the selected position is valid
    if(position < numberOfCards())
    {
        RemovedCard = cards.takeAt(position);
        emit stackChanged(this);
        return RemovedCard;
    }

    qDebug() << "warning, empty card handed out by TakeCard(), no card at position " << position;
    return cardstack::EMPTY_CARD;
}

const card cardstack::takeTopCard()
{
    // take the top card from the deck
    return takeCard(numberOfCards() - 1);
}

const card cardstack::takeBottomCard()
{
    // take the bottom card from the deck
    return takeCard(0);
}

quint32 cardstack::numberOfCards() const
{
    return cards.length();
}

QString cardstack::compressedString() const
{
    QString CardString;

    for(quint32 i = 0; i < numberOfCards(); ++i)
        CardString += cards[i].compressedString();

    return CardString;
}

void cardstack::printCards() const
{
    for(quint32 i = 0; i < numberOfCards(); ++i)
        qDebug() << "card " << i << "\tis " << QChar(cards[i].getRank()) << " of " << QChar(cards[i].getSuit());
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
    for(quint32 i = 0; i+1 < StringLength; i += 2)
        stack.addCard(static_cast<card::R_t>(StackString.at(i).toLatin1()), static_cast<card::S_t>(StackString.at(i+1).toLatin1()));
}

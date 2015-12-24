#include "cardstack.h"
#include <QTime>
#include "card.h"

cardstack::cardstack()
{

}

cardstack::cardstack(const card& OnlyCard)
{
    AddCard(OnlyCard);
    emit StackChanged(this);
}

cardstack::cardstack(const cardstack &other)
{
    cards = other.cards;
    emit StackChanged(this);
}

cardstack::~cardstack()
{
    //    qDebug() << "~cardstack()";
}

cardstack &cardstack::operator =(const cardstack &other)
{
    cards = other.cards;
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

void cardstack::AddCard(const QChar &NewRank, const QChar &NewSuit)
{
    // use other overload
    card temp(NewRank, NewSuit);
    AddCard(temp);
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

card cardstack::Look(int position) const
{
    // if deck has at least one card, and the selected position is valid
    if(position < NumberOfCards() && position >= 0)
        return cards[position];

    qDebug() << "warning, empty card handed out by Look(), no card at position " << position;
    return card();
}

card cardstack::TopCard() const
{
    // look at the top card of the deck
    return this->Look(this->NumberOfCards() - 1);
}

card cardstack::BottomCard() const
{
    // look at the bottom card of the deck
    return this->Look(0);
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

card cardstack::TakeBottomCard()
{
    // take the bottom card from the deck
    return TakeCard(0);
}

int cardstack::NumberOfCards() const
{
    return cards.length();
}

QString cardstack::CompressedString() const
{
    QString CardString;

    for(int i = 0; i < NumberOfCards(); ++i)
        CardString += cards[i].CompressedString();

    return CardString;
}

void cardstack::PrintCards() const
{
    for(int i = 0; i < NumberOfCards(); ++i)
        qDebug() << "card " << i << "\t" << " is " << cards[i].getRankQChar() << " of " << cards[i].getSuitQChar();
}


QDataStream& operator <<(QDataStream &out, const cardstack &stack)
{
    return out << stack.CompressedString().toLatin1();
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
        stack.AddCard(StackString[i], StackString[i+1]);
}

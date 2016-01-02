#include "card.h"

card::card()
{
//    qDebug() << "card() made an empty card";
    setCard(R_t::NO_RANK, S_t::NO_SUIT);
}

card::card(R_t NewRank, S_t NewSuit)
{
    setCard(NewRank, NewSuit);
}

card::~card()
{
//    qDebug() << "~card() was: " << compressedString();
}

card &card::operator =(const card &other)
{
    setCard(other.rank, other.suit);
    return *this;
}

bool card::operator ==(const card &other) const
{
    return((getRank() == other.getRank()) && (getSuit() == other.getSuit()));
}

bool card::operator!=(const card &other) const
{
    return !(*this == other);
}

void card::setRank(R_t NewRank)
{
    rank = NewRank;
}

void card::setSuit(S_t NewSuit)
{
    suit = NewSuit;
}

void card::setCard(R_t NewRank, S_t NewSuit)
{
    setRank(NewRank);
    setSuit(NewSuit);
}

const card::S_t &card::getSuit() const
{
    return suit;
}

const card::R_t &card::getRank() const
{
    return rank;
}

QString card::compressedString() const
{
    return QString(rank) + QString(suit);
}

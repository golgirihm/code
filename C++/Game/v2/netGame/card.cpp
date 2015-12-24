#include "card.h"

card::card()
{
//    qDebug() << "card() made an empty card";
    setCard(R_t::NO_RANK, S_t::NO_SUIT);
}

card::card(QChar NewRank, QChar NewSuit)
{
    setCard(NewRank, NewSuit);
}

card::card(QByteArray bytes)
{
    QChar rank_QChar;
    QChar suit_QChar;

    QDataStream stream(bytes);

    stream >> rank_QChar;
    stream >> suit_QChar;

    setCard(rank_QChar, suit_QChar);

    qDebug() << endl << "card(bytes) constructor: card == " << getRankQChar() << getSuitQChar();
}

card::~card()
{
    //    qDebug() << "~card()";
}

card &card::operator =(const card &other)
{
    setCard(other.suit, other.rank);
    return *this;
}

QByteArray card::bytes()
{
    QByteArray buffer;
    QDataStream stream(&buffer, QIODevice::WriteOnly);

    stream << QChar(rank);
    stream << QChar(suit);

    return buffer;
}

void card::setSuit(QChar NewSuit)
{
    suit = QChar(NewSuit);
}

void card::setRank(QChar NewRank)
{
    rank = QChar(NewRank);
}

void card::setCard(QChar NewRank, QChar NewSuit)
{
    rank = QChar(NewRank);
    suit = QChar(NewSuit);
}

QChar card::getSuitQChar() const
{
    return suit;
}

QChar card::getRankQChar() const
{
    return rank;
}

QString card::CompressedString() const
{
    return QString(rank) + QString(suit);
}

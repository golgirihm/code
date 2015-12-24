#include "card.h"

card::card()
{
//    qDebug() << "card() made an empty card";
    rank = NO_RANK;
    suit = NO_SUIT;
}

card::card(QChar NewRank, QChar NewSuit)
{
    rank = QChar(NewRank);
    suit = QChar(NewSuit);
}

card::~card()
{
    //    qDebug() << "~card()";
}

card &card::operator =(const card &other)
{
    this->suit = other.suit;
    this->rank = other.rank;
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

card::card(QByteArray bytes)
{
    QDataStream stream(bytes);

    QChar rank_QChar;
    QChar suit_QChar;

    stream >> rank_QChar;
    stream >> suit_QChar;

    this->setCard(rank_QChar, suit_QChar);

    qDebug() << endl << "card(bytes) constructor: card == " << this->getRankQChar() << this->getSuitQChar();
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

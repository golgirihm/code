#ifndef CARD_H
#define CARD_H

#include <QDebug>

// suits
enum S_t : char
{
    SPADES = 'S',
    DIAMONDS = 'D',
    CLUBS = 'C',
    HEARTS = 'H',
    NO_SUIT = 'Z'
};

static const S_t SUITS_STD[] = { SPADES, DIAMONDS, CLUBS, HEARTS };
const int NUMSUITS_STD ((int)(sizeof(SUITS_STD) / sizeof(*SUITS_STD)));

// values
enum R_t : char
{
    ACE = 'A',
    TWO = '2',
    THREE = '3',
    FOUR = '4',
    FIVE = '5',
    SIX = '6',
    SEVEN = '7',
    EIGHT = '8',
    NINE = '9',
    TEN = 'T',
    JACK = 'J',
    QUEEN = 'Q',
    KING = 'K',
    NO_RANK = 'Z'
};

static const R_t RANKS_STD[] = { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
const int NUMRANKS_STD ((int)(sizeof(RANKS_STD) / sizeof(*RANKS_STD)));

class card
{
public:
    card();
    card(QChar NewRank, QChar NewSuit);
    ~card();

    card(QByteArray bytes);
    QByteArray bytes();
    card &operator = (const card &other);

private:
    QChar rank;
    QChar suit;

signals:

public slots:
    void setSuit(QChar NewSuit);
    void setRank(QChar NewRank);
    void setCard(QChar NewRank, QChar NewSuit);
    QChar getSuitQChar() const;
    QChar getRankQChar() const;
    QString CompressedString() const;
};


#endif // CARD_H

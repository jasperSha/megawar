#pragma once
#include <iostream>
#include <string>


class Card {
    public:
        enum class Rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, End};
        enum class Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

        Card::Rank getRank() const;
        Card::Suit getSuit() const;

        std::string toString() const;

        Card(Rank r, Suit s);

        int getValue() const;

        friend bool operator>(const Card& first, const Card& second);
        friend bool operator<(const Card& first, const Card& second);
        friend bool operator==(const Card& first, const Card& second);

        friend Card* crd_compare(const Card& first, const Card& second);

        friend std::ostream& operator<<(std::ostream& out, Card& c);
        

        ~Card() {};

    protected:
        Rank rank;
        Suit suit;
        

};
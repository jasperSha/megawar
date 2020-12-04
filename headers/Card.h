#pragma once
#include <iostream>
#include <string>


class Card {
    protected:
        enum class Rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, End};
        enum class Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

        Rank rank;
        Suit suit;


        
    public:

        Card::Rank getRank() const;
        Card::Suit getSuit() const;

        std::string toString() const;

        Card(Rank r, Suit s);
        Card(int r, int s);

        int getValue() const;

        friend bool operator>(const Card& first, const Card& second);
        friend bool operator<(const Card& first, const Card& second);
        friend bool operator==(const Card& first, const Card& second);


        friend std::ostream& operator<<(std::ostream& out, Card& c);
        

        ~Card() {};


};
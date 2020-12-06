#pragma once
#include <iostream>
#include <string>


class Card {
    protected:
        enum Rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, RANKEND};
        enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES, SUITEND};
        
        Rank rank;
        Suit suit;


        
    public:
        Card();
        Card(Rank r, Suit s);

        Card::Rank getRank() const;
        Card::Suit getSuit() const;

        std::string toString() const;


        int getValue() const;

        friend bool operator>(const Card& first, const Card& second);
        friend bool operator<(const Card& first, const Card& second);
        friend bool operator==(const Card& first, const Card& second);


        friend std::ostream& operator<<(std::ostream& out, const Card& c);
        

        ~Card();


};
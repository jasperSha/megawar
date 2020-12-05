#pragma once
#include "Card.h"
#include <vector>


class CardPile {
    public:
        CardPile() {};

        void add(Card c);
        Card remove();
        
        int getCount() const;
    
        ~CardPile() {};

    protected:
        std::vector<Card> storage;
};
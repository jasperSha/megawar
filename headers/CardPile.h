#pragma once
#include "Card.h"
#include <vector>


class CardPile {
    public:
        CardPile();

        void add();
        Card remove();
        
        int getCount() const;
    
        ~CardPile() {};

    protected:
        std::vector<Card> pile;
};
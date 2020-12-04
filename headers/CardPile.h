#pragma once
#include "Card.h"
#include <vector>


class CardPile {
    public:
        CardPile();
        CardPile(std::vector<Card> cds);

        void add();
        Card remove();
        
        int getCount() const;
    
        ~CardPile() {};

    protected:
        std::vector<Card> pile;
};
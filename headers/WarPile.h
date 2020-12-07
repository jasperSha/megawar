#pragma once
#include "CardPile.h"
#include <vector>

class WarPile: public CardPile {
    public:
        WarPile() {};
        
        std::vector<Card> dump();
        
        /*  @param: range of cards to check for max
        *   @return vector : vector of indices of players who played a max card
        *
        */
        std::vector<int> findWinners(int range);

        virtual void display() const;
};
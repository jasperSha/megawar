#pragma once
#include "CardPile.h"
#include "Player.h"
#include <vector>

class LostFound: public CardPile {
    public:
        LostFound();

        void add(); //extends CardPile::add()

        void reward(Player& p); //pop all cards from pile for winner, extends CardPile::remove()

        int getCount() const; //check if any cards in lost and found for war winners extends CardPile::getCount()

        ~LostFound() {};

    protected:
        std::vector<Card> spoils;

};
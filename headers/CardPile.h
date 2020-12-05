#pragma once
#include "Card.h"
#include <vector>


class CardPile {
    public:
        CardPile() {};

        virtual void add(Card c);
        virtual Card remove();
        virtual int getCount() const;

    protected:
        std::vector<Card> storage;
};
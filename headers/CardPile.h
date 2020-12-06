#pragma once
#include "Card.h"
#include <vector>


class CardPile {
    public:
        CardPile();
        virtual ~CardPile();

        void add(Card c);
        Card remove();
        int getCount() const;

    protected:
        std::vector<Card> storage;
};
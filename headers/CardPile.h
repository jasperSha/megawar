#pragma once
#include "Card.h"
#include <vector>


class CardPile {
    public:
        CardPile();
        virtual ~CardPile();
        virtual void display() const = 0;
        virtual void resize(int newCapacity);

        virtual std::vector<Card> remove(int numCards);
        virtual void add(std::vector<Card> pile);

        int getCount() const;

    protected:
        std::vector<Card> storage;
};
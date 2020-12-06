#pragma once
#include "CardPile.h"

class WarPile: public CardPile {
    public:
        WarPile() {};
        virtual void display() const;
};
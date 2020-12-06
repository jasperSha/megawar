#pragma once
#include "CardPile.h"

class LostFound: public CardPile {
    public:
        LostFound();

        virtual void display() const;
};
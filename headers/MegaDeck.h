#pragma once
#include <vector>
#include "Deck.h"
#include "Player.h"
#include "Card.h"

class MegaDeck: public CardPile {
    public:


        MegaDeck() {};

        MegaDeck(std::vector<Deck> d, std::vector<Player> p);

        void buildGame();
        void dealCards(); //given total number of players, then distributes decks equally among them

        virtual void display() const override;

    protected:
        std::vector<Deck> decks;
        std::vector<Player> players;
};
#pragma once
#include <vector>
#include "Deck.h"
#include "Player.h"

class MegaDeck {
    public:
        MegaDeck();

        MegaDeck(std::vector<Deck> d);

        void distributeCards(int playerCount); //given total number of players, then distributes decks equally among them

        ~MegaDeck() {};
    
    protected:
        std::vector<Deck> decks;

};
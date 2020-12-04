#pragma once
#include <vector>
#include "Deck.h"
#include "Player.h"

class MegaDeck {
    public:
        MegaDeck();

        MegaDeck(std::vector<Deck> d);

        void dealCards(); //given total number of players, then distributes decks equally among them

        ~MegaDeck() {};
    
    protected:
        std::vector<Deck> decks;
        std::vector<Player> players;
        std::vector<Card> megaDeck;

};
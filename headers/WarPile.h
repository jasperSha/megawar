#pragma once
#include "CardPile.h"
#include "Player.h"
#include <vector>

class WarPile: public CardPile {
    public:
        WarPile();

        void add(); //extends CardPile::add()
        void reward(Player& p); //extends CardPile::remove()

        std::vector<Player>& determineWinner(); //return vector of players with top cards in warpile
        int getCount() const; //extends CardPile::getCount()

        ~WarPile() {};
    
    protected:
        std::vector<Card> loot;
        std::vector<Player> warPlayers;


};
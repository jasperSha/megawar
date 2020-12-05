#pragma once
#include "CardPile.h"
#include "Player.h"
#include <vector>

class WarPile: public CardPile {
    public:
        WarPile();

        virtual void add(Card c); //extends CardPile::add()
        void reward(Player& p); //extends CardPile::remove()

        std::vector<Player>& determineWinner(); //return vector of players with top cards in warpile
        virtual int getCount() const; //extends CardPile::getCount()
    
    protected:
        std::vector<Card> loot;
        std::vector<Player> warPlayers;


};
#pragma once
#include "CardPile.h"


class Player: public CardPile {

    public:
        Player() {};
        Player(int id);

        int getPlayerID() const;

        double getFierceness();

        void updateGameStats(bool won);
        void getStats();
        
        int getHandCount() const; //extends CardPile::getCount() const

        void receiveCard(Card c); //extends CardPile::add()
        Card& playCard(); //extends CardPile::remove()

        ~Player() {};

    protected:
        int playerID;
        int battlesPlayed;
        int battlesWon;

};
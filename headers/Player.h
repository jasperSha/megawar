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
        
        virtual int getCount() const; //extends CardPile::getCount() const

        virtual void add(Card c); //extends CardPile::add()
        virtual Card remove(); //extends CardPile::remove()

    protected:
        int playerID;
        int battlesPlayed;
        int battlesWon;

};
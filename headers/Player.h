#pragma once
#include "CardPile.h"
#include "Card.h"


class Player: public CardPile {

    public:
        Player();
        Player(int id);

        // int getPlayerID() const;

        // double getFierceness();

        // void updateGameStats(bool won);
        // void getStats();
        
        // virtual int getCount() const; //extends CardPile::getCount() const

        void add(Card c); //extends CardPile::add()
        Card remove(); //extends CardPile::remove()
        ~Player();

    protected:
        int playerID;
        int battlesPlayed;
        int battlesWon;

};
#pragma once
#include "CardPile.h"
#include "Card.h"


class Player: public CardPile {

    public:
        Player();
        Player(int id);
        ~Player();

        int getPlayerID() const;
        double getFierceness();

        void updateGameStats(bool won);
        void getStats();


    protected:
        int playerID;
        int battlesPlayed;
        int battlesWon;

};
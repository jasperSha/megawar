#pragma once
#include "CardPile.h"
#include "Card.h"


class Player: public CardPile {

    public:
        Player();
        Player(int id);
        ~Player();

        int getPlayerID() const;
        double getFierceness() const;

        void updateGameStats(bool won);
        void getStats() const;

        virtual void display() const override;

    protected:
        int playerID;
        int battlesPlayed;
        int battlesWon;

};
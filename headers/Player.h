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
        void addToFront(std::vector<Card> pile);

        void won();
        void updateGameStats();
        void getStats() const;

        bool available();

        virtual void display() const override;

    protected:
        int playerID;
        int battlesPlayed;
        int battlesWon;

        bool winner;

};
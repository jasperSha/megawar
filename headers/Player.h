#pragma once
#include "CardPile.h"


class Player: public CardPile {

    public:
        Player();
        Player(int id);

        int getPlayerID() const;

        double getFierceness() const;

        void updateStats();
        int getBattlesPlayed() const;
        int getBattlesWon() const;
        
        int getHandCount() const; //extends CardPile::getCount() const

        void receiveCard(Card& c); //extends CardPile::add()
        Card& playCard(); //extends CardPile::remove()

        ~Player() {};

    protected:
        std::vector<Card> hand;

        int playerID;
        double fierceness;
        int battlesPlayed;
        int battlesWon;

};
#include "../headers/Player.h"
#include <iostream>
#include <cmath>

Player::Player(int id) {
    playerID = id;
}

int Player::getPlayerID() const {
    return playerID;
}

void Player::receiveCard(Card c) {
    CardPile::add(c);
}

double Player::getFierceness() {
    int handCount = CardPile::getCount();
    double fierceness = 0;
    for (int i = 0; i < handCount; i++) {
        fierceness += storage[i].getValue();
    }
    fierceness /= handCount;
    return std::ceil(fierceness * 100.0) / 100.0;
}


void Player::updateGameStats(bool won) {
    if (won) {
        battlesWon++;
    }
    battlesPlayed++;
}

void Player::getStats() {
    std::cout << "Player " << playerID << ": Fierceness = "
              << getFierceness() << "Cards = " << CardPile::getCount()
              << "Battles = " << battlesPlayed << " Won = "
              << battlesWon;
}
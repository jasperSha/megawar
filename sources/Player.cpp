#include "../headers/Player.h"
#include <iostream>
#include <cmath>

Player::Player() {
    playerID = -1;
}
Player::~Player() {}

Player::Player(int id) {
    playerID = id;
}

int Player::getPlayerID() const {
    return playerID;
}

double Player::getFierceness() {
    std::cout << "getting fierceness" << std::endl;
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
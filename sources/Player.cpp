#include "../headers/Player.h"
#include <iostream>
#include <cmath>

Player::Player() {
    playerID = -1;
    battlesPlayed = 0;
    battlesWon = 0;
}
Player::~Player() {}

Player::Player(int id) {
    playerID = id;
    battlesPlayed = 0;
    battlesWon = 0;
}

int Player::getPlayerID() const {
    return playerID;
}

double Player::getFierceness() const{
    int handCount = getCount();
    if (handCount == 0)
        return 0;
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

void Player::getStats() const{
    std::cout << "\nPlayer " << playerID << ": Fierceness = "
              << getFierceness() << " Cards = " << getCount()
              << " Battles = " << battlesPlayed << " Won = "
              << battlesWon;
}

void Player::display() const {
    for (int i = 0; i < storage.size(); i++) {
        std::cout << "Player " << playerID << "'s hand: " << storage[i] << ' ';
    }
}
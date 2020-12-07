#include "../headers/Player.h"
#include <iostream>
#include <cmath>
#include <iomanip>

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

void Player::addToFront(std::vector<Card> pile) {
    for (auto& c : pile) {
        storage.insert(storage.begin(), c);
    }
}

bool Player::available() {
    if (getCount() > 0)
        return true;
    return false;
} 


void Player::won() {
    winner = true;
}


void Player::updateGameStats() {
    if (winner) {
        battlesWon++;
        winner = false;
    }
    battlesPlayed++;
}

void Player::getStats() const{
    std::cout << "\nPlayer " << playerID << ": Fierceness = "
              << std::fixed << std::setprecision(2) << std::setw(5)
              << getFierceness() 
              << std::setw(9) << std::left
              << " Cards = " << std::setw(4)
              << getCount()
              << std::setw(10) << std::right
              << " Battles = " 
              << std::left << std::setw(4)
              << battlesPlayed
              << std::setw(6)
              << " Won = "
              << std::setw(5)
              << battlesWon;
}

void Player::display() const {
    std::cout << "Player " << playerID << "'s hand: ";
    for (int i = 0; i < storage.size(); i++) {
         std::cout << storage[i] << ' ';
    }
}
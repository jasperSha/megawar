#include "../headers/Player.h"
#include <iostream>
#include <cmath>

Player::Player() {}
Player::Player(int id) {
    playerID = id;
}
Player::~Player() {}

// int Player::getPlayerID() const {
//     return playerID;
// }

// int Player::getCount() const {
//     return CardPile::getCount();
// }

// void Player::add(Card c) {
//     CardPile::add(c);
// }
// Card Player::remove() {
//     return CardPile::remove();
// }

// double Player::getFierceness() {
//     int handCount = CardPile::getCount();
//     double fierceness = 0;
//     for (int i = 0; i < handCount; i++) {
//         fierceness += storage[i].getValue();
//     }
//     fierceness /= handCount;
//     return std::ceil(fierceness * 100.0) / 100.0;
// }


// void Player::updateGameStats(bool won) {
//     if (won) {
//         battlesWon++;
//     }
//     battlesPlayed++;
// }

// void Player::getStats() {
//     std::cout << "Player " << playerID << ": Fierceness = "
//               << getFierceness() << "Cards = " << CardPile::getCount()
//               << "Battles = " << battlesPlayed << " Won = "
//               << battlesWon;
// }
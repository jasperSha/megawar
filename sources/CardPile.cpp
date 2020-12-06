#include "../headers/CardPile.h"
#include "../headers/Card.h"
#include <vector>

CardPile::CardPile() 
{}
CardPile::~CardPile() 
{}

void CardPile::add(std::vector<Card> pile) {
    storage.insert(std::end(storage), std::begin(pile), std::end(pile));
}

std::vector<Card> CardPile::remove(int numCards) {
    std::vector<Card> pile;
    for (int i = 0; i < numCards; i++) {
        Card top = storage.back();
        pile.push_back(top);
        storage.pop_back();
    }
    return pile;
}

void CardPile::resize(int newCapacity) {
    storage.resize(newCapacity);
}

int CardPile::getCount() const {
    return storage.size();
}


#include "../headers/CardPile.h"
#include "../headers/Card.h"

CardPile::CardPile() 
{}
CardPile::~CardPile() 
{}

void CardPile::add(Card c) {
    storage.push_back(c);
}

Card CardPile::remove() {
    Card top = storage.back();
    storage.pop_back();
    return top;
}

int CardPile::getCount() const {
    return storage.size();
}


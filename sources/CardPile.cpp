#include "../headers/CardPile.h"

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
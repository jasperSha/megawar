#include "../headers/WarPile.h"

void WarPile::add(Card& c) {
    CardPile::add(c);
}

void WarPile::reward(Player& p) {
    Card award = CardPile::remove();
    p.receiveCard(award);
}
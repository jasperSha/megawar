#include "../headers/WarPile.h"

void WarPile::reward(Player& p) {
    Card award = CardPile::remove();
    p.add(award);
}

#include <iostream>
#include "../headers/Card.h"
#include "../headers/WarPile.h"

void WarPile::display() const {
    std::cout << "The WarPile loot: ";
    for (int i = 0; i < storage.size(); i++) {
        std::cout << storage[i] << ' ';
    }
}
#include <iostream>
#include "../headers/Card.h"
#include "../headers/WarPile.h"

void WarPile::display() const {
    std::cout << "The WarPile loot: ";
    for (int i = 0; i < storage.size(); i++) {
        std::cout << storage[i] << ' ';
    }
}

std::vector<Card> WarPile::dump() {
    return this->remove(this->getCount());
}

std::vector<int> WarPile::findWinners(int range) {
    std::vector<int> playerIndex;
    std::size_t totalElementCount = getCount();

    int first = totalElementCount - range;
    int max = storage[first].getValue();

    for (int i = first; i < totalElementCount; i++) {
        if (storage[i].getValue() > max) {
            max = storage[i].getValue();
        }
    }
    //now find players who match the max
    for (int i = first; i < totalElementCount; i++) {
        if (storage[i].getValue() == max) {
            playerIndex.push_back(i - first); //need index relative to the range, not entire warpile
        }
    }
    return playerIndex;
}

/*
arr = [5, 6, 7, 8, 9]
range = 3
getcount == 5
first = 5 - 3 = 2
for int i = 2; i < 5; i++
    if max:
        max = storage[i].value
        index.append(i)



*/


#include "../headers/Card.h"
#include "../headers/LostFound.h"
#include <iostream>

void LostFound::display() const {
    std::cout << "The Lost and Found pile: ";
    for (int i = 0; i < storage.size(); i++)
        std::cout << storage[i] << ' ';
}
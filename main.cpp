#include <iostream>
#include "./headers/Card.h"

int main() {
    Card c1(Card::Rank::ACE, Card::Suit::CLUBS);

    std::cout << c1 << std::endl;
    std::cout << c1.getValue() << std::endl;
    
    return 0;
}
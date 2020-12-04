#include <iostream>
#include "./headers/Card.h"
#include "./headers/Deck.h"
#include "./headers/CardPile.h"
#include "./headers/MegaDeck.h"


int main() {
    
    Deck deckOne, deckTwo;

    deckOne.shuffle();
    deckTwo.shuffle();

    deckTwo.showDeck();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    Card c = deckTwo.deal();
    std::cout << c << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    deckTwo.showDeck();
    
    return 0;
}
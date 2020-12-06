#include "../headers/MegaDeck.h"
#include <vector>

const int CARDS_PER_DECK = 52;

MegaDeck::MegaDeck(std::vector<Deck> d, std::vector<Player> p) {
    decks = d;
    players = p;
}

void MegaDeck::dealCards() {
    int totalDecks = decks.size();
    int totalPlayers = players.size();

    int totalCardCount = totalDecks * CARDS_PER_DECK;

    for (int i = 0; i < totalDecks; i++) {
        decks[i].shuffle();
    }

    //dividing cards equally among players requires discarding remainder
    int remainder = totalCardCount % totalPlayers;
    
    //for each deck, deal the whole deck to the one stack
    for (int i = 0; i < totalDecks; i++) {
        for (int j = 0; j < CARDS_PER_DECK; j++)
            megaDeck.push_back(decks[i].remove());
    }

    //get rid of extra cards
    megaDeck.resize(totalCardCount - remainder);
    
    int count = 0;
    while (count < totalCardCount) {
        for (int j = 0; j < totalPlayers; j++) {
            players[j].add(megaDeck[count++]);
        }
    }
    
}

void MegaDeck::display() {
    for (int i = 0; i < decks.size(); i++)
        players[i].getStats();  
} 
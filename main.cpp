#include "./headers/Card.h"
#include "./headers/Deck.h"
#include "./headers/CardPile.h"
#include "./headers/MegaDeck.h"
#include "./headers/WarPile.h"
#include "./headers/Player.h"
#include "./headers/LostFound.h"

#include <iostream>


MegaDeck buildGame() {
    int numPlayers, numDecks;
    std::cout << "How many players? ";
    std::cin >> numPlayers;
    std::cout << "How many decks? ";
    std::cin >> numDecks;

    std::vector<Player> players;
    std::vector<Deck> decks;

    for (int i = 0; i < numPlayers; i++) {
        Player p(i+1);
        players.push_back(p);
    }
    for (int i = 0; i < numDecks; i++) {
        Deck d;
        decks.push_back(d);
    }

    MegaDeck mega(decks, players);
    return mega;
}




int main() {
    MegaDeck mega = buildGame();
    mega.dealCards();
    mega.display();
    mega.playGame();
    std::cout << std::endl;

    return 0;
}
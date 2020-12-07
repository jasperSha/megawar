#include "../headers/MegaDeck.h"
#include <vector>
#include <algorithm>


const int CARDS_PER_DECK = 52;
const int TOP_OF_DECK = 1;

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
    totalCardCount -= remainder;
    //for each deck, deal the whole deck to the one stack
    for (int i = 0; i < totalDecks; i++) {
        for (int j = 0; j < CARDS_PER_DECK; j++)
            add(decks[i].remove(TOP_OF_DECK));
    }
    //get rid of extra cards
    this->resize(totalCardCount);
    int count = 0;
    while (count < totalCardCount) {
        for (int j = 0; j < totalPlayers; j++) {
            players[j].add(this->remove(TOP_OF_DECK));
            count++;
        }
    }
    
}


/*
TODO: CHANGE DISPLAY TO DISPALY GAME SETTINGS
*/

void MegaDeck::display() const {
    for (int i = 0; i < players.size(); i++) {
        players[i].getStats();  
    }
} 

void MegaDeck::buildGame() {

}

/*
    Round: Each player lays down one card. Player with highest card wins the pile.
            Players who have highest hand && same value enter a war.
            war(players, original_hands):
            if any players have no more cards, they immediately drop out of game.
            if no players left, all cards -> Lost_found
            else
                each remaining player plays 4 cards -> highest fourth card wins all cards. 
                if a tie: enter war(players, original_hands+4_cards_each)
    
    params:
            players with hands
*/

void MegaDeck::war(std::vector<Player*> warMongers, WarPile& wp, LostFound& lf) {
    //everyone lost
    if (warMongers.size() == 0) {
        lf.add(wp.dump());
        return;
    }

    //winner takes all
    if (warMongers.size() == 1) {
        (*warMongers[0]).addToFront(wp.dump());
        (*warMongers[0]).addToFront(lf.dump());
        (*warMongers[0]).won();
        return;
    }

    //players who do not have enough to continue
    int lostIndex = 0;
    std::vector<int> losers;
    for (int i = 0; i < warMongers.size(); i++) {
        int hand = (*warMongers[i]).getCount();
        if (hand < 4 && hand > 0) {
            wp.add((*warMongers[i]).remove(hand));
            losers.push_back(lostIndex); //indexing to remove from WarMongers later
        }
        else if (hand >= 4)
            wp.add((*warMongers[i]).remove(3));
        lostIndex++;
    }
    
    //sort to descending order for remove_if to work
    std::sort(losers.begin(), losers.end(), std::greater <>());

    //removes players unable to play more war(does not preserve order of WarMongers)
    //must remove with indicies in descending order ( last elements first)
    for (const auto& lost : losers) {
        warMongers[lost] = warMongers.back();
        warMongers.pop_back();
    }

    int warMongerCount = warMongers.size();
    for (int i = 0; i < warMongerCount; i++) {
        wp.add((*warMongers[i]).remove(1));
    }
    
    //player range is players left playing; find max card value of those cards that were
    //played (e.g., 4 players left, find the max of the 4 cards added to warpile)
    //vector of indices of players who won
    std::vector<int> winnerIndices = wp.findWinners(warMongerCount);
    std::vector<Player*> newWarMongers;

    for (auto& i : winnerIndices) {
        newWarMongers.push_back(warMongers[i]);
    }

    warMongers = newWarMongers;
    war(warMongers, wp, lf);
}

void MegaDeck::playGame() {
    Player* winner = NULL;
    WarPile wp;
    LostFound lf;

    int battleCount = 0;
    std::cout << "\nPre-battle stats: ";
    this->display();
    std::cout << std::endl;

    std::vector<Player*> availablePlayers;
    std::vector<Player*> warMongers;
    std::vector<int> winnerIndices;
    int currPlayers;
    this->display();

    while (winner == NULL) {
        //reset round
        availablePlayers.clear();
        warMongers.clear();
        winnerIndices.clear();

        //first check who can still play (before recursive loop means they have AT LEAST ONE CARD)
        for (auto& p : players) {
            if (p.available()) {
                Player* player = &p;
                availablePlayers.push_back(player);
            }
        }
        //check if only one left, then exit with winner
        if (availablePlayers.size() == 1) {
            winner = availablePlayers[0];
            break;
        }

        for (auto& p : availablePlayers) {
            wp.add((*p).remove(1));
        }

        currPlayers = availablePlayers.size();
        winnerIndices = wp.findWinners(currPlayers);

        for (auto& i : winnerIndices) {
            warMongers.push_back(availablePlayers[i]);
        }

        war(warMongers, wp, lf);

        for (auto& p : players)
            p.updateGameStats();
        std::cout << "\nBattle " << battleCount << " Stats:";
        this->display();
        std::cout << std::endl;
        battleCount++;
    }

    std::cout << "\nThe winner was:";
    winner->getStats();
}


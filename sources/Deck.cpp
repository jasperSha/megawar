#include "Deck.h"
#include <iostream>





/*
Deck::Deck() {
	char suits[] = { 'S','H','D','C' };
	char ranks[] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
	top = 0;

	int count = 0;
	Card deckCard;
	for (int s = 0; s < 4; s++) { // 4 suits
		for (int r = 0; r < 13; r++) { // 4 ranks
			deckCard = Card(ranks[r], suits[s]);
			storage[count++] = deckCard; //from bottom up, keeping track of count in deck
		}
	}
}

void Deck::refreshDeck() { Deck(); }

void Deck::showDeck() const {
	int idx = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			storage[idx++].showCard();
			cout << " ";
		}

		cout << '\n'; 
	}
}

int Deck::cardsLeft() const { 
	return 52 - top;
}

void Deck::shuffle() {
	Card swap;
	int first, second;
	srand(time(NULL));

	for (int i = 0; i < 100000; i++) {

		first = rand() % 52;
		second = rand() % 52;

		//hold original value temporarily
		swap = storage[first];
		storage[first] = storage[second];

		//swap back in the original
		storage[second] = swap;

	}
}

Card Deck::deal() { return storage[top++]; }

*/
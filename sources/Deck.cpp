#include "../headers/Deck.h"
#include "../headers/Card.h"
#include "time.h"
#include <iostream>

Deck::Deck() {
	for (int SuitInt = CLUBS; SuitInt != SUITEND; SuitInt++) {
		for (int RankInt = ACE; RankInt != RANKEND; RankInt++) {

			Card::Rank rank = static_cast<Card::Rank>(RankInt);
			Card::Suit suit = static_cast<Card::Suit>(SuitInt);

			Card c1(rank, suit);
			storage.push_back(c1);
		}	
	}
}

void Deck::showDeck() {
	int cardCount = storage.size();
	int count = 0;
	while (count < cardCount) {
		std::cout << storage[count++] << '\n';
	}
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

int Deck::getCount() const {
	return CardPile::getCount();
}

Card Deck::remove() {
	return CardPile::remove();
}
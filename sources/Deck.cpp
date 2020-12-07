#include "../headers/Deck.h"
#include "../headers/Card.h"
#include "time.h"
#include <iostream>
#include <vector>

Deck::Deck() {
	std::vector<Card> pile;
	for (int SuitInt = CLUBS; SuitInt != SUITEND; SuitInt++) {
		for (int RankInt = ACE; RankInt != RANKEND; RankInt++) {

			Card::Rank rank = static_cast<Card::Rank>(RankInt);
			Card::Suit suit = static_cast<Card::Suit>(SuitInt);

			Card cd(rank, suit);
			pile.push_back(cd);
		}	
	}
	storage = pile;
}

void Deck::display() const{
	int cardCount = storage.size();
	int count = 0;
	while (count < cardCount) {
		std::cout << storage[count++] << '\n';
	}
}
std::vector<Card> Deck::remove(int numCards) {
	return this->CardPile::remove(1);
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

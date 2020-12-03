#pragma once
#include "CardPile.h"

class Deck: public CardPile {

	public:
		Deck(); //all decks start with full 52, they will never gain cards, only deal them.

		int cardsLeft() const;

		void shuffle();
		Card deal(); //extends CardPile::remove()
		
		~Deck() {};

	protected:
		std::vector<Card> storage;
};

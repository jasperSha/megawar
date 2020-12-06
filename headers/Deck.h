#pragma once
#include "CardPile.h"
#include "Card.h"

class Deck: public virtual CardPile, Card {
	public:
		Deck(); //all decks start with full 52, they will never gain cards, only deal them.
		~Deck() {};
		
		int getCount() const;
		void showDeck();

		void shuffle();

		Card remove(); //extends CardPile::remove()
		
};

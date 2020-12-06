#pragma once
#include "CardPile.h"
#include "Card.h"

class Deck: public virtual CardPile, Card {
	public:
		Deck(); //all decks start with full 52, they will never gain cards, only deal them.
		
		void showDeck();
		void shuffle();
		
};

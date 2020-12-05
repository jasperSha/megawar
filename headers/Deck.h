#pragma once
#include "CardPile.h"
#include "Card.h"

class Deck: public CardPile, Card {
	public:
		Deck(); //all decks start with full 52, they will never gain cards, only deal them.

		virtual int getCount() const;
		void showDeck();

		void shuffle();

		virtual Card remove(); //extends CardPile::remove()
		
};

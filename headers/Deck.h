#pragma once
#include "CardPile.h"
#include "Card.h"

class Deck: public CardPile, Card {

	public:
		Deck(); //all decks start with full 52, they will never gain cards, only deal them.

		int cardsLeft() const;
		void showDeck();

		void shuffle();
		Card deal(); //extends CardPile::remove()
		
		~Deck() {};

	protected:
		std::vector<Card> storage;
};

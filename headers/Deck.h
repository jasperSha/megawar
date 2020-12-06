#pragma once
#include "CardPile.h"
#include "Card.h"
#include <vector>

class Deck: public CardPile, Card {
	public:
		Deck(); //all decks start with full 52, they will never gain cards, only deal them.
		
		void shuffle();

		virtual void display() const override;
		virtual std::vector<Card> remove(int numCards) override;

		virtual void resize(int newCapacity) override;
		
};

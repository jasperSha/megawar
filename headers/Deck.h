#pragma once
#include "CardPile.h"
#include "Card.h"
#include <vector>

class Deck: public CardPile, Card {
	public:
		Deck(); //all decks start with full 52, they will never gain cards, only deal them.
		
		void shuffle();

		virtual void display() const override;

		/** @param: int numCards : dummy variable
		 *  @return: only the top (end of vector) is removed for a Deck
		 */
		virtual std::vector<Card> remove(int numCards) override;

};

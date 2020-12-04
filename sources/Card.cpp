#include "../headers/Card.h"
#include <iostream>
#include <string>

Card::Card(Card::Rank r, Card::Suit s) {
	rank = r;
	suit = s;
}

std::string Card::toString() const {
	std::string ranks[] = {"ACE", "TWO", "THREE", "FOUR", "FIVE",
						   "SIX", "SEVEN", "EIGHT", "NINE", "TEN",
						   "JACK", "QUEEN", "KING"};
	std::string suits[] = {"CLUBS","DIAMONDS", "HEARTS", "SPADES"};
	
	const Card::Rank rank = this->getRank();
	const Card::Suit suit = this->getSuit();
	
	int rnk = static_cast<int>(rank);
	int st = static_cast<int>(suit);

	std::string ans = ranks[rnk-1] + " OF " + suits[st];

	return ans;
}

int Card::getValue() const {
	return static_cast<int>(rank);
}

Card::Rank Card::getRank() const{
	return this->rank;
}

Card::Suit Card::getSuit() const{
	return this->suit;
}

std::ostream& operator<<(std::ostream& out, Card& c) {
	out << c.toString();
	return out;
}

bool operator>(const Card& first, const Card& second) {
	return first.getValue() > second.getValue();
}

bool operator<(const Card& first, const Card& second) {
	return first.getValue() < second.getValue();
}

bool operator==(const Card& first, const Card& second) {
	return first.getValue() == second.getValue();
}



/*
Card::Card() : rank(' '), suit(' ') {}
Card::Card(char r, char s) : rank(r), suit(s) {}

void Card::showCard() const {

	stringstream ss;
	string rankChar;

	//read rank char value into stream
	ss << rank;
	ss >> rankChar;

	//Ten the only single character rank representing a 2-char string value
	string rankConvert = (rankChar == "T") ? "10" : rankChar;
	printf("%s%c", rankConvert.c_str(), suit);

}

void Card::setCard(char r, char s) {

	rank = r;
	suit = s;

}

int Card::getValue() const {
	switch (rank) {
		case 'A':
			return 1;
		case 'J':
		case 'Q':
		case 'K':
		case 'T':
			return 10;
		default:
			//otherwise simply 2-9, integer values
			stringstream ss;
			int x;

			ss << rank;
			ss >> x;
			return x;
	}
}
*/
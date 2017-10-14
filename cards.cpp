#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <time.h>

/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
Card class
************************************************* */

/*
Default constructor for the Card class.
It could give repeated cards. This is OK.
Most variations of Blackjack are played with
several decks of cards at the same time.
*/
Card::Card() {
	int r = 1 + rand() % 4;
	switch (r) {
	case 1: suit = OROS; break;
	case 2: suit = COPAS; break;
	case 3: suit = ESPADAS; break;
	case 4: suit = BASTOS; break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; break;
	case  2: rank = DOS; break;
	case  3: rank = TRES; break;
	case  4: rank = CUATRO; break;
	case  5: rank = CINCO; break;
	case  6: rank = SEIS; break;
	case  7: rank = SIETE; break;
	case  8: rank = SOTA; break;
	case  9: rank = CABALLO; break;
	case 10: rank = REY; break;
	default: break;
	}
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "Oros";
		break;
	case COPAS:
		suitName = "Copas";
		break;
	case ESPADAS:
		suitName = "Espadas";
		break;
	case BASTOS:
		suitName = "Bastos";
		break;
	default: break;
	}
	return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}
	return rankName;
}



// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "Golds";
		break;
	case COPAS:
		suitName = "Cups";
		break;
	case ESPADAS:
		suitName = "Swords";
		break;
	case BASTOS:
		suitName = "Clubs";
		break;
	default: break;
	}
	return suitName;
}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "Ace";
		break;
	case DOS:
		rankName = "Two";
		break;
	case TRES:
		rankName = "Three";
		break;
	case CUATRO:
		rankName = "Four";
		break;
	case CINCO:
		rankName = "Five";
		break;
	case SEIS:
		rankName = "Six";
		break;
	case SIETE:
		rankName = "Seven";
		break;
	case SOTA:
		rankName = "Jack";
		break;
	case CABALLO:
		rankName = "Knight";
		break;
	case REY:
		rankName = "King";
		break;
	default: break;
	}
	return rankName;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
	return static_cast<int>(rank) + 1;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}

double Card::value()
{
	int value=0;
	if (rank == AS)
		value=1;
	else if (rank == DOS)
		value=2;
	else if (rank == TRES)
		value=3;
	else if (rank == CUATRO)
		value=4;
	else if (rank == CINCO)
		value=5;
	else if (rank == SEIS)
		value=6;
	else if (rank == SIETE)
		value=7;
	else if (rank == SOTA || rank == CABALLO || rank == REY)
		value=0.5;
		return value;
}


/* *************************************************
Hand class
************************************************* */
// Implemente the member functions of the Hand class here.

Hand::Hand()
{
	srand((int)time(NULL));
}
void Hand::addCard(Card newCard)
{
	myCards.push_back(newCard);
	count += newCard.value();
}
void Hand::printCards()
{
	for (int i = 0; i < myCards.size(); i++) {
	cout << myCards.at(i).get_english_rank() << " of " << myCards.at(i).get_english_suit << endl; }
}
void Hand::erase()
{
	myCards.clear();
	count = 0.0;
}


/* *************************************************
Player class
************************************************* */
// Implemente the member functions of the Player class here.

Player::Player(int m)
{
	money = m;
}
void Player::addCard(Card newCard)
{
	playerHand.addCard(newCard);
}
void Player::printCards()
{
	playerHand.printCards();
}

void Player::newHand()
{
	playerHand.erase();
}

#include "cards.h"
#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;


double DealerHand(Player dealer, double count)
{

	if (count < 5.5)
	{
		Card draw;
		dealer.addCard(draw);
		cout << "New Card: " << endl;
		cout << "/t" << draw.get_english_rank() << " of " << draw.get_english_suit() << endl;
		cout << "Dealer's cards: " << endl;
		dealer.printCards();
		cout << "Dealer's score is " << (*dealer.getHand()).score() << endl;
		return DealerHand(dealer, (*dealer.getHand()).score());
	}

	return ((*dealer.getHand()).score());
}

int main() {
	int bet;
	Player a(100);
	Player b(100);
	string answer;
	bool cont = true;

	while (a.getMoney() > 0) {
		a.newHand();
		cout << "You currently have: " << a.getMoney() << " dollars.  Please enter your bet: " << endl;
		cin >> bet;
		while (cont == true) {
			Card draw;
			a.addCard(draw);
			cout << "The new card is: " << endl;
			cout << "/t" << draw.get_english_rank() << " of " << draw.get_english_suit() << endl;
			cout << "Your cards: " << endl;
			a.printCards();
			cout << "Your score is: " << (*a.getHand()).score() << endl;
			if ((*a.getHand()).score() > 7.5) {
				cout << "BUST! You LOSE!" << endl << endl;
				a.lose(bet);
				break;
			}
			cout << "Do you want another card? (yes/no): " << endl;
			cin >> answer;
			if (answer == "no" || answer == "No") {
				double ds = DealerHand(b, (*b.getHand()).score());
				if (ds > 7.5) {
					cout << "Dealer busted.  You WIN!" << endl;
					a.win(bet);
					break;
				}
				else if (ds > (*a.getHand()).score()) {
					cout << "You LOSE!" << endl;
					a.lose(bet);
				}
				else if (ds < (*a.getHand()).score()) {
					cout << "You WIN!" << endl;
					a.win(bet);
				}
				else {
					cout << "It's a TIE!" << endl;
				}
			}
		
		}

	}
}

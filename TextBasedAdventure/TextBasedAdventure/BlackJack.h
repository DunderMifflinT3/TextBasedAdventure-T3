#pragma once
#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <vector>       // std::vector
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include<stack>
using namespace std;
bool userturn = false;
bool dealerturn = false;

class Dealer
{
private:
	int userhand, dealerhand;// total values for the cards 
	stack<int> cards;// stack for all the cards 
	stack<int> acesUser;// stack to check aces for the user
	stack<int> acesDealer;// Stack to check for aces for the dealer 
	vector<int>card_vec = { 1, 2, 3, 4, 5, 6, 7, 8,
						9, 10,10,10,10,1, 2, 3, 4, 5, 6, 7, 8,// Vector holding all cards 
						9, 10,10,10,10,1, 2, 3, 4, 5, 6, 7, 8,
						9, 10,10,10,10,1, 2, 3, 4, 5, 6, 7, 8,
						9, 10,10,10,10 };
	int hold;
public:

	Dealer()// simple constructor
	{
		userhand = 0;
		dealerhand = 0;
		
	}
	void cardPile()
	{
		
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); default_random_engine e(seed);//Makes seed to shuffle cards 
		shuffle(card_vec.begin(), card_vec.end(), e);// Shuffles cards in vector 

		for (vector<int>::iterator it = card_vec.begin(); it != card_vec.end(); ++it) {
			cards.push(*it);// Transfers all shuffled cards in vector to stack 
		}
		
	}

	int getUserHand()
	{
		return userhand;// returns total cards for user 
	}
	int getDealerHand()
	{
		return dealerhand;// Returns total cards for dealer 
	}

	void hitUser()
	{
		int userInput;
		if (cards.top() == 1)// checks if aces has been drawn
		{
			cout << "Would you like the ace to be a 1 or a 11? Right now you have " << userhand << endl;
				cin >> userInput;
				if (userInput == 1)// if user picks one it will be set to one
				{
					userhand += 1;
					cards.pop();
				}
				else if (userInput == 11)// if user picks 11 it will be set to 11
				{
					userhand += 11;
					acesUser.push(1);// tells stack that the user has a ace registered as a 11
					cards.pop();
				}
		}
		else
		{
			cout << "You drew a " << cards.top()<< endl;// if the card is not a ace
		userhand += cards.top();
		cards.pop();
		}
	}
	int  holdcard()// holds the dealers second card so it remains hiddden form the user
	{
		int hold;
		if (cards.top() == 1)// checks to see if the card is a ace 
		{
			if (dealerhand + 11 <= 21)// determinies if the card will be a 11 or a one 
			{
				hold = 11;
				acesDealer.push(1);// tells stack dealer has a ace as a 11
			}
			else
				hold=1;// dealer registered card as a one 

			cards.pop();
			return hold;
		}
		else
		{
			hold= cards.top();// any ohter cards besides ace 
			cards.pop();
			return hold;
		}
	}
	void hitDealer()
	{
		if (cards.top()==1)// check to see if the card is a ace 
		{
			if (dealerhand + 11 <= 21)// determines if the card should be a 11 or a one 
			{
				cout << "The dealer drew a 11" << endl;
				dealerhand += 11;
				acesDealer.push(1);// tells stack if dealer has a ace 
				cards.pop();

			}
			else
			{
				cout << "The dealer drew a 1" << endl;// if dealer draws a one 
				dealerhand += 1;
				cards.pop();
			}
			
		}
		else
		{
			cout << "The dealer drew a " << cards.top() << endl;// Any other cards besides aces 
			dealerhand += cards.top();
			cards.pop();
		}
	}
	bool checkUserWin(int dealerHold)// Sees if the user wins the game 
	{
		if (userhand > dealerhand+dealerHold && bustUser(userhand) == false)
			return true;
		
		else
			return false;
	}
	bool checkDealerWin(int  dealerHold)// Sees if the dealer wins the game 
	{
		if (dealerhand+dealerHold > userhand && bustDealer(dealerhand+dealerHold, dealerHold) == false)
			return true;

		else
			return false;
	}
	bool checkTie(int dealerHold)// chexks to see if there is a tie 
	{
		if (userhand == dealerhand+dealerHold && bustUser(userhand) == false && bustDealer(dealerhand+dealerHold, dealerHold) == false)
			return true;
		else
			return false;
	}
	bool bustUser(int hand )// sees if the user busted 
	{
		if (hand > 21 && breakAceUser()== false )// user busted 
			return true;
		else if(hand>21 && breakAceUser() == true)// checks to see if the user took anyt aces as 11 and if they bust will reduce their hand by 10
		{
			userhand -= 10;
			acesUser.pop();
			return false;
		}
		else
			return false;// user did not bust
	}
	bool bustDealer(int hand, int holdDealer)
	{
		if (hand > 21 && breakAceDealer(holdDealer)== false)// dealer busted 
			return true;
		else if (hand > 21 && breakAceDealer(holdDealer) == true)// checks to see if the user took anyt aces as 11 and if they bust will reduce their hand by 10
		{
			dealerhand -= 10;
			acesDealer.pop();
			return false;
		}
		else
			return false; // dealer did not bust
	}

	bool breakAceUser()
	{
		if (userhand > 21 && acesUser.empty() == false)// checks to see if the stack of 11 aces is empty for user
		{
			return true;
		}
		else
			return false;
	}
	bool breakAceDealer(int holdDealer)
	{
		if (dealerhand + holdDealer > 21 && acesDealer.empty() == false)// checks to see if the stack of 11 aces is empty for Dealer
		{
			return true;
		}
		else
			return false;
	}

};
	
	
	

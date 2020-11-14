#include <iostream>
#include "BlackJack.h"
#include "InputValidation.h"
using namespace std;

int playBlackJack()
{
	double userInput = 1;// to tell if the user will hit or stay 
	int holdDealerCard;// holds the dealers hidden card 
	cout << "Welcome to the BlackJack mini game!" << endl;// couts starting messages 
	cout << "In order to win this ganme get as close to 21 as you can" << endl;
	cout << "If the dealer is closer to 21 than you then you loose, but if you go over 21 you loose as well" << endl;
	cout << "The goal is to beat the dealer and not go over 21 so good luck" << endl;
	cout << "THe dealer stays on 16 and above" << endl;
	Dealer obj;// object of class 
	obj.cardPile();//Creates the deck 
	obj.hitUser();//Gives the user a card 
	obj.hitDealer();// Gives the dealer a card 
	obj.hitUser();// Gives the user a card 
	cout << "The starting hand for the user is " << obj.getUserHand() << endl;
	cout << "The dealer is showing a  " << obj.getDealerHand() << endl;
	holdDealerCard = obj.holdcard();// Sets the hidden card for dealer 
	while (userInput == 1 && obj.bustUser(obj.getUserHand()) == false)// loop for user playing 
	{
		cout << "Would you like to hit or stay(1=hit, 0=stay)" << endl;
		cin >> userInput;
		if (userInput == 1 && obj.bustUser(obj.getUserHand()) == false)// checks if user hits n
		{
			obj.hitUser();
			if (obj.bustUser(obj.getUserHand()) == true)// user busted 
			{
				cout << "You busted your final hand was " << obj.getUserHand() << endl;
				return 0;
			}
			else
				cout << "Your new hand is " << obj.getUserHand() << endl;// user does not hit 
		}
	}

	cout << "The dealer flips his face down card and it is a " << holdDealerCard << " the dealer now has " << obj.getDealerHand() + holdDealerCard << endl;
	if (obj.breakAceDealer(holdDealerCard) == false)
	{
		while (obj.getDealerHand() + holdDealerCard < 16 && obj.getDealerHand() + holdDealerCard < obj.getUserHand())// determines whether the dealer hits 
		{
			obj.hitDealer();
			cout << "The Dealer hits and now has " << obj.getDealerHand() + holdDealerCard << endl;

		}
	}
	else if (obj.breakAceDealer(holdDealerCard) == true)
	{
		while (obj.getDealerHand() + holdDealerCard < 17 && obj.getDealerHand() + holdDealerCard < obj.getUserHand())// determines whether the dealer hits 
		{
			obj.hitDealer();
			cout << "The Dealer hits and now has " << obj.getDealerHand() + holdDealerCard << endl;

		}
	}
	if (obj.checkUserWin(holdDealerCard) == true)// if user wins 
	{
		cout << "Congrats you won the hand! Your hand was " << obj.getUserHand() << " and the dealers hand was " << obj.getDealerHand() + holdDealerCard << endl;
		return 1;
	}
	else if (obj.bustDealer(obj.getDealerHand() + holdDealerCard, holdDealerCard) == true)// if dealer busts 
	{
		cout << "The dealer busted with " << obj.getDealerHand() + holdDealerCard << endl;
		return 0;
	}
	else if (obj.checkDealerWin(holdDealerCard) == true)// if dealer wins 
	{
		cout << "Sorry you lost try again, you had " << obj.getUserHand() << " and the dealer had " << obj.getDealerHand() + holdDealerCard << endl;
		return 0;
	}
	else if (obj.checkTie(holdDealerCard) == true)// if user and dealer tie 
		cout << "You both push with " << obj.getUserHand() << " in both of your hands" << endl;
}
//int main()
//{
//	playBlackJack(); //Call game with one line
//}
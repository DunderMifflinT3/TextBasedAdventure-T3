#include <iostream>
#include <cstdlib>
#include <ctime>
#include "InputValidation.h"
using namespace std;

bool playHT()
{
	int randnumber;

	//generate random number from 1-2
	srand(time(NULL));
	randnumber = (rand() % 2) + 1;
	cout << "This is heads or tails. Guess two in a row correctly to win." << endl;
	
	for (int i = 0; i < 2; i++)
	{
		cout << "Enter 1 for HEADS. Enter 2 for TAILS.";
		int choice = input(2);

		if (i == 2)
		{
			if (choice == randnumber)
			{
				cout << "You got 2 in a row! You win!" << endl;
				return true;
			}
			else
			{
				cout << "Wrong side." << endl;
				return false;
			}
		}
		else if (choice == randnumber)
		{
			cout << "You got it right. You need " << 1 - i << " more to win!" << endl;
			if (1 - i == 0)
				return true;
		}
		else
		{
			cout << "Wrong side." << endl;
			return false;
		}
	}
}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "InputValidation.h"
using namespace std;

bool playHL()
{
	int randnumber;
	
	int tries = 0;
	int attemptnumber = 10;
	char playagain;

	//generate random number from 1-100
	srand(time(0));
	randnumber = rand() % 100 + 1;

	//reads first number
	cout << "You have 10 tries to guess the number from 1-100." << endl;

	for (int i = 0; i < attemptnumber; i++)
	{
		cout << "Enter a number from 1-100:" << endl;
		input(100);
		if (choice > randnumber)
		{
			cout << "Nope, too high." << endl;
		}
		else if (choice < randnumber) {
			cout << "Nope, too low." << endl;
		}
		else {
			cout << "Yes! That is the correct number. You got it in " << tries << " attempts.";
			return true;
		}
		tries++;
	}
	{
		cout << "You are out of guesses.";
		return false;
	}
}
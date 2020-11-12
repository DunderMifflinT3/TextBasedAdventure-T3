#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool playHT()
{
	int guess;
	int randnumber;

	//generate random number from 1-2
	srand(time(NULL));
	randnumber = rand() % 2;
	cout << "This is heads or tails. Guess two in a row correctly to win." << endl;

	for (int i = 0; i < 2; i++)
	{
		cout << "Enter 0 for HEADS. Enter 1 for TAILS.";
		cin >> guess;
		if (i == 2)
		{
			if (guess == randnumber)
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
		else if (guess == randnumber)
		{
			cout << "You got it right. You need " << 1 - i << " more to win!" << endl;
		}
		else
		{
			cout << "Wrong side." << endl;
			return false;
		}
	}
}
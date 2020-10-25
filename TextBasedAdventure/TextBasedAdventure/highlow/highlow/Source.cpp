#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// HIGH LOW ROOM GAME
int main()
{
	int randnumber;
	int guess;
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
			cin >> guess;
			if (guess > randnumber)
			{
					cout << "Nope, too high." << endl;
			}
				else if (guess < randnumber) {
				cout << "Nope, too low." << endl;
					}
				else {
				cout << "Yes! That is the correct number. You got it in " << tries << " attempts.";
				return true;
				}
				tries++;
		}
		{
			cout << "You are out of guesses. Would you like to play again?";
			return false;
		}
}

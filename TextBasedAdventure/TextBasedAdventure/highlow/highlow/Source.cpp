#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// HIGH LOW ROOM GAME
int main()
{
	int randnumber;
	int guess;
	int tries = 0;

	//generate random number from 1-100
	srand(time(0));
	randnumber = rand() % 100 + 1;

	do
	{
		//reads first number
		cout << "Enter a number from 1-100: ";
		cin >> guess;
		tries++;

		//gameplay statements
		if (guess > randnumber)
			cout << "Nope, too high." << endl;
		else if (guess < randnumber)
			cout << "Nope, too low." << endl;
		else
			cout << "Yes! That is the correct number. You got it in " << tries << " attempts.";
	} while (guess != randnumber);

	return false;
}
#include <iostream>
#include <time.h> 
#include <stdlib.h>   
#include <stdio.h> 
#include <string>
#include "InputValidation.h"
#include  "Color.h"
using namespace std;

int tie_array[3][2] = { {0,1}, {1,2}, {2,3} };
int comp_win[3][2] = { {0,3}, {1,1}, {2,2} };
int player_win[3][2] = { {0,2}, {1,3},{2,1} };

int random;
enum winLossTie { win, loss, tie };

void setRandom()
{
	srand(time(NULL));
	double ran = rand() % 3;// Returns random number from 0-8
	random = ran;
}

int testWin(int choice)
{
	int y = 0;
	for (int x = 0; x < 3; x++)
	{
		if (tie_array[x][y] == random && tie_array[x][y + 1] == choice)	//Tie
		{
			system("CLS"); //Clears the console
			settextcolor(purple);
			if (random == 0)
			{
				cout << "Tie! Y'all throw Rocks at Each other Nothing Happens." << endl;
			}
			else if (random == 1)
			{
				cout << "Tie! Why did you two think fighting with paper was a good idea?" << endl;
			}
			else if (random == 2)
			{
				cout << "Tie! You both ran with scissors and got in trouble." << endl;
			}
			cout << endl;
			settextcolor(yellow);
			return 0;
		}

		else if (comp_win[x][y] == random && comp_win[x][y + 1] == choice)	//Loss
		{
			system("CLS"); //Clears the console
			settextcolor(dark_red);
			if (random == 0)
			{
				cout << "You lose.... He beats you vigorously with a rock you try to defend youself with a pair of safety scissors." << endl;
			}
			else if (random == 1)
			{
				cout << "You lose.... He gives you several paper cuts in not so fun places." << endl;
			}
			else if (random == 2)
			{
				cout << "You lose.... He tries sticking the scissors where the sun don't shine." << endl;
			}
			cout << endl;
			settextcolor(yellow);
			return 1;
		}

		else if (player_win[x][y] == random && player_win[x][y + 1] == choice)	//Win
		{
			system("CLS"); //Clears the console
			settextcolor(dark_green);
			if (random == 0)
			{
				cout << "You win! You give him a peice of paper with your artwork he laughs so hard he has a heart attack." << endl;
			}
			else if (random == 1)
			{
				cout << "You win! You throw the scissors MW2 style and General Shepherd his ass." << endl;
			}
			else if (random == 2)
			{
				cout << "You win! You yell Kobe and peg a rock at the dudes head." << endl;
			}
			cout << endl;
			settextcolor(yellow);
			return 2;
		}
	}
}

int startRPS()
{
	settextcolor(yellow);
	cout << "In order to pass this challange you have to win this game off Rock Paper Scissors" << endl;
	cout << "Enter in (1 for Rock) (2 for Paper) (3 for Scissors)" << endl;

	setRandom();

	return testWin(input(3));	//Returns if the player wins, loses, or ties. Also tests input validation.

}


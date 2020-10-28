#include <iostream>
#include <time.h> 
#include <stdlib.h>   
#include <stdio.h> 
#include <string>
#include "InputValidation.h"
using namespace std;

double tie_array[3][2] = { {0,1}, {1,2}, {2,3} };
double comp_win[3][2] = { {0,3}, {1,1}, {2,2} };
double player_win[3][2] = { {0,2}, {1,3},{2,1} };
string winning_saying;
int random;
bool win;
bool tie;

void set_random()
{
	srand(time(NULL));
	double ran = rand() % 3;// Returns random number from 0-8
	random = ran;
}

void test_win(double choice)
{
	int y = 0;
	for (int x = 0; x < 3; x++)
	{

		if (tie_array[x][y] == random && tie_array[x][y + 1] == choice)	//Tie
		{
			if (random == 0)
			{
				winning_saying = "Tie! Y'all throw Rocks at Each other Nothing Happens.";
			}
			else if (random == 1)
			{
				winning_saying = "Tie! Why did you two think fighting with paper was a good idea?";
			}
			else if (random == 2)
			{
				winning_saying = "Tie!You both ran with scissors and got in trouble.";
			}
			win = false;
			tie = true;
		}

		else if (comp_win[x][y] == random && comp_win[x][y + 1] == choice)	//Loss
		{
			if (random == 0)
			{
				winning_saying = "You lose.... He beats you vigorously with a rock you try to defend youself with a pair of safety scissors.";
			}
			else if (random == 1)
			{
				winning_saying = "You lose.... He gives you several paper cuts in not so fun places.";
			}
			else if (random == 2)
			{
				winning_saying = "You lose.... He tries sticking the scissors where the sun don't shine.";
			}
			win = false;
			tie = false;
		}

		else if (player_win[x][y] == random && player_win[x][y + 1] == choice)	//Win
		{
			if (random == 0)
			{
				winning_saying = "You win! You give him a peice of paper with your artwork he laughs so hard he has a heart attack.";
			}
			else if (random == 1)
			{
				winning_saying = "You win! You throw the scissors MW2 style and General Shepherd his ass.";
			}
			else if (random == 2)
			{
				winning_saying = "You win! You yell Kobe and peg a rock at the dudes head.";
			}
			win = true;
			tie = false;
		}
	}
}

void startRPS()

{
	cout << "In order to pass this challange you have to win this game off Rock Paper Scissors" << endl;
	cout << "Enter in (1 for Rock) (2 for Paper) (3 for Scissors)" << endl;

	set_random();


	//Input Validation
	input(3);

	test_win(choice);

	cout << winning_saying << endl << endl;

	return;
}


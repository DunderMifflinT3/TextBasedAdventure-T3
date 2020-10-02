#include "R_P_S.h"
#include <iostream>
#include <time.h> 
#include <stdlib.h>   
#include <stdio.h> 
#include <string>
using namespace std;

double tie_array[3][2] = { {0,1}, {1,2}, {2,3} };
double comp_win[3][2] = { {0,3}, {1,1}, {2,2} };
double player_win[3][2] = { {0,2}, {1,3},{2,1} };
string winning_saying;

void R_P_S::set_random()
	{
	srand(time(NULL));
	double ran = rand() % 3;// Returns random numer from 0-8
	random = ran;
	}
void R_P_S::display()
	
{
	double user_input;
	cout << "In order to pass this challange you have to win this game off Rock Paper Scissors" << endl;
	cout << "Enter in (1 for Rock) (2 for Paper) (3 for Scissors)" << endl;
	cin >> user_input;
	while (input_val(user_input)==false)
	{
		cin >> user_input;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	set_random();
	test_win(user_input);
	
	
	
	
	cout << winning_saying << endl;
	

}
bool R_P_S::input_val(double user_input)
{
	if (floor(user_input) != user_input)
	{
		cout << "Enter in valid value" << endl;

		return false;
	}
	else if (user_input > 3 || user_input <= 0)
	{
		cout << "Enter in valid value" << endl;
		return false;
	}
	return true;
}
int main()
{
	R_P_S obj;
	obj.display();
	
}
double R_P_S::get_random()
{
	return random;
}
void R_P_S::test_win(double user_input)
{
	int y = 0;
	for (int x = 0; x < 3; x++)
	{
		 
			if (tie_array[x][y]==random && tie_array[x][y+1]==user_input)
			{
				tie = true;
				win = false;
				if (random==0)
				{
					winning_saying = "Tie! Y'all throw Rocks at Each other Nothing Happens";
				}
				else if (random==1)
				{
					winning_saying = "Tie! Why did you two think fighting with paper was a good idea?";
				}
				else if (random == 2)
				{
					
					winning_saying = "Tie!You both ran with scissorsand got in trouble";
				}
			}
			else if (comp_win[x][y] == random && comp_win[x][y + 1] == user_input)
			{
				tie = false;
				win = false;
				if (random == 0)
				{
					winning_saying = "You lose.... He beats you vigorously with a rock you try to defend youself with a pair of safety scissors, you run away";
				}
				else if (random == 1)
				{
					winning_saying = "You lose.... He gives you several paper cuts in not so fun places, you run away";
				}
				else if (random == 2)
				{
					winning_saying = "You lose.... He tries sticking the scissors where the sun don't shine, you run away";
				}

			}
			else if (player_win[x][y] == random && player_win[x][y + 1] == user_input)
			{
				if (random == 0)
				{
					winning_saying = "You win! You give him a peice of paper with your artwork he laughs so hard he has a heart attack";
				}
				else if (random == 1)
				{
					winning_saying = "You win! You throw the scissors MW2 style and General Shepherd his ass ";
				}
				else if (random == 2)
				{
					winning_saying = "You win! You yell Kobe and peg a rock at the dudes head";
				}

			}
		
	}
}
bool R_P_S:: get_Tie()
{
	return tie;
}
bool R_P_S::get_Win()
{
	return win;
}

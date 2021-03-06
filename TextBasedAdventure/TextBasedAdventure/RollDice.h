#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "InputValidation.h"
using namespace std;

bool playRD()
{
	// You have 3 turns
	int maxturns = 3;
	// Numbers to enter for each roll
	int roll1 = 1;
	int roll2 = 2;
	// Variables for user roll
	int user1;
	int user2;
	// Variables for computer roll
	int computer1;
	int computer2;
	//play again
	char playagain;
	//random number seed
	srand(time(0));
	// read gameplay
	cout << "You have 3 chances to roll a higher number then the computer. You each have 2 dice." << endl;

	for (int i = 1; i <= maxturns; i++)
	{
		//rand # 1-6
		user1 = rand() % 6 + 1;
		user2 = rand() % 6 + 1;
		computer1 = rand() % 6 + 1;
		computer2 = rand() % 6 + 1;
		// Total user roll
		int usertotal = user1 + user2;
		int computertotal = computer1 + computer2;
		//user enters first dice
		cout << "Enter 1 to roll dice 1." << endl;
		input(1);
		system("CLS");
		cout << "You rolled a " << user1 << "." << endl;

		//user enters second dice
		cout << "Enter 1 to roll dice 2." << endl;
		input(1);
		system("CLS");
		cout << "You rolled a " << user2 << "." << endl;

		//user total
		cout << "Your total score is " << usertotal << "." << endl << endl;

		//computer gameplay
		cout << "The computer's fist dice was a " << computer1 << "." << endl;
		cout << "The computer's second dice was a " << computer2 << "." << endl;
		cout << "The computer's total score is " << computertotal << "." << endl << endl;

		if (usertotal > computertotal)
		{
			cout << "You win! The task is complete." << endl;
			return true;
		}
		else
		{
			cout << "You lose, try again!" << endl;
		}
	}
	return false;
}
//All Input Validation in the game uses the functions in this file

#pragma once
#include <iostream>
#undef max
using namespace std;

int choice;
double choiceCopy;

bool inputValidation(int choice, double choiceCopy, int numOfChoices)	//Checks if input is valid
{
	if (floor(choiceCopy) != choiceCopy)
	{
		cout << "Invalid Input" << endl;

		return false;
	}
	else if (choice > numOfChoices || choice < 1)
	{
		cout << "Invalid Input" << endl;
		return false;
	}
	return true;
}

void input(int numOfChoices)	//Allows for an input to happen
{
	cin >> choiceCopy;
	choice = choiceCopy;
	while (inputValidation(choice, choiceCopy, numOfChoices) == false)
	{
		cin >> choiceCopy;
		choice = choiceCopy;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}


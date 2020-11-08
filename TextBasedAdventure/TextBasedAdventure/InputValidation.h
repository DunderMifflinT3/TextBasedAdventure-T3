//All Input Validation in the game uses the functions in this file

#pragma once
#include <iostream>
#undef max
using namespace std;

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

int input(int numOfChoices)	//Allows for an input to happen
{
	int inputChoice;
	double inputChoiceCopy;

	cout << endl;
	cin >> inputChoiceCopy;
	inputChoice = inputChoiceCopy;
	while (inputValidation(inputChoice, inputChoiceCopy, numOfChoices) == false)
	{
		cin >> inputChoiceCopy;
		inputChoice = inputChoiceCopy;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return inputChoice;
}


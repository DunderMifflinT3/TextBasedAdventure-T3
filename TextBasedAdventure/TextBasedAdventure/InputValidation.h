//All Input Validation in the game uses the functions in this file

#pragma once
#include <iostream>
#include <cctype>;
#undef max
using namespace std;

bool checkIfDigit(string choice)
{
	for (int i = 0; i < choice.size(); i++)
	{
		if (!isdigit(choice[i]))
		{
			return false;
		}
	}
	return true;
}

bool inputValidation(string choice, int numOfChoices)	//Checks if input is valid
{
	if (choice.size() > 4)	//Prevents large inputs from causinng problems
	{
		cout << "Invalid Input" << endl;
		return false;
	}
	else if(!checkIfDigit(choice))	//Makes sure that input is a digit
	{
		cout << "Invalid Input" << endl;
		return false;
	}
	else if (stoi(choice) < 1 || stoi(choice) > numOfChoices)	//Makes sure input is within the specified range
	{
		cout << "Invalid Input" << endl;
		return false;
	}
	else
	{
		return true;
	}
}

int input(int numOfChoices)	//Allows for an input to happen
{
	string inputString;

	cout << endl;

	do //Only returns after the input is validated to be within 1 and the number of choices
	{
		getline(cin, inputString);

	} while (!inputValidation(inputString, numOfChoices));

	return stoi(inputString);
}


//All Input Validation in the game uses the functions in this file

#pragma once
#include <iostream>
#undef max
using namespace std;

bool inputValidation(string choice, int numOfChoices)	//Checks if input is valid
{
	if (choice.size() > 1 || stoi(choice) < 1 || stoi(choice) > numOfChoices)
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

	do 
	{
		getline(cin, inputString);

	} while (!inputValidation(inputString, numOfChoices));

	return stoi(inputString);
}


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

bool playMath()
{
	// generate random numbers for equations
	srand(time(0));
	int a, b, c, d;
	a = rand() % 10 + 1;
	b = rand() % 10 + 1;
	c = rand() % 10 + 1;
	d = rand() % 10 + 1;

	//same for all
	int answer;
	// question 1
	int answer1 = (a * b) - (c * d);
	// question 2
	int answer2 = (-a * (c - d)) + pow(b, 2);
	// question 3
	int answer3 = ((d * a) - pow((c * -b), 2));

	//play again
	char playagain;

	// Gameplay sentence
	cout << "This is the math quiz. There are 3 questions. You have one chance to get them all correct. Don't mess up!" << endl << endl;

	//Question 1
	cout << "This is question 1. Enter your answer." << endl;
	cout << "What is (" << a << " * " << b << ") - (" << c << " * " << d << ")?" << endl;
	cin >> answer;
	if (answer == answer1)
	{
		cout << "Correct, move on to the next question." << endl;
	}
	else
	{
		cout << "You lose!" << endl;
		return false;
	}

	// Q2
	cout << "This is question 2. Enter your answer." << endl;
	cout << "What is (" << -a << " * (" << c << " - " << d << ")) + " << b << "^2 ?" << endl;
	cin >> answer;
	if (answer == answer2)
	{
		cout << "Correct, move on to the next question." << endl;
	}
	else
	{
		cout << "You lose!" << endl;
		return false;
	}
	// Q3 = 1
	cout << "This is question 3. Enter your answer." << endl;
	cout << "((" << d << " * " << a << ") - (" << c << " * " << -b << ")^2) ?" << endl;
	cin >> answer;
	if (answer == answer3)
	{
		cout << "Goodjob! You have completed this task." << endl;
		return true;
	}
	else
	{
		cout << "You lose!" << endl;
		return false;
	}
}
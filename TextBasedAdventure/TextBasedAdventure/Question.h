#pragma once
#include <iostream>
#include <string>
using namespace std;

class Question
{
private:
	string text;
	string answers[4];
	double correct;
public:
	//Constructors
	Question()
	{
		correct = 'X';
	}
	Question(string text, string ans[], double correct)
	{
		setText(text);
		setAnswers(ans);
		setCorrect(correct);
	}

	void setText(string text)
	{
		this->text = text;
	}
	void setAnswers(string ans[])
	{
		for (int i = 0; i < 4; i++)
			answers[i] = ans[i];
	}
	void setCorrect(double correct)
	{
		this->correct = correct;
	}
	string getText()
	{
		return text;
	}
	string getAnswer(int i)
	{
		if (i >= 0 && i < 4)
			return answers[i];
		else
			return " ";
	}
	double getCorrect()
	{
		return correct;
	}
	void display()		//Display the question & answers
	{
		cout << text << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << int(1 + i) << ". " << answers[i] << endl;
		}
	}
	bool isCorrectAnswer(double choice)		//Checks if input answer is correct
	{
		if (choice == correct)
		{
			cout << "Correct!" << endl << endl;
			return true;
		}
		else
		{
			cout << "Wrong, correct answer is: " << correct << endl << endl;
			return false;
		}
	}
};

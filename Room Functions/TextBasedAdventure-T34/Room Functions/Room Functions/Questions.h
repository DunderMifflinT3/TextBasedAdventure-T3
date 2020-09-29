#pragma once
#include <iostream>
#include <string>

class Question
{
private:
	string question;
	string answer;
	//include points for multiple questions
public:
	Question();
	Question(string q, string result);
	string getQuestion();
	string getAnswer();
	void displayQuestion();
	bool correctAnswer(string choice);
	//include points tracker
};

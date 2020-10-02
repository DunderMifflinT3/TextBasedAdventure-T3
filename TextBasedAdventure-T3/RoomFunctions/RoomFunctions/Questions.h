#pragma once
#include <iostream>
#include <string>
using namespace std;

class Question
{
private:
	//string question;
	string text;
	string answers[4];
	char correct;
	//include points for multiple questions
public:
	Question();
	Question(string text, string ans[], char correct); //Question constructor
	void setText(string text);
	void setAnswers(string answers[]);
	void setCorrect(char correct);
	string getText();
	string getAnswer(int i);
	char getCorrect();
	bool correctAnswer(char choice); //Checks if input answer is correct
	void display(); //Display the question & answers
	//include points tracker
};

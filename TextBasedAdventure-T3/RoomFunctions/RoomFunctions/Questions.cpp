#include "Questions.h"
using namespace std;

//Need to add questions
//Include multiple choice
//Input validation
//points & tracker
Question::Question()
{
	correct = 'X';
}
Question::Question(string text, string ans[], char correct)
{
	setText(text);
	setAnswers(ans);
	setCorrect(correct);
}
void Question::setText(string text)
{
	this->text = text;
}
void Question::setAnswers(string ans[])
{
	for (int i = 0; i < 4; i++)
		answers[i] = ans[i];
}
void Question::setCorrect(char correct)
{
	this->correct = correct;
}
string Question::getText()
{
	return text;
}
string Question::getAnswer(int i)
{
	if (i >= 0 && i < 4)
		return answers[i];
	else
		return " ";
}
char Question::getCorrect()
{
	return correct;
}
void Question::display()
{
	cout << text << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << char('A' + i) << ". " << answers[i] << endl;
	}
	cout << endl;
}
bool Question::correctAnswer(char choice)
{
	if (choice == correct)
	{
		cout << "Correct!" << endl;
		return true;
	}
	else
	{
		cout << "Wrong, correct answer is: " << correct << endl;
		return false;
	}
}

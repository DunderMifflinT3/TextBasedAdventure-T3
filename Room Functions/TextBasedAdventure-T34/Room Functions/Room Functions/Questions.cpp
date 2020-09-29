#include "Questions.h"
using namespace std;


//Need to add questions
//Include multiple choice
//Input validation
//points & tracker
Question::Question()
{
	question = "Is this a Game?";
	answer = "Yes";
}
Question::Question(string q, string result)
{
	question = q;
	answer = result;
}
string Question::getQuestion()
{
	return question;
}
string Question::getAnswer()
{
	return answer;
}
void Question::displayQuestion()
{
	cout << "Your task is to answer the following question: " << endl << question << endl;
	cout << "Your answer is: ";
}
bool Question::correctAnswer(string choice)
{
	if (choice == answer)
	{
		cout << "Correct!" << endl;
		return true;
	}
	else
	{
		cout << "Wrong, correct answer is: " << answer << endl;
		return false;
	}
}
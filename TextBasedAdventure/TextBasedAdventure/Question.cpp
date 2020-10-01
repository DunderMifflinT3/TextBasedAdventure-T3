#include "Question.h"
void Question::getQuestion()
{
	char choice;
	cout << "Lets start with a simple task, answer the following question by typing 'A, B, C, or D' for your selection" << endl;

	string ans1[] = { "Eight", "Seven", "Ten", "Nine" };//possible answers
	Question q1("How many planets are in our Solar System?", ans1, 'A');//sets up the question & answer as q1
	string ans2[] = { "Mercury", "Venus", "Mars", "Saturn" };
	Question q2("Which planet has the most moons?", ans2, 'D');
	string ans3[] = { "320,543,121 km", "149,600,000 km", "405,800,000 km", "250,300,000 km" };
	Question q3("What is the distance between the Sun and Earth?", ans3, 'B');

	q1.display();
	cin >> choice;
	q1.isCorrectAnswer(choice);
}

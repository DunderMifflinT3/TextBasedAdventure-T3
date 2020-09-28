#include "StartRoom.h"
#include "Questions.h"
#include <Windows.h>
using namespace std;

//Display intro msg
void StartRoom::startMsg()
{
	cout << "You have just woken up on a spaceship that is part of a space bounty expedition" << endl;
	cout << "to capture a most wantedalien and the ship is quickly spiraling out of control towards Earth." << endl;
	cout << "You realize your crewmates are missing, the power is out and the ships gadgets" << endl;
	cout << "seem to have been tampered with. You also realize there is a hole in the ship" << endl;
	cout << "and your oxygen is dropping quickly. Your mission is to find your crew, " << endl;
	cout << "repair the ship by fixing parts in each room so you can return home safely, and ultimately SURVIVE!" << endl << endl;
	Sleep(3000); //Gives user time to read script
}
void StartRoom::roomInfo()
{
	cout << "You are currently in the " << roomName << endl << endl;
}
//Starts room's question
void StartRoom::startRoom()
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
	q1.correctAnswer(choice);
}
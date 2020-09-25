#pragma once
#include <iostream>
#include <string>
using namespace std;

class StartRoom
{
private:
	//int roomID;  //include Room ID for Starting Point
	string roomName = "Start Room";
	//include future room info

public:
	void startMsg();
	void roomInfo();
	void startRoom();
	//include future room functions
};

void StartRoom::startMsg()
{
	cout << "Welcome to the long-distance spaceship Star-Glider, your journey begins at the " << roomName << endl;
}
void StartRoom::roomInfo()
{
	cout << "You are currently in the crew bedroom  " << endl;
	cout << "You must complete a series of tasks to survive" << endl;
}

void StartRoom::startRoom()
{
	cout << "Lets start with a simple task." << endl;

	//Call question

	//Check if correct answer

}
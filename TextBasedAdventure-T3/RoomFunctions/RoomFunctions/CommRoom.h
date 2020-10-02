#pragma once
#include <iostream>
#include <string>
using namespace std;

class CommRoom
{
private:
	//int roomID;  //include Room ID for Comm rOOM
	string roomName = "Communication Room";
	//include future room info

public:
	void roomInfo();
	void startRoom();
	//include future room functions
};

void CommRoom::roomInfo()
{
	cout << "You entered the " << roomName << endl;
	cout << "Communication throughout the ship and any external communication seems to be down.";
	cout << "You notice that the main transmitter is destroyed. Fixing communications could";
	cout << "allow you to get in touch with your team at home and tell them about the situation." << endl;
}

void CommRoom::startRoom()
{
	cout << "Solve the puzzle to fix the comms" << endl;

	//Call question

	//Check if correct answer

}
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
	cout << "You are currently in the " << roomName << endl;
	cout << "The comms are down, and the main transmitter is completely destroyed" << endl;
}

void CommRoom::startRoom()
{
	cout << "Solve the puzzle to fix the comms" << endl;

	//Call question

	//Check if correct answer

}
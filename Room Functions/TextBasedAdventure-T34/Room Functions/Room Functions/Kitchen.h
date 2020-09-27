#pragma once
#include <iostream>
#include <string>
using namespace std;

class Kitchen
{
private:
	//int roomID;  //include Room ID for Kitchen
	string roomName = "Kitchen";
	//include future room info

public:
	void roomInfo();
	void startRoom();
	//include future room functions
};

void Kitchen::roomInfo()
{
	cout << "You are currently in the " << roomName << endl;
	cout << "The chef has been murdered, and the knife is missing" << endl;
}

void Kitchen::startRoom()
{
	cout << "Solve the riddle for some food" << endl;

	//Call question

	//Check if correct answer

}

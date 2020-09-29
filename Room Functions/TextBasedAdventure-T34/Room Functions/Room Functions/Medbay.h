#pragma once
#include <iostream>
#include <string>
using namespace std;

class Medbay
{
private:
	//int roomID;  //include Room ID for Medbay
	string roomName = "Medbay";
	//include future room info

public:
	void roomInfo();
	void startRoom();
	//include future room functions
};

void Medbay::roomInfo()
{
	cout << "You are currently in the " << roomName << endl;
	cout << "The medic is found dead in the room" << endl;
}

void Medbay::startRoom()
{
	cout << "Answer the trivia question correctly to aquire bandages" << endl;

	//Call question

	//Check if correct answer

}

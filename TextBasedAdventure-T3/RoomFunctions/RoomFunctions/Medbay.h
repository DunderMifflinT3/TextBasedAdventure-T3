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
	cout << "You have entered the " << roomName << endl;
	cout << " It seems like someone has broken into the medical supplies" << endl;
}

void Medbay::startRoom()
{
	cout << "Answer the trivia question correctly to aquire bandages" << endl;

	//Call question

	//Check if correct answer

}
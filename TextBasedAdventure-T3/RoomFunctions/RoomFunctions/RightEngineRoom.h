#pragma once
#include <iostream>
#include <string>
using namespace std;

class RightEngine
{
private:
	//int roomID;  //include Room ID for Right Engine Room
	string roomName = "Right Engine Room";
	string tank;
	//include future room info

public:
	void roomInfo();
	void startRoom();
	//include future room functions
};

void RightEngine::roomInfo()
{
	cout << "You are currently in the " << roomName << endl;
	cout << "The ship’s fuel levels are low, you need to refill the ship’s fuel";
	cout << "You see a fuel container next to the fuel tank." << endl;
}

void RightEngine::startRoom()
{
	cout << "Type “Use/ fill tank” to fuel the engine." << endl;
	cin >> tank;

	if (tank == "fill tank")
	{
		cout << "Fuel Tank has been filled!" << endl;
	}
	else
	{
		cout << "Improper command, please type ''fill tank'' to fill the tank" << endl;
	}
}
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
	void startMsg(); //Display intro msg
	void roomInfo();
	void startRoom(); //Starts room's question
	//include future room functions
};

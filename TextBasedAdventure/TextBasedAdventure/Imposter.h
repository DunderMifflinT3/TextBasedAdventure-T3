#pragma once
#include <iostream>

using namespace std;

#ifndef Imposter_H
#define Imposter_H

class Imposter
{
private:
	int currentRoomID;
public:
	//Constructors
	Imposter()
	{
	}

	Imposter(int startRoom)
	{
		currentRoomID = startRoom;
	}

	int getCurrentRoomID()
	{
		return currentRoomID;
	}

	void moveRooms(int roomID)
	{
		currentRoomID = roomID;
	}
};

#endif
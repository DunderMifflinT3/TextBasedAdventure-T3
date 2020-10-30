#pragma once

#include <iostream>
#include <array>
#include "Question.h"
using namespace std;

#ifndef Room_H
#define Room_H

const int MAXADJACENTROOMS = 5;

class Room
{
private:
	int roomID;
	string roomName;
	bool isPlayerInRoom;	//Checks if player is in room. May be useful for future functions
	int numOfAdjacentRooms;	//Amount of rooms connected to this room. Used to interate for loops involving adjacent room array.
	int adjacentRooms[MAXADJACENTROOMS];	//A list of rooms connected to this room
	int question;			//Question called from this room
	string item;
	int randomCode; //Code generator
	bool isCompleted = false;
	bool power = false;

public:
	
	//Constructors
	Room()
	{
	}

	Room(int id, string name, int adj[MAXADJACENTROOMS], int numOfAdj, int quest, string itm)
	{
		roomID = id;
		roomName = name;
		numOfAdjacentRooms = numOfAdj;
		question = quest;
		item = itm;
		
		for (int i = 0; i < MAXADJACENTROOMS; i++)
		{
			adjacentRooms[i] = adj[i];
		}
	}

	//Destructor
	~Room()
	{
	}

	//Get Functions
	int getRoomID()
	{
		return roomID;
	}

	string getRoomName()
	{
		return roomName;
	}

	int getAdjacentRooms(int i)
	{
		return adjacentRooms[i];
	}

	int getNumOfAdjacentRooms()
	{
		return numOfAdjacentRooms;
	}

	int getRoomQuestion()
	{
		return question;
	}

	string getRoomItem()
	{
		return item;
	}

	bool getIsCompleted()
	{
		return isCompleted;
	}
	/*void setPower(bool p)
	{
		power = p;
	}*/
	bool getPower()
	{
		return power;
	}
	//Change Room to Completed
	void completeRoom()
	{
		isCompleted = true;
	}
	//Gives power to room
	void powerRoom()
	{
		power = true;
	}
	int noteCode()
	{
		srand(time(NULL));
		randomCode = rand() % 9000 + 1000; //Generates different code every game
		return randomCode;
	}
	void resetRoom()
	{	
		isCompleted = false;
		power = false;
	}
};

#endif

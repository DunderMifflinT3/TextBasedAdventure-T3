#pragma once

#include <iostream>
#include <array>
using namespace std;

#ifndef Room_H
#define Room_H

const int MAXADJACENTROOMS = 4;

class Room
{
private:
	int roomID;
	string roomName;
	bool isPlayerInRoom;	//Checks if player is in room. May be useful for future functions
	int numOfAdjacentRooms;	//Amount of rooms connected to this room. Used to interate for loops involving adjacent room array.
	int adjacentRooms[MAXADJACENTROOMS];	//A list of rooms connected to this room

public:
	//Constructors

	Room()
	{
	}

	Room(int id, string name, int adj[MAXADJACENTROOMS], int numOfAdj)
	{
		roomID = id;
		roomName = name;
		numOfAdjacentRooms = numOfAdj;
		
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

};

#endif

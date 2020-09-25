#pragma once

#include <iostream>
#include <array>
using namespace std;

#ifndef Room_H
#define Room_H

class Room
{
private:
	int roomID;
	string roomName;		
	bool isPlayerInRoom;	//Checks if player is in room. May be useful for future functions
	int numOfAdjacentRooms;	//Amount of rooms connected to this room. Used to interate for loops involving adjacent room array.

	int adjacentRooms[];	//A list of rooms connected to this room

public:

	//Constructor
	Room(int id, string name, int adj[], int numOfAdj)
	{
		setRoomID(id);
		setRoomName(name);
		setNumOfAdjacentRooms(numOfAdj);
		setAdjacentRooms(adj, numOfAdj);
	}

	//Copy Constructor
	Room(const Room &r)
	{
	}

	//Destructor
	~Room()
	{
	}


	//Set Functions
	void setRoomID(int id)
	{
		roomID = id;
	}

	void setRoomName(string name)
	{
		roomName = name;
	}

	void setNumOfAdjacentRooms(int num)
	{
		numOfAdjacentRooms = num;
	}

	void setAdjacentRooms(int adj[], int size)
	{
		for (int i = 0; i < size; i++)
		{	
			adjacentRooms[i] = adj[i];
		}
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

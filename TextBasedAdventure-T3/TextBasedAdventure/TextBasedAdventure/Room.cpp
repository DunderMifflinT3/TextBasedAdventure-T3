//Version 2.0

#include "Room.h"

void enterRoomMessage(Room);
void changeRooms(Room);

//Adjacent Room List. Must have 4 values in array in order for it to be initialized correctly. -1 means there is no room in that spot.
int startAdj[] = { 1,2,3,4 };
int medAdj[] = { 0,2,10,-1 };
int comAdj[] = { 0,1,13,-1 };
int kitAdj[] = { 0,6,9,-1 };
int rEngAdj[] = { 0,11,-1,-1 };
int lEngAdj[] = { 0,7,10,-1 };
int elecAdj[] = { 3,7,-1,-1 };
int jailAdj[] = { 5,6,8,-1 };
int hanAdj[] = { 7,9,-1,-1 };
int louAdj[] = { 3,8,-1,-1 };
int storAdj[] = { 1,5,13,-1 };
int bathAdj[] = { 4,12,-1,-1 };
int weaAdj[] = { 11,13,-1,-1 };
int navAdj[] = { 2,10,12,-1 };

Room currentRoom;	//Room that the player is in

//Initialize Rooms (ID, name, adjacent rooms, amount of adjacent rooms)
Room Start(0, "Bedroom", startAdj, 4);
Room Medical(1, "Medical Room", medAdj, 3);
Room Communication(2, "Communications Room", comAdj, 3);
Room Kitchen(3, "Kitchen", kitAdj, 3);
Room RightEngine(4, "Right Engine Room", rEngAdj, 2);
Room LeftEngine(5, "Left Engine Room", lEngAdj, 3);
Room Electrical(6, "Electrical Room", elecAdj, 2);
Room Jail(7, "Jail", jailAdj, 3);
Room Hangar(8, "Hangar", hanAdj, 2);
Room Lounge(9, "Lounge", louAdj, 2);
Room Storage(10, "Storage", storAdj, 3);
Room Bathroom(11, "Bathroom", bathAdj, 2);
Room Weapons(12, "Weapons Room", weaAdj, 2);
Room Navigation(13, "Nagivation Room", navAdj, 3);

Room mapRooms[] = { Start, Medical, Communication, Kitchen, RightEngine, LeftEngine, Electrical,Jail,Hangar,Lounge,Storage,Bathroom,Weapons,Navigation };	//Array of all rooms


int main()
{
	currentRoom = Start; //Sets the room that the player is in
	enterRoomMessage(currentRoom);

	return 0;
}

void enterRoomMessage(Room newRoom)		//Message that plays when room is entered
{
	cout << "You have entered the " << newRoom.getRoomName() << "." << endl;

	changeRooms(newRoom);
}

void changeRooms(Room oldRoom)		//Test for changing rooms
{
	int adjacentIDArray[MAXADJACENTROOMS];	//Array that holds the ids of adjacent rooms

	cout << "You can enter the following rooms:" << endl;

	int roomCount = 1;
	for (int i = 0; i < currentRoom.getNumOfAdjacentRooms(); i++)
	{
		int tempAdjacentID = currentRoom.getAdjacentRooms(i);
		cout << i + 1 << ": " << mapRooms[tempAdjacentID].getRoomName() << endl;
		adjacentIDArray[i] = currentRoom.getAdjacentRooms(i);
	}

	int choice;

	cin >> choice;		//To Do: Input Validation

	currentRoom = mapRooms[adjacentIDArray[choice - 1]];	//Sets the new current room to the chosen value

	enterRoomMessage(currentRoom);
}

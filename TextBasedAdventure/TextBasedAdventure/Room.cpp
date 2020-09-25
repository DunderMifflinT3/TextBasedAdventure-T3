//Version 1.0

#include "Room.h"

//Adjacent Room List
int startAdj[] = { 1,2,3,4 };
int medAdj[] = { 0,2,10 };
int comAdj[] = { 0,1,13 };
int kitAdj[] = { 0,6,9 };
int rEngAdj[] = { 0,11 };
int lEngAdj[] = { 0,7,10 };
int elecAdj[] = { 3,7 };
int jailAdj[] = { 5,6,8 };
int hanAdj[] = { 7,9 };
int louAdj[] = { 3,8 };
int storAdj[] = { 1,5,13 };
int bathAdj[] = { 4,12 };
int weaAdj[] = { 11,13 };
int navAdj[] = { 2,10,12 };


int main()
{
	//Initialize Rooms (ID, name, adjacent rooms, amount of adjacent rooms)
	Room Start(0, "Bedroom", startAdj, sizeof(startAdj));
	Room Medical(1, "Medical Room", medAdj, sizeof(medAdj));
	Room Communication(2, "Communications Room", comAdj, sizeof(comAdj));
	Room Kitchen(3, "Kitchen", kitAdj, sizeof(kitAdj));
	Room RightEngine(4, "Right Engine Room", rEngAdj, sizeof(rEngAdj));
	Room LeftEngine(5, "Left Engine Room", lEngAdj, sizeof(lEngAdj));
	Room Electrical(6, "Electrical Room", elecAdj, sizeof(elecAdj));
	Room Jail(7, "Jail", jailAdj, sizeof(jailAdj));
	Room Hangar(8, "Hangar", hanAdj, sizeof(hanAdj));
	Room Lounge(9, "Lounge", louAdj, sizeof(louAdj));
	Room Storage(10, "Storage", storAdj, sizeof(storAdj));
	Room Bathroom(11, "Bathroom", bathAdj, sizeof(bathAdj));
	Room Weapons(12, "Weapons Room", weaAdj, sizeof(weaAdj));
	Room Navigation(13, "Nagivation Room", navAdj, sizeof(navAdj));

	Room currentRoom = Start;	//Calls copy constructor. Change this value to check adjacent rooms (Does not currently work).

	cout << currentRoom.getAdjacentRooms(4) << endl;	//Works when using any of the initialized rooms, just not with currentRoom.

	//For loop does not work when using i<getNumOfAdjacentRooms. Only works when replacing it with an actual number.
	for (int i = 0; i < Start.getNumOfAdjacentRooms(); i++)
	{
		cout << Start.getAdjacentRooms(i) << endl;
	}
}


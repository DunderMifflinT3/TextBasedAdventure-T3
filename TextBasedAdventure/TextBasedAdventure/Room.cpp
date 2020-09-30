//Version 2.0

#include "Room.h"
#include "Question.h"
#include <Windows.h>

void enterRoomMessage(Room);
void changeRooms(Room);

string ans1[] = { "Eight", "Seven", "Ten", "Nine" };//possible answers
Question q1("How many planets are in our Solar System?", ans1, 'A');//sets up the question & answer as q1
string ans2[] = { "Mercury", "Venus", "Mars", "Saturn" };
Question q2("Which planet has the most moons?", ans2, 'D');
string ans3[] = { "320,543,121 km", "149,600,000 km", "405,800,000 km", "250,300,000 km" };
Question q3("What is the distance between the Sun and Earth?", ans3, 'B');

Question questionArray[] = { q1,q2,q3 };	//Array of all questions

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
Room Start(0, "Bedroom", startAdj, 4, 0);
Room Medical(1, "Medical Room", medAdj, 3, 1);
Room Communication(2, "Communications Room", comAdj, 3, 2);
Room Kitchen(3, "Kitchen", kitAdj, 3, 3);
Room RightEngine(4, "Right Engine Room", rEngAdj, 2, 4);
Room LeftEngine(5, "Left Engine Room", lEngAdj, 3, 5);
Room Electrical(6, "Electrical Room", elecAdj, 2, 6);
Room Jail(7, "Jail", jailAdj, 3, 7);
Room Hangar(8, "Hangar", hanAdj, 2, 8);
Room Lounge(9, "Lounge", louAdj, 2, 9);
Room Storage(10, "Storage", storAdj, 3, 10);
Room Bathroom(11, "Bathroom", bathAdj, 2, 11);
Room Weapons(12, "Weapons Room", weaAdj, 2, 12);
Room Navigation(13, "Nagivation Room", navAdj, 3, 13);

Room mapRooms[] = { Start, Medical, Communication, Kitchen, RightEngine, LeftEngine, Electrical,Jail,Hangar,Lounge,Storage,Bathroom,Weapons,Navigation };	//Array of all rooms

void displayRoomMessage(int id) //Displays message when room is not complete
{
	switch (id)
	{
	case(0):
		{
			break;
		}
	case(1):
		{
			cout << " It seems like someone has broken into the medical supplies" << endl;
			break;
		}
	case(2):
		{
			break;
		}
	case(3):
		{
			cout << "The kitchen knives are missing and the room is a mess. Food is all over the floor, " << endl;
			cout << "cabinets have been left open. Seems like someone was really hungry." << endl;
			break;
		}
	case(4):
		{
			break;
		}
	case(5):
		{
			break;
		}
	case(6):
		{
			break;
		}
	case(7):
		{
			break;
		}
	case(8):
		{
			break;
		}
	case(9):
		{
			break;
		}
	case(10):
		{
			break;
		}
	case(11):
		{
			break;
		}
	case(12):
		{
			break;
		}
	case(13):
		{
			break;
		}
	default:
		{
		cout << "Error" << endl;
		}
	}
}


int main()
{

	cout << "You have just woken up on a spaceship that is part of a space bounty expedition" << endl;
	cout << "to capture a most wanted alien and the ship is quickly spiraling out of control towards Earth." << endl;
	cout << "You realize your crewmates are missing, the power is out and the ships gadgets" << endl;
	cout << "seem to have been tampered with. You also realize there is a hole in the ship" << endl;
	cout << "and your oxygen is dropping quickly. Your mission is to find your crew, " << endl;
	cout << "repair the ship by fixing parts in each room so you can return home safely, and ultimately SURVIVE!" << endl << endl;
	Sleep(3000); //Gives user time to read script

	currentRoom = Start; //Sets the room that the player is in
	enterRoomMessage(currentRoom);

	return 0;
}

void enterRoomMessage(Room newRoom)		//Message that plays when room is entered
{
	cout << "You have entered the " << newRoom.getRoomName() << "." << endl;
	
	//Displays room question based on questionArray
	questionArray[currentRoom.getRoomQuestion()].display();
	char choice;
	cin >> choice;
	questionArray[currentRoom.getRoomQuestion()].correctAnswer(choice);

	//Asks to change rooms. Will be moved.
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

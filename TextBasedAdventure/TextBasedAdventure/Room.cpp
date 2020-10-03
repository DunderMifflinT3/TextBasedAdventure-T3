//Version 3.1
#include <cmath>
#include <math.h>
#include <algorithm>
#include <Windows.h>
#include "Room.h"
#include "Question.h"
#undef max


void enterRoomMessage(Room);
void changeRooms(Room);
bool inputMap(int, double);
bool inputQuestion(int, double); //input validation for questions

//Initialize all questions
string ans1[] = { "Eight", "Seven", "Ten", "Nine" };//possible answers
Question q1("How many planets are in our Solar System?", ans1, 1);//sets up the question & answer as q1
string ans2[] = { "Mercury", "Venus", "Mars", "Saturn" };
Question q2("Which planet has the most moons?", ans2, 4);
string ans3[] = { "320,543,121 km", "149,600,000 km", "405,800,000 km", "250,300,000 km" };
Question q3("What is the distance between the Sun and Earth?", ans3, 2);
string ans4[] = { "10.2 billion years old", "25.4 billion years old", "13.8 billion years old", "9 billion years old" };
Question q4("How old is the universe in years? (Plus or minus 1 billion years.)", ans4, 3);
string ans5[] = { "Mercury", "Venus", "Mars", "Saturn" };
Question q5("What is the smallest planet in our solar system?", ans5, 1);
string ans6[] = { "Mercury", "Jupiter", "Venus", "Saturn" };
Question q6("What is the largest planet in our solar system ?", ans6, 2);
string ans7[] = { "Sun", "Blue star", "Red dwarf stars", "Red supergiant stars" };
Question q7("What is the largest type of star in the universe ?", ans7, 4);
string ans8[] = { "Black Hole", "My Ex", "Earth", "Supernova" };
Question q8("What has a gravitational pull so strong that even light cannot escape it?", ans8, 1);
string ans9[] = { "Apache 19", "USSR Falcon", "Apollo 17", "Space-X" };
Question q9("Which NASA space flight was the last manned mission to the moon?", ans9, 3);
string ans10[] = { "130 min", "45 min", "60 min", "15 min" };
Question q10("How many minutes was the shortest space flight?", ans10, 4);
string ans11[] = { "80", "181", "56", "125" };
Question q11("How many moons are in our Solar System?", ans11, 2);
string ans12[] = { "Sun", "Jupiter", "Venus", "Saturn" };
Question q12("What is the hottest planet in our solar system ?", ans12, 3);
string ans13[] = { "Michael Collins", "Buzz Aldrin", "Freddy Mercury", "Neil Armstrong" };
Question q13("Who was the first person to walk on the moon?", ans13, 4);
string ans14[] = { "Titan", "Mimas", "Rhea", "Phoebe" };
Question q14("What is the name of Saturn’s largest moon?", ans14, 1);

Question questionArray[] = { q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14 };	//Array of all questions (Randomize this in order to get

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

void displayRoomMessage(int id) //Displays message when room is not complete. Cases correspond to room IDs.
{
	switch (id)
	{
	case(0):
		{
			break;
		}
	case(1):
		{
		cout << "It seems like someone has broken into the medical supplies" << endl;
			break;
		}
	case(2):
		{
		cout << "Communication throughout the ship and any external communication seems to be down." << endl;
		cout << "You notice that the main transmitter is destroyed. Fixing communications could" << endl;
		cout << "allow you to get in touch with your team at home and tell them about the situation." << endl;
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
		cout << "The ship’s fuel levels are low, you need to refill the ship’s fuel" << endl;
		cout << "You see a fuel container next to the fuel tank." << endl;
			break;
		}
	case(5):
		{
		cout << "You notice a leak in the engine and the fuel levels dropping." << endl;
			break;
		}
	case(6):
		{
		cout << "The power is off throughout most of the ship, the only thing keeping the " << endl;
		cout << "systems online right now is the backup generator. The power box has the wires ripped out " << endl;
		cout <<	"you need to find some way to connect the wires again and get the power back online. " << endl;
			break;
		}
	case(7):
		{
		cout << "You have entered the cell where you expect to find the alien you and your crew have " << endl;
		cout << "captured and are transporting back home. Unfortunately you notice that the cell has " << endl;
		cout <<	"been opened by force and the alien captive is missing." << endl;
			break;
		}
	case(8):
		{
		cout << "The room has a few escape pods however, they all seem to be completely broken, " << endl;
		cout << "trying to fix these would be a waste of time." << endl;
			break;
		}
	case(9):
		{
		cout << "There isn’t much in the lounge except some couches and playing cards from the day before." << endl;
			break;
		}
	case(10):
		{
		cout << " ";
			break;
		}
	case(11):
		{
		cout << "The shower is running and the mirror is broken. You see the word HELP written on the wall in what seems to be blood." << endl;
			break;
		}
	case(12):
		{
		cout << "There is a container with one gun in it for emergencies. " << endl;
		cout << "(Power needs to be restored from the electrical room in order to open this container)" << endl;
			break;
		}
	case(13):
		{
		cout << "You find the pilot murdered in their chair and the command console is flashing red with " << endl;
		cout << "the word “WARNING!” on the screen. Here you can check the console for progress on completed " << endl;
		cout << "repairs you have made to the ship.  “Check Console” to check progress of repaired systems. " << endl;
		cout << "x amount of systems are online out of x." << endl;
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
	cout << "-------------------------------------------------------------------------------------------------------------" << endl << endl;	//Separates screen when entering a new room.
	cout << "You have entered the " << newRoom.getRoomName() << "." << endl << endl;

	//Displays room message if room is not completed
	if (currentRoom.getIsCompleted() == false)
	{
		displayRoomMessage(currentRoom.getRoomID());

		//Displays room question based on questionArray
		questionArray[currentRoom.getRoomQuestion()].display();
		int ansChoice;
		double ansChoiceCopy;
		cin >> ansChoiceCopy; //send for input validation
		ansChoice = ansChoiceCopy;
		while (inputMap(ansChoice, ansChoiceCopy) == false)
		{
			cin >> ansChoiceCopy;
			ansChoice = ansChoiceCopy;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl;
		}
		if (questionArray[currentRoom.getRoomQuestion()].isCorrectAnswer(choice))
		{
			mapRooms[currentRoom.getRoomID()].completeRoom();
			cout << "You have completed everything in this room." << endl << endl;
		}
	}
	else
	{
		cout << "There is nothing else for you to do in this room." << endl;
		cout << endl;
	}

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
	double choiceCopy;
	cin >> choiceCopy;		//To Do: Input Validation
	choice = choiceCopy;
	while (inputMap(choice, choiceCopy) == false)
	{
		cin >> choiceCopy;
		choice = choiceCopy;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	currentRoom = mapRooms[adjacentIDArray[choice - 1]];	//Sets the new current room to the chosen value

	enterRoomMessage(currentRoom);
}
bool inputMap(int choice, double choiceCopy)
{
	if (floor(choiceCopy) != choiceCopy)
	{
		cout << "Enter in valid value" << endl;

		return false;
	}
	else if (choice > currentRoom.getNumOfAdjacentRooms() || choice <= 0)
	{
		cout << "Enter in valid value" << endl;
		return false;
	}
}
bool inputQuestion(int ansChoice, double choiceCopy)
{
	if (floor(choiceCopy) != choiceCopy)
	{
		cout << "Enter in valid value" << endl;

		return false;
	}
	else if (ansChoice > currentRoom.getNumOfAdjacentRooms() || ansChoice <= 0)
	{
		cout << "Enter in valid value" << endl;
		return false;
	}
}

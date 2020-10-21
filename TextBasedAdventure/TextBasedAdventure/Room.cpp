//Version 4
#include <cmath>
#include <math.h>
#include <algorithm>
#include <Windows.h>
#include <iostream>
#include <time.h>
#include "Room.h"
#include "Question.h"
#include "Player.h"
#include "Imposter.h"
#undef max

void enterRoomMessage(Room);
void changeRooms(Room);
bool inputMap(int, double);
bool inputQuestion(int, double); //input validation for questions
bool roomPower(Room); //Powers up rooms
void getRoomActions(Room);
void map();
void Help();
void escape();
void investigate(int);

Player player1("Player 1", 100);
Imposter imposter(7);

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

int userChoice;
int choice;
double choiceCopy;

Room currentRoom;	//Room that the player is in
//Initialize Rooms (ID, name, adjacent rooms, amount of adjacent rooms, question ID, item)
Room Start(0, "Bedroom", startAdj, 4, 0, "Flashlight");
Room Medical(1, "Medical Room", medAdj, 3, 1, "");
Room Communication(2, "Communications Room", comAdj, 3, 2, "");
Room Kitchen(3, "Kitchen", kitAdj, 3, 3, "Note");
Room RightEngine(4, "Right Engine Room", rEngAdj, 2, 4, "");
Room LeftEngine(5, "Left Engine Room", lEngAdj, 3, 5, "");
Room Electrical(6, "Electrical Room", elecAdj, 2, 6, "");
Room Jail(7, "Jail", jailAdj, 3, 7, "");
Room Hangar(8, "Hangar", hanAdj, 2, 8, "Escape Plan");
Room Lounge(9, "Lounge", louAdj, 2, 9, "Oxygen Tank");
Room Storage(10, "Storage", storAdj, 3, 10, "Wrench");
Room Bathroom(11, "Bathroom", bathAdj, 2, 11, "");
Room Weapons(12, "Weapons Room", weaAdj, 2, 12, "Weapon");
Room Navigation(13, "Nagivation Room", navAdj, 3, 13, "Key Card");

Room mapRooms[] = { Start, Medical, Communication, Kitchen, RightEngine, LeftEngine, Electrical, Jail, Hangar, Lounge, Storage, Bathroom, Weapons, Navigation };	//Array of all rooms

const int randomCode = currentRoom.noteCode(); //Generates Random Code Every Game For Hanger

bool roomPower(Room Electrical) 
{
	if (mapRooms[6].getIsCompleted() == true) //Complete task in Electrical room to turn power on
	{
		for (int i = 0; i < 14; i++)
		{
			mapRooms[i].powerRoom();
		}
		cout << "Power is online." << endl << endl;
		return true;
	}
	else
	{
		cout << "Power is still off, find correct room to turn online." << endl << endl;
		return false;
	}
	
}
void displayRoomMessage(int id) //Displays message when room is not complete. Cases correspond to room IDs.
{
	switch (id)
	{
	case(0):
		{
		if (roomPower(Electrical) == false)
			cout << "Room does not have power, find the correct room to turn on power." << endl << endl;
		else
			cout << endl;
		break;
		}
	case(1):
		{
		if (roomPower(Electrical) == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
			changeRooms(Medical); //if locked change rooms
		}
		if (roomPower(Electrical) == true)
		{
			cout << "It seems like someone has broken into the medical supplies" << endl;
			cout << endl;
		}
		else 
		{
			cout << "error" << endl;
		}
		break;
		}
	case(2):
		{
			cout << "Communication throughout the ship and any external communication seems to be down." << endl;
			cout << "You notice that the main transmitter is destroyed. Fixing communications could" << endl;
			cout << "allow you to get in touch with your team at home and tell them about the situation." << endl << endl; 
		break;
		}
	case(3):
		{
			cout << "The kitchen knives are missing and the room is a mess. Food is all over the floor, " << endl;
			cout << "cabinets have been left open. Seems like someone was really hungry." << endl << endl;
		break;
		}
	case(4):
		{
		if (roomPower(Electrical) == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
			changeRooms(RightEngine);
		}
		else
		{
			cout << "The ship’s fuel levels are low, you need to refill the ship’s fuel" << endl;
			cout << "You see a fuel container next to the fuel tank." << endl << endl;
		}
		break;
		}
	case(5):
		{
			cout << "You notice a leak in the engine and the fuel levels dropping." << endl << endl;
		break;
		}
	case(6):
		{
			cout << "The power is off throughout most of the ship, the only thing keeping the " << endl;
			cout << "systems online right now is the backup generator. The power box has the wires ripped out " << endl;
			cout <<	"you need to find some way to connect the wires again and get the power back online. " << endl << endl;
			cout << "Complete the following task correctly to turn power online: " << endl;
		break;
		}
	case(7):
		{
			cout << "You have entered the cell where you expect to find the alien you and your crew have " << endl;
			cout << "captured and are transporting back home. Unfortunately you notice that the cell has " << endl;
			cout << "been opened by force and the alien captive is missing." << endl << endl;
		break;
		}
	case(8):
		{
		if (roomPower(Electrical) == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
			changeRooms(Hangar);
		}
		else
		{
			cout << "The room has a few escape pods however, it seems they are offline." << endl;
			cout << "Complete the task to activate the pods." << endl;
		}
		break;
		}
	case(9):
		{
			cout << "There isn’t much in the lounge except some couches and playing cards from the day before." << endl;
			cout << endl;
		break;
		}
	case(10):
		{
		if (roomPower(Electrical) == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
			changeRooms(Storage);
		}
		else
		cout << " ";
		cout << endl;
			break;
		}
	case(11):
		{
		if (roomPower(Electrical) == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
			changeRooms(Bathroom);
		}
		else
		{
			cout << "The shower is running and the mirror is broken. You see the word HELP written on the wall in what seems to be blood." << endl;
			cout << endl;
		}
		break;
		}
	case(12):
		{
		if (roomPower(Electrical) == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
			changeRooms(Weapons);
		}
		else
		{
			cout << "There is a container with one gun in it for emergencies. " << endl;
			cout << "(Power needs to be restored from the electrical room in order to open this container)" << endl;
			cout << endl;
		}
		break;
		}
	case(13):
		{
		if (roomPower(Electrical) == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
			changeRooms(Navigation);
		}
		else
		{
			cout << "You find the pilot murdered in their chair and the command console is flashing red with " << endl;
			cout << "the word “WARNING!” on the screen. Here you can check the console for progress on completed " << endl;
			cout << "repairs you have made to the ship.  “Check Console” to check progress of repaired systems. " << endl;
			cout << "x amount of systems are online out of x." << endl;
			cout << endl;
		}
		break;
		}
	default:
		{
		cout << "Error" << endl;
		cout << endl;
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

	if (imposter.getCurrentRoomID() == newRoom.getRoomID())	//Checks if imposter is in the same room
	{
		cout << "You feel another presence in this room..." << endl;
		cout << "You're being attacked!" << endl;
	}
	
	getRoomActions(newRoom);
}

void changeRooms(Room oldRoom)		//Test for changing rooms
{
	int adjacentIDArray[MAXADJACENTROOMS];	//Array that holds the ids of adjacent rooms

	cout << "You can enter the following rooms:" << endl << endl;

	int roomCount = 1;
	for (int i = 0; i < currentRoom.getNumOfAdjacentRooms(); i++)
	{
		int tempAdjacentID = currentRoom.getAdjacentRooms(i);
		cout << i + 1 << ": " << mapRooms[tempAdjacentID].getRoomName() << endl;
		adjacentIDArray[i] = currentRoom.getAdjacentRooms(i);
	}
		
	int choice;
	double choiceCopy;
	cin >> choiceCopy;		
	choice = choiceCopy;
	while (inputMap(choice, choiceCopy) == false)
	{
		cin >> choiceCopy;
		choice = choiceCopy;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	currentRoom = mapRooms[adjacentIDArray[choice - 1]];	//Sets the new current room to the chosen value

	imposter.moveRooms(rand() % 13 + 1);	//Imposter changes rooms when player does (TO DO: Change formula for the rooms it picks)

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
	return true;
}

bool inputQuestion(int ansChoice, double choiceCopy)
{
	if (floor(choiceCopy) != choiceCopy)
	{
		cout << "Enter in valid value" << endl;

		return false;
	}
	else if (ansChoice > 4 || ansChoice <= 0)
	{
		cout << "Enter in valid value" << endl;
		return false;
	}
	return true;
}

void getRoomActions(Room newRoom)
{
	double userChoiceCopy;
	
	cout << "What would you like to do in the " << newRoom.getRoomName() << "?" << endl << endl;
	cout << "1. Complete Task" << endl;
	cout << "2. Investigate" << endl;
	cout << "3. Leave" << endl;
	cout << "4. Inventory" << endl;
	cout << "5. Map" << endl;
	cout << "6. Help" << endl;
	cin >> userChoiceCopy;
		
	userChoice = userChoiceCopy;
	while (userChoice > 6 || userChoice < 1)
	{
		cout << "Invalid input" << endl;
		cin >> userChoice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		userChoiceCopy = userChoice;
	}
	while (userChoiceCopy != floor(userChoiceCopy))
	{
		cout << "Invalid input" << endl;
		
		cin >> userChoiceCopy;
	}
	userChoice = userChoiceCopy;
	switch (userChoice)
	{
	case(1): 
		{
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
			while (inputQuestion(ansChoice, ansChoiceCopy) == false)
			{
				cin >> ansChoiceCopy;
				ansChoice = ansChoiceCopy;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl;
			}
			if (questionArray[currentRoom.getRoomQuestion()].isCorrectAnswer(ansChoice))
			{
				mapRooms[currentRoom.getRoomID()].completeRoom();
				cout << "You have completed everything in this room." << endl << endl;

			}
			else
			{
				player1.takeDamage(10);		//Player Takes damage if answer is wrong
				cout << "Current Oxygen: " << player1.getCurrentHP() << " / " << player1.getMaxHP() << endl;
			}
		}
		else
		{
			cout << "There is nothing else for you to do in this room." << endl;
			cout << endl;
		}
		currentRoom = mapRooms[newRoom.getRoomID()];
		getRoomActions(currentRoom);
		break;
		}
	case(2):
		{
		investigate(currentRoom.getRoomID());
		getRoomActions(currentRoom);
		break;
		}
	case(3):
		{
		changeRooms(newRoom);
		break;
		}
	case(4):
	{
		if (player1.inventory.empty())
		{
			cout << "There are no objects in your inventory." << endl << endl;
		}
		else
		{
			cout << "Inventory:" << endl;
			player1.showInventory();
			cout << endl;
		}
		getRoomActions(currentRoom);
		break;
	}
	case(5):
		{
		map();
		getRoomActions(currentRoom);
		break;	
		}	
	case(6):
		{
		Help();
		getRoomActions(currentRoom);
		break;
		}
	}
}

void Help()
{
	cout << "Choose a room to navigate to from the displayed map / room list" << endl;
	cout << "Each room will have a description when you go into the room with a minigame to fix gadgets or objects you can pick up(Air tank, weapon, tools, paper with a code on it for another minigame they may have to remember.)" << endl;
	cout << "To win the game, you must repair all gadgetsand get the weapon before the killer" << endl;
	cout << "Failing at a minigame too many times, lowers total air supply which can kill you.You are able to replenish your air supply by picking up air tanks around the map." << endl;
	cout << "Be careful because if the Killer gets to you or you run out of time trying to repair the ship, YOU WILL LOSE" << endl;
}

void map()
{
	cout << "  ----------Navigation-------------Weapons" << endl;
	cout << "  |                                 |" << endl;
	cout << "  | MedBay------|                Bathroom" << endl;
	cout << "  |  |          |---Communication    |" << endl;
	cout << "Storage         |                    |" << endl;
	cout << "  |             |                    |" << endl;
	cout << "LEngine-------Bedroom-------------REngine" << endl;
	cout << "  |            |              " << endl;
	cout << "  |     -----Kitchen----------      " << endl;
	cout << "  |     |                    |     " << endl;
	cout << "  |  Electric              Lounge    " << endl;
	cout << "  |     |                    |     " << endl;
	cout << " Jail---|                  Hanger     " << endl;
	cout << "  |__________________________|     " << endl;
}

void escape()
{
	if (mapRooms[8].getIsCompleted() == true)
	{
		int code;
		cout << "The escape pod is online! Please enter 4 digit code to enter pod: " << endl;
		cin >> code;

		if (code == randomCode)
		{
			cout << "Access Granted!" << endl << endl;
			cout << "Congradulations! You have succesfully escaped the ship and are safely headed back to Earth!" << endl;
		}
		else
		{
			cout << "Access Denied" << endl << endl;
			cout << "Maybe the code can found in one of the rooms" << endl;
			getRoomActions(currentRoom);
		}
	}
	else
	{
		cout << "Please complete the task to activate the pod." << endl;
		getRoomActions(currentRoom);
	}
}

void investigate(int id)
{
	switch (id)
	{
	case(0)://Bedroom
	{
		if (!player1.searchInventory("Flashlight"))	//If flashlight is not in inventory, adds it
		{
			cout << "After carefully investigating " << currentRoom.getRoomName() << ", you have found a Flashlight" << endl << endl;
			player1.addToInventory("Flashlight");
		}
		else
		{
			cout << "After carefully investigating " << currentRoom.getRoomName() << ", there is nothing to be found here." << endl << endl;
		}
		break;
	}
	case(1)://Medical
	{
		if (roomPower(Electrical) == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
		}
		//if (roomPower(Electrical) == true)
		else
		{
			if (!player1.getCollectedOxygenTank(id))
			{
				cout << "After carefully investigating " << currentRoom.getRoomName() << ", you have found a Oxygen Tank" << endl;
				player1.increaseMaxHP(20);
				player1.healDamage(20);
				player1.setCollectedOxygenTanks(id);
			}
			else
			{
				cout << "After carefully investigating " << currentRoom.getRoomName() << ", there is nothing to be found here." << endl << endl;
			}
		}
		break;
	}
	case(2)://Communications
	{
		if (roomPower(Electrical) == false)
		{
			if (player1.searchInventory("Flashlight"))
			{
				cout << "Room is too dark, you turned on your Flashlight" << endl;
				cout << "After carefully investigating " << currentRoom.getRoomName() << ", there is nothing to be found here." << endl << endl;
			}
			else
			{
				cout << "It is too dark to see anything please turn on power first." << endl << endl;
			}
		}
		else
		{
			cout << "After carefully investigating " << currentRoom.getRoomName() << ", there is nothing to be found here." << endl << endl;
		}
		break;
	}
	case(3)://Kitchen
	{   if (roomPower(Electrical) == false)
		{
			if (player1.searchInventory("Flashlight"))
			{
				cout << "Room is too dark, you turned on your Flashlight" << endl;
				cout << "After carefully investigating " << currentRoom.getRoomName() << ", you have found a Note." << endl;
				cout << "The note says IN CASE OF EMERGENCY " << randomCode << " ... the rest of the note is not legible." << endl << endl;
				player1.addToInventory("Note");
			}
			else
			{
				cout << "It is too dark to see anything please turn on power first." << endl << endl;
			}
	}
	else
	{
		cout << "After carefully investigating " << currentRoom.getRoomName() << ", you have found a Note." << endl;
		cout << "The note says IN CASE OF EMERGENCY " << randomCode << " ... the rest of the note is not legible." << endl << endl;
		player1.addToInventory("Note");
	}
		break;
	}
	case(4)://R Engine
	{
		if (roomPower(Electrical) == false)
		{
			if (player1.searchInventory("Flashlight"))
			{
				cout << "Room is too dark, you turned on your Flashlight" << endl;
				cout << "After carefully investigating " << currentRoom.getRoomName() << ", there is nothing to be found here." << endl << endl;
			}
			else
			{
				cout << "It is too dark to see anything please turn on power first." << endl << endl;
			}
		}
		else
		{
			cout << "After carefully investigating " << currentRoom.getRoomName() << ", there is nothing to be found here." << endl << endl;
		}
		break;
	}
	case(5)://L Engine
	{		
		if (roomPower(Electrical) == false)
		{
			if (player1.searchInventory("Flashlight"))
			{
				cout << "Room is too dark, you turned on your Flashlight" << endl;
				cout << "After carefully investigating " << currentRoom.getRoomName() << ", there is nothing to be found here." << endl << endl;
			}
			else
			{
				cout << "It is too dark to see anything please turn on power first." << endl << endl;				
			}
		}
		else
		{
			cout << "After carefully investigating " << currentRoom.getRoomName() << ", there is nothing to be found here." << endl << endl;
		}
		break;	
	}
	case(6)://Electircal
	{
		if (roomPower(Electrical) == false)
		{
			if (player1.searchInventory("Flashlight"))
			{
				cout << "Room is too dark, you turned on your Flashlight" << endl;
				cout << "After carefully investigating " << currentRoom.getRoomName() << ", there is nothing to be found here." << endl << endl;
			}
			else
			{
				cout << "It is too dark to see anything please turn on power first." << endl << endl;
			}
		}
		else
		{
			cout << "After carefully investigating " << currentRoom.getRoomName() << ", there is nothing to be found here." << endl << endl;
		}
		break;
	}
	case(7)://Jail
	{
		if (roomPower(Electrical) == false)
		{
			if (player1.searchInventory("Flashlight"))
			{
				cout << "Room is too dark, you turned on your Flashlight" << endl;
				cout << "After carefully investigating " << currentRoom.getRoomName() << ", there is nothing to be found here." << endl << endl;
			}
			else
			{
				cout << "It is too dark to see anything please turn on power first." << endl << endl;
			}
		}
		else
		{
			cout << "After carefully investigating " << currentRoom.getRoomName() << ", there is nothing to be found here." << endl << endl;
		}
		break;
	}
	case(8)://Hanger
	{
		if (roomPower(Electrical) == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
		}
		else
		{
			escape();
		}
		break;
	}
	case(9)://Lounge
	{
		if (roomPower(Electrical) == false)
		{
			if (player1.searchInventory("Flashlight"))
			{
				if (!player1.getCollectedOxygenTank(id))
				{
					cout << "After carefully investigating " << currentRoom.getRoomName() << ", you have found a Oxygen Tank" << endl;
					player1.increaseMaxHP(20);
					player1.healDamage(20);
					player1.setCollectedOxygenTanks(id);
				}
				else
				{
					cout << "After carefully investigating " << currentRoom.getRoomName() << ", there is nothing to be found here." << endl << endl;
				}
			}
			else
			{
				cout << "It is too dark to see anything please turn on power first." << endl << endl;
			}
		}
		else
		{
			if (!player1.getCollectedOxygenTank(id))
			{
				cout << "After carefully investigating " << currentRoom.getRoomName() << ", you have found a Oxygen Tank" << endl;
				player1.increaseMaxHP(20);
				player1.healDamage(20);
				player1.setCollectedOxygenTanks(id);
			}
			else
			{
				cout << "After carefully investigating " << currentRoom.getRoomName() << ", there is nothing to be found here." << endl << endl;
			}
		}
		break;
	}
	case(10)://Storage
	{
		if (roomPower(Electrical) == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
		}
		else
		{
			if (!player1.searchInventory("Wrench"))
			{
				cout << "After carefully investigating " << currentRoom.getRoomName() << ", you have found a Wrench" << endl << endl;
				player1.addToInventory("Wrench");
			}
			else
			{
				cout << "After carefully investigating " << currentRoom.getRoomName() << ", there is nothing to be found here." << endl << endl;
			}
		}
		break;
	}
	case(11)://Bathroom
	{
		if (roomPower(Electrical) == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
		}
		else
		{
			cout << "After carefully investigating " << currentRoom.getRoomName() << ", there is nothing to be found here." << endl << endl;
		}
		break;
	}
	case(12)://Weapons
	{
		if (roomPower(Electrical) == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
		}
		else
		{
			if (!player1.searchInventory("Weapon"))
			{
				cout << "After carefully investigating " << currentRoom.getRoomName() << ", you have found a Weapon" << endl << endl;
				player1.addToInventory("Weapon");
			}
			else
			{
				cout << "After carefully investigating " << currentRoom.getRoomName() << ", there is nothing to be found here." << endl << endl;
			}
		}
		break;
	}
	case(13)://Navigation
	{
		if (roomPower(Electrical) == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
		}
		else
		{
			if (!player1.searchInventory("Key Card"))
			{
				cout << "After carefully investigating " << currentRoom.getRoomName() << ", you have found a Key-card" << endl << endl;
				player1.addToInventory("Key Card");
			}
			else
			{
				cout << "After carefully investigating " << currentRoom.getRoomName() << ", there is nothing to be found here." << endl << endl;
			}
		}
		break;
	}
	default:
	{
		cout << "Error 1" << endl;
		cout << endl;
	}
	}
}

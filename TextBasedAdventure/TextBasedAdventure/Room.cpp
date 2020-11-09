//Version 4.5
#include <cmath>
#include <math.h>
#include <algorithm>
#include <Windows.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include "Room.h"
#include "Question.h"
#include "Player.h"
#include "Imposter.h"
#include "R_P_S.cpp"
#include "InputValidation.h"
#include "Color.h"
#include <string>

void enterRoomMessage(Room);
void changeRooms(Room);
bool isShipPowered(); //Checks if task in Electrical is complete to power rooms
void getRoomActions(Room);
void map();
void help();
void escape();
void investigate(int);
void turnCounter();
void difficultLevel();
void gameOver();
void playGame();
void playerDeath();
void imposterEncounter();
void quit();
void restart();
int roomsCompleted();

int playerHP = 100;
Player player1("Player 1", playerHP, 0);
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
Question q14("What is the name of Saturns largest moon?", ans14, 1);

Question questionArray[] = { q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14 };	//Array of all questions (Randomize this in order to get

//Adjacent Room List. Must have 4 values in array in order for it to be initialized correctly. -1 means there is no room in that spot.
int startAdj[] = { 1,2,3,4,5 };
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

int turnCount = 0;
int difficulty;
int maxTurnCount;
int imposterReleaseTurn;
//int completedRooms;

//Room currentRoom;	//Room that the player is in

//Initialize Rooms (ID, name, adjacent rooms, amount of adjacent rooms, question ID, item)
Room Start(0, "Bedroom", startAdj, 5, 0, "Flashlight");
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

int randomCode; //Stores Generated Random Code Every Game For Hanger
string randomCodeString;

int roomsCompleted()//Counter for completed tasks
{
	int complete = 0;
	for (int i = 0; i < 14; i++)
	{
		if (i == 8)
		{
			complete = complete; //Doesn't count Hangar, Hangar task for escape scenario
		}
		else if (mapRooms[i].getIsCompleted() == true)
		{
			complete++;
		}
	}
	const int completedRooms = complete; //Made const so counter doesn't duplicate everytime user checks
	return completedRooms;
}
bool isShipPowered()
{
	if (mapRooms[6].getIsCompleted() == true) //Complete task in Electrical room to turn power on
	{
		cout << "Power is ";
		cout << green << "online." << endl << endl;
		settextcolor(yellow);
		return true;
	}
	else
	{
		cout << "Power is off, find correct room to turn online." << endl << endl;
		return false;
	}
}
void displayRoomMessage(int id) //Displays message when room is not complete. Cases correspond to room IDs.
{
	switch (id)
	{
	case(0):
	{
		if (isShipPowered() == false)
			cout << "Room does not have power, find the correct room to turn on power." << endl << endl;
		else
			cout << endl;
		break;
	}
	case(1):
	{
		if (isShipPowered() == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
			changeRooms(Medical); //if locked change rooms
		}
		if (isShipPowered() == true)
		{
			cout << "It seems like someone has broken into the medical supplies" << endl << endl;
		}
		else
		{

		}
		break;
	}
	case(2):
	{
		/*cout << "Communication throughout the ship and any external communication seems to be down." << endl;
		cout << "You notice that the main transmitter is destroyed. Fixing communications could" << endl;
		cout << "allow you to get in touch with your team at home and tell them about the situation." << endl << endl;*/
		break;
	}
	case(3):
	{
		/*cout << "The kitchen knives are missing and the room is a mess. Food is all over the floor, " << endl;
		cout << "cabinets have been left open. Seems like someone was really hungry." << endl << endl;*/
		break;
	}
	case(4):
	{
		if (isShipPowered() == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
			changeRooms(RightEngine);
		}
		else if (player1.searchInventory("Wrench") == false)
		{
			cout << "You need a specific tool to be able to complete this task." << endl << endl;
			getRoomActions(mapRooms[player1.getcurrentRoom()]);
		}
		//else
		//{
		//	/*cout << "The ship" << "\'" << "s fuel levels are low, you need to refill the ship" << "\'" << "s fuel" << endl;
		//	cout << "You see a fuel container next to the fuel tank." << endl << endl;*/
		//}
		break;
	}
	case(5):
	{
		if (player1.searchInventory("Wrench") == false)
		{
			cout << "You need a specific tool to be able to complete this task." << endl << endl;
			getRoomActions(mapRooms[player1.getcurrentRoom()]);
		}
		else
		{
			/*cout << "You notice a leak in the engine and the fuel levels dropping. Complete the task at hand to fix the leak." << endl << endl;*/
		}
		break;
	}
	case(6):
	{
		/*cout << "The power is off throughout most of the ship, the only thing keeping the " << endl;
		cout << "systems online right now is the backup generator. The power box has the wires ripped out " << endl;
		cout <<	"you need to find some way to connect the wires again and get the power back online. " << endl << endl;*/
		cout << "Complete the following task correctly to turn power online: " << endl;
		break;
	}
	case(7):
	{
		/*cout << "You have entered the cell where you expect to find the alien you and your crew have " << endl;
		cout << "captured and are transporting back home. Unfortunately you notice that the cell has " << endl;
		cout << "been opened by force and the alien captive is missing." << endl << endl;*/
		break;
	}
	case(8):
	{
		if (isShipPowered() == false)
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
		/*cout << "There isn" << "\'" << "t much in the lounge except some couches and playing cards from the day before." << endl << endl;*/
		break;
	}
	case(10):
	{
		if (isShipPowered() == false)
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
		if (isShipPowered() == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
			changeRooms(Bathroom);
		}
		else
		{
			//cout << "The shower is running and the mirror is broken. You see the word HELP written on the wall in what seems to be blood." << endl;
		}
		break;
	}
	case(12):
	{
		if (isShipPowered() == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
			changeRooms(Weapons);
		}
		else
		{
			/*cout << "There is a container with one gun in it for emergencies. " << endl;
			cout << "(Power needs to be restored from the electrical room in order to open this container)" << endl << endl;*/
		}
		break;
	}
	case(13):
	{
		if (isShipPowered() == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
			changeRooms(Navigation);
		}
		else
		{
			/*cout << "You find the pilot murdered in their chair and the command console is flashing red with " << endl;
			cout << "the word " << "\"" << "WARNING!" << "\" " << "on the screen. Here you can check the console for progress on completed " << endl;
			cout << "repairs you have made to the ship. " << "\"" << "Check Console" << "\"" << " to check progress of repaired systems. " << endl;
			cout << "x amount of systems are online out of x." << endl << endl;*/
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
void difficultLevel() //User picks the difficulty level
{
	consolecol();
	settextcolor(yellow);
	cout << "Please choose 1-3 for difficulty level:" << endl << endl;
	cout << "1. Amatuer Explorer (40 turns)" << endl;
	cout << "2. Skilled Adventurer (25 turns)" << endl;
	cout << "3. Veteran Pioneer (15 turns)" << endl;

	int difficultyChoice = input(3);

	switch (difficultyChoice)
	{
	case(1):
	{
		maxTurnCount = 40;
		imposterReleaseTurn = 10;
		break;
	}
	case(2):
	{
		maxTurnCount = 25;
		imposterReleaseTurn = 5;
		break;
	}
	case(3):
	{
		maxTurnCount = 15;
		imposterReleaseTurn = 1;
		break;
	}
	}
	system("CLS"); //Clears the console
}
void playGame()
{
	//Resets everything before selecting difficulty
	turnCount = 0;
	randomCode = Start.noteCode();
	randomCodeString = to_string(randomCode);

	player1.resetPlayer(playerHP, 0);

	for (int i = 0; i < 14; i++)
	{
		mapRooms[i].resetRoom();
	}

	difficultLevel();
	settextcolor(yellow);
	cout << "You have just woken up on a spaceship that is part of a space bounty expedition" << endl;
	cout << "to capture a most wanted alien and the ship is quickly spiraling out of control towards Earth." << endl;
	cout << "You realize your crewmates are missing, the power is out and the ships gadgets" << endl;
	cout << "seem to have been tampered with. You also realize there is a hole in the ship" << endl;
	cout << "and your oxygen is dropping quickly. Your mission is to find your crew, " << endl;
	cout << "repair the ship by fixing parts in each room so you can return home safely, and ultimately SURVIVE!" << endl << endl;
	Sleep(3000); //Gives user time to read script

	system("CLS"); //Clears the console
	//currentRoom = Start; //Sets the room that the player is in

	enterRoomMessage(mapRooms[player1.getcurrentRoom()]);

}
int main()
{
	playGame();
	return 0;
}
void enterRoomMessage(Room newRoom)		//Message that plays when room is entered
{
	cout << yellow << "You have entered the ";
	cout << blue << newRoom.getRoomName() << "." << endl << endl; //Room names in blue
	settextcolor(yellow);

	if (imposter.getCurrentRoomID() == newRoom.getRoomID() && turnCount > imposterReleaseTurn)	//Checks if imposter is in the same room
	{
		imposterEncounter();
	}

	if (imposter.getCurrentRoomID() == 6 && mapRooms[6].getIsCompleted())	//Imposter turns off the power if he goes into the electrical room
	{
		cout << "It seems like the power tripped again. You may have to go back and fix it to proceed." << endl << endl;
		mapRooms[6].completeRoom(false);
	}

	cout << "Turns until nuclear meltdown: " << maxTurnCount - turnCount << endl << endl;
	getRoomActions(newRoom);
}
void changeRooms(Room oldRoom)		//Test for changing rooms
{
	int choice;
	int adjacentIDArray[MAXADJACENTROOMS];	//Array that holds the ids of adjacent rooms

	cout << "You can enter the following rooms:" << endl << endl;

	int roomCount = 1;
	for (int i = 0; i < mapRooms[player1.getcurrentRoom()].getNumOfAdjacentRooms(); i++)
	{
		int tempAdjacentID = mapRooms[player1.getcurrentRoom()].getAdjacentRooms(i);
		cout << i + 1 << ": " << mapRooms[tempAdjacentID].getRoomName() << endl;
		adjacentIDArray[i] = mapRooms[player1.getcurrentRoom()].getAdjacentRooms(i);
	}

	//Input Validation
	choice = input(mapRooms[player1.getcurrentRoom()].getNumOfAdjacentRooms());

	system("CLS"); //Clears the console

	player1.setCurrentRoom(mapRooms[adjacentIDArray[choice - 1]].getRoomID());	//Sets the new current room to the chosen value

	if (turnCount > imposterReleaseTurn)	//Imposter starts moving after imposter release turn
	{
		imposter.moveRooms(rand() % 13 + 1);	//Imposter changes rooms when player does (TO DO: Change formula for the rooms it picks)
	}

	turnCounter();

	enterRoomMessage(mapRooms[player1.getcurrentRoom()]);
}
void getRoomActions(Room newRoom)
{
	if (turnCount == imposterReleaseTurn)	//Mentions imposter release. Make Red Text
	{
		if (player1.getcurrentRoom() == 7)	//If player is in the jail on the turn the imposter breaks out
		{
			cout << "You look around the room for a bit until you notice that one of the cells has been breached." << endl;
			cout << "What happened here, and are you really safe ?" << endl << endl;
			imposterEncounter();
		}
		else
		{
			cout << "You hear movement coming from the other side of the ship. Is someone else on board with you..." << endl << endl;
		}
	}
	settextcolor(yellow);
	cout << "What would you like to do in the " << blue << newRoom.getRoomName() << yellow << "?" << endl << endl;
	cout << "1. Complete Task" << endl;
	cout << "2. Investigate" << endl;
	cout << "3. Leave" << endl;
	cout << "4. Inventory" << endl;
	cout << "5. Map" << endl;
	cout << "6. Help" << endl;
	cout << "7. Quit" << endl;
	cout << "8. Restart" << endl;
	settextcolor(yellow);
	//Input Validation
	int actionChoice = input(8);
	system("CLS"); //Clears the console

	switch (actionChoice)
	{
	case(1):
	{
		//Displays room message if room is not completed
		if (mapRooms[player1.getcurrentRoom()].getIsCompleted() == false)
		{
			displayRoomMessage(player1.getcurrentRoom());

			//Displays room question based on questionArray
			questionArray[mapRooms[player1.getcurrentRoom()].getRoomQuestion()].display();

			//Input Validation
			int questionChoice = input(4);
			system("CLS"); //Clears the console

			if (questionArray[mapRooms[player1.getcurrentRoom()].getRoomQuestion()].isCorrectAnswer(questionChoice))
			{
				mapRooms[player1.getcurrentRoom()].completeRoom(true);
				cout << "You have completed everything in this room." << endl << endl;

			}
			else
			{
				player1.takeDamage(10);		//Player Takes damage if answer is wrong
				playerDeath();	//Plays a death message
				cout << "Current Oxygen: " << green << player1.getCurrentHP() << yellow << " / " << player1.getMaxHP() << endl << endl;
			}
		}
		else
		{
			cout << "There is nothing else for you to do in this room." << endl;
			cout << endl;
		}
		player1.setCurrentRoom(newRoom.getRoomID());
		getRoomActions(mapRooms[player1.getcurrentRoom()]);
		break;
	}
	case(2):
	{
		investigate(player1.getcurrentRoom());
		getRoomActions(mapRooms[player1.getcurrentRoom()]);
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
		getRoomActions(mapRooms[player1.getcurrentRoom()]);
		break;
	}
	case(5):
	{
		map();
		getRoomActions(mapRooms[player1.getcurrentRoom()]);
		break;
	}
	case(6):
	{
		help();
		getRoomActions(mapRooms[player1.getcurrentRoom()]);
		break;
	}
	case(7):
	{
		quit();
		break;
	}
	case(8):
	{
		restart();
		break;
	}
	}
}
void help()
{
	cout << "Choose a room to navigate to from the displayed map / room list" << endl;
	cout << "Each room will have a description when you go into the room with a minigame to fix gadgets or objects you can pick up (Air tank, weapon, tools, paper with a code on it for another minigame they may have to remember.)" << endl;
	cout << "To win the game, you must repair all gadgetsand get the weapon before the killer" << endl;
	cout << "Failing at a minigame too many times, lowers total air supply which can kill you.You are able to replenish your air supply by picking up air tanks around the map." << endl;
	cout << "Be careful because if the Killer gets to you or you run out of time trying to repair the ship, YOU WILL LOSE" << endl;
}
void map()
{
	settextcolor(dark_purple);
	cout << "  ----------" << blue << "Navigation" << dark_purple << "-------------" << blue << "Weapons" << dark_purple << endl;
	cout << "  |                                 |" << endl;
	cout << "  | " << blue << "MedBay" << dark_purple << "------|                " << blue << "Bathroom" << dark_purple << endl;
	cout << "  |  |          |---" << blue << "Communication" << dark_purple << "    |" << endl;
	cout << blue << "Storage" << dark_purple << "         |                    |" << endl;
	cout << "  |             |                    |" << endl;
	cout << blue << "LEngine" << dark_purple << "-------" << blue << "Bedroom" << dark_purple << "-------------" << blue << "REngine" << dark_purple << endl;
	cout << "  |            |              " << endl;
	cout << "  |     -----" << blue << "Kitchen" << dark_purple << "----------      " << endl;
	cout << "  |     |                    |     " << endl;
	cout << "  |  " << blue << "Electric              Lounge    " << dark_purple << endl;
	cout << "  |     |                    |     " << endl;
	cout << blue << " Jail" << dark_purple << "---|                  " << blue << "Hanger     " << dark_purple << endl;
	cout << "  |__________________________|     " << endl;
	settextcolor(yellow);
}
void escape()
{
	if (mapRooms[8].getIsCompleted() == true && player1.searchInventory("Key Card") == true)
	{
		int code;
		cout << "The escape pod is " << green << "online!" << yellow << " Please enter 4 digit code to enter pod: " << endl;
		cin >> code;

		system("CLS"); //Clears the console

		if (code == randomCode)
		{
			cout << green << "Access Granted!" << endl << endl;
			cout << "Congratulations! You have succesfully escaped the ship and are safely headed back to Earth!" << endl << endl;
			settextcolor(yellow);
			gameOver();
		}
		else
		{
			cout << "Access Denied" << endl << endl;
			cout << "Maybe the code can found in one of the rooms" << endl;
			getRoomActions(mapRooms[player1.getcurrentRoom()]);
		}
	}
	else
	{
		cout << "You found an escape pod. You need to complete the task and have the keycard to activate the Pod" << endl;
		getRoomActions(mapRooms[player1.getcurrentRoom()]);
	}
}
void rightEngineComplete()
{
	if (mapRooms[4].getIsCompleted() == true)
	{
		cout << "You have repaired the Right engine and the fuel levels are stabilizing" << endl << endl;
	}
	else
	{
		cout << "You notice a leak in the Right engine and the fuel levels dropping." << endl;
		cout << "You need to repair the engine." << endl << endl;
		getRoomActions(mapRooms[player1.getcurrentRoom()]);
	}

}
void leftEngineComplete()
{
	if (mapRooms[5].getIsCompleted() == true)
	{
		cout << "You have repaired the Left engine and the fuel levels are stabilizing" << endl << endl;
	}
	else
	{
		cout << "You notice a leak in the Left engine and the fuel levels dropping." << endl;
		cout << "You need to repair the engine." << endl << endl;
		getRoomActions(mapRooms[player1.getcurrentRoom()]);
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
			cout << "There are several empty beds with footlockers nearby." << endl;
			cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", you have found a ";
			cout << green << "Flashlight" << endl << endl;
			settextcolor(yellow);
			player1.addToInventory("Flashlight");
		}
		else
		{
			cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", there is nothing to be found here." << endl << endl;
		}
		break;
	}
	case(1)://Medical
	{
		if (isShipPowered() == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
		}
		else
		{
			if (!player1.getCollectedOxygenTank(id))
			{
				cout << "It seems like someone has broken into the medical supplies" << endl << endl;
				cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", you have found a ";
				cout << green << "Oxygen Tank" << endl;
				settextcolor(yellow);
				player1.increaseMaxHP(20);
				player1.healDamage(20);
				player1.setCollectedOxygenTanks(id);
			}
			else
			{
				cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", there is nothing to be found here." << endl << endl;
			}
		}
		break;
	}
	case(2)://Communications
	{
		if (isShipPowered() == false)
		{
			if (player1.searchInventory("Flashlight"))
			{
				cout << "Room is too dark, you turned on your Flashlight" << endl << endl;
				cout << "Communication throughout the ship and any external communication seems to be down." << endl;
				cout << "You notice that the main transmitter is destroyed. Fixing communications could" << endl;
				cout << "allow you to get in touch with your team at home and tell them about the situation." << endl << endl;
				cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", there is nothing to be found here." << endl << endl;
				cout << "Room is too dark, you turned on your Flashlight" << endl;
			}
			else
			{
				cout << "It is too dark to see anything please turn on power first." << endl << endl;
			}
		}
		else
		{
			cout << "Communication throughout the ship and any external communication seems to be down." << endl;
			cout << "You notice that the main transmitter is destroyed. Fixing communications could" << endl;
			cout << "allow you to get in touch with your team at home and tell them about the situation." << endl << endl;
			cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", there is nothing to be found here." << endl << endl;
		}
		break;
	}
	case(3)://Kitchen
	{   if (isShipPowered() == false)
	{
		if (player1.searchInventory("Flashlight"))
		{
			if (!player1.searchInventory("Note: " + randomCodeString))
			{
				cout << "Room is too dark, you turned on your Flashlight" << endl;
				cout << "The kitchen knives are missing and the room is a mess. Food is all over the floor, " << endl;
				cout << "cabinets have been left open. Seems like someone was really hungry." << endl << endl;
				cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", you have found a ";
				cout << green << "Note." << endl;
				settextcolor(yellow);
				cout << "The note says IN CASE OF EMERGENCY ";
				cout << green << randomCode;
				settextcolor(yellow);
				cout << " ... the rest of the note is not legible." << endl << endl;
				player1.addToInventory("Note: " + randomCodeString);
			}
			else
			{
				cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", there is nothing to be found here." << endl << endl;
			}
		}
		else
		{
			cout << "It is too dark to see anything please turn on power first." << endl << endl;
		}
	}
	else
	{
		if (!player1.searchInventory("Note: " + randomCodeString))
		{
			cout << "The kitchen knives are missing and the room is a mess. Food is all over the floor, " << endl;
			cout << "cabinets have been left open. Seems like someone was really hungry." << endl << endl;
			cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", you have found a ";
			cout << green << "Note." << endl;
			settextcolor(yellow);
			cout << "The note says IN CASE OF EMERGENCY ";
			cout << green << randomCode;
			settextcolor(yellow);
			cout << " ... the rest of the note is not legible." << endl << endl;
			cout << "The note says IN CASE OF EMERGENCY " << randomCode << " ... the rest of the note is not legible." << endl << endl;
			player1.addToInventory("Note");
		}
		else
		{
			cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", there is nothing to be found here." << endl << endl;
		}
	}
	break;
	}
	case(4)://R Engine
	{
		if (isShipPowered() == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
		}
		else
		{
			cout << "The ship" << "\'" << "s fuel levels are low, you need to refill the ship" << "\'" << "s fuel" << endl;
			cout << "You see a fuel container next to the fuel tank." << endl << endl;
			rightEngineComplete();
		}
		break;
	}
	case(5)://L Engine
	{
		if (isShipPowered() == false)
		{
			if (player1.searchInventory("Flashlight"))
			{
				cout << "Room is too dark, you turned on your Flashlight" << endl << endl;
				cout << "You notice a leak in the engine and the fuel levels dropping. Complete the task at hand to fix the leak." << endl << endl;
				leftEngineComplete();
			}
			else
			{
				cout << "It is too dark to see anything please turn on power first." << endl << endl;
			}
		}
		else
		{
			cout << "You notice a leak in the engine and the fuel levels dropping. Complete the task at hand to fix the leak." << endl << endl;
			leftEngineComplete();
		}
		break;
	}
	case(6)://Electircal
	{
		if (isShipPowered() == false)
		{
			if (player1.searchInventory("Flashlight"))
			{
				cout << "Room is too dark, you turned on your Flashlight" << endl;
				cout << "The power is off throughout most of the ship, the only thing keeping the " << endl;
				cout << "systems online right now is the backup generator. The power box has the wires ripped out " << endl;
				cout << "you need to find some way to connect the wires again and get the power back online. " << endl << endl;
				cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", there is nothing to be found here." << endl << endl;
			}
			else
			{
				cout << "It is too dark to see anything please turn on power first." << endl << endl;
			}
		}
		else
		{
			cout << "The power box is connected to the backup generator via the spare wires you have found laying around the room." << endl;
			cout << "It appears that the wires were ripped out intentionally, ";
			cout << red << "BE CAREFUL!" << endl;
			settextcolor(yellow);
			cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", there is nothing to be found here." << endl << endl;
		}
		break;
	}
	case(7)://Jail
	{
		if (isShipPowered() == false)
		{
			if (player1.searchInventory("Flashlight"))
			{
				cout << "Room is too dark, you turned on your Flashlight" << endl;
				cout << "You have entered the cell where you expect to find the alien you and your crew have " << endl;
				cout << "captured and are transporting back home. Unfortunately you notice that the cell has " << endl;
				cout << "been opened by force and the alien captive is missing." << endl << endl;
				cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", there is nothing to be found here." << endl << endl;
			}
			else
			{
				cout << "It is too dark to see anything please turn on power first." << endl << endl;
			}
		}
		else
		{
			cout << "You have entered the cell where you expect to find the alien you and your crew have " << endl;
			cout << "captured and are transporting back home. Unfortunately you notice that the cell has " << endl;
			cout << "been opened by force and the alien captive is missing." << endl << endl;
			cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", there is nothing to be found here." << endl << endl;
		}
		break;
	}
	case(8)://Hanger
	{
		if (isShipPowered() == false)
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
		if (isShipPowered() == false)
		{
			if (player1.searchInventory("Flashlight"))
			{
				if (!player1.getCollectedOxygenTank(id))
				{
					cout << "There isn" << "\'" << "t much in the lounge except some couches and playing cards from the day before." << endl << endl;
					cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", you have found a ";
					cout << green << "Oxygen Tank" << endl;
					settextcolor(yellow);
					player1.increaseMaxHP(20);
					player1.healDamage(20);
					player1.setCollectedOxygenTanks(id);
				}
				else
				{
					cout << "There isn" << "\'" << "t much in the lounge except some couches and playing cards from the day before." << endl << endl;
					cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", there is nothing to be found here." << endl << endl;
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
				cout << "There isn" << "\'" << "t much in the lounge except some couches and playing cards from the day before." << endl << endl;
				cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", you have found a ";
				cout << green << "Oxygen Tank" << endl;
				settextcolor(yellow);
				player1.increaseMaxHP(20);
				player1.healDamage(20);
				player1.setCollectedOxygenTanks(id);
			}
			else
			{
				cout << "There isn" << "\'" << "t much in the lounge except some couches and playing cards from the day before." << endl << endl;
				cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", there is nothing to be found here." << endl << endl;
			}
		}
		break;
	}
	case(10)://Storage
	{
		if (isShipPowered() == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
		}
		else
		{
			if (!player1.searchInventory("Wrench"))
			{
				cout << "There appears to be cleaning supplies, and a toolbox." << endl;
				cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", you have found a ";
				cout << green << "Wrench" << endl << endl;
				settextcolor(yellow);
				player1.addToInventory("Wrench");
			}
			else
			{
				cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", there is nothing to be found here." << endl << endl;
			}
		}
		break;
	}
	case(11)://Bathroom
	{
		if (isShipPowered() == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
		}
		else
		{
			cout << "The shower is running and the mirror is broken. You see the word ";
			cout << red << "HELP ";
			settextcolor(yellow);
			cout << "written on the wall in what seems to be blood." << endl << endl;
			cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", there is nothing to be found here." << endl << endl;
		}
		break;
	}
	case(12)://Weapons
	{
		if (isShipPowered() == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
		}
		else
		{
			if (!player1.searchInventory("Weapon"))
			{
				cout << "There is a container with a gun in it for emergencies. " << endl;
				//cout << "(Power needs to be restored from the electrical room in order to open this container)" << endl << endl;
				cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", you have found a ";
				cout << green << "Weapon" << endl << endl;
				settextcolor(yellow);
				player1.addToInventory("Weapon");
			}
			else
			{
				cout << "There is an empty container from where you retrieved your gun." << endl;
				cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", there is nothing to be found here." << endl << endl;
			}
		}
		break;
	}
	case(13)://Navigation
	{
		if (isShipPowered() == false)
		{
			cout << "Room is locked, turn on power to unlock room." << endl << endl;
		}
		else
		{
			if (!player1.searchInventory("Key Card"))
			{
				cout << "You find the pilot murdered in their chair and the command console is flashing red with " << endl;
				cout << "the word " << "\"" << red << "WARNING!" << yellow << "\" " << "on the screen. Here you can check the console for progress on completed " << endl;
				cout << "repairs you have made to the ship. It appears you have made progress on repairing vital components of the ship." << endl;
				cout << roomsCompleted() << " of the systems are online out of 13." << endl << endl;
				cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", you have found a ";
				cout << green << "Key-card" << endl << endl;
				player1.addToInventory("Key Card");
			}
			else
			{
				cout << "You find the pilot murdered in their chair and the command console is flashing red with " << endl;
				cout << "the word " << "\"" << red << "WARNING!" << yellow << "\" " << "on the screen. Here you can check the console for progress on completed " << endl;
				cout << "repairs you have made to the ship. It appears you have made progress on repairing vital components of the ship." << endl;
				cout << roomsCompleted() << " of the systems are online out of 13." << endl << endl;
				cout << "After carefully investigating " << mapRooms[player1.getcurrentRoom()].getRoomName() << ", there is nothing to be found here." << endl << endl;
			}
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
void turnCounter()
{
	turnCount++;
	if (turnCount == maxTurnCount)
	{
		cout << red << "You have run out of time, Nuclear Meltdown in progess!" << endl << endl;
		settextcolor(yellow);
		gameOver();
	}
}
void gameOver()
{
	cout << red << "Game Over" << endl << endl;
	settextcolor(yellow);
	cout << "Would you like to play again? Select 1 or 2" << endl; //Still not complete needs restart and end game function
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	int playAgainChoice = input(2);
	system("CLS"); //Clears the console
	switch (playAgainChoice)
	{
	case(1):
	{
		playGame();
	}
	case(2):
	{
		exit(0);
	}
	}
}
void quit()
{
	cout << red << "You are about to quit the game" << endl << endl;
	settextcolor(yellow);
	cout << "Are you sure you want to quit?" << endl; //Still not complete needs restart and end game function
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	int playAgainChoice = input(2);
	system("CLS"); //Clears the console
	switch (playAgainChoice)
	{
	case(1):
	{
		exit(0);
	}
	case(2):
	{
		getRoomActions(mapRooms[player1.getcurrentRoom()]);
	}
	}
}
void restart()
{
	cout << purple << "You are about to restart the game" << endl << endl;
	settextcolor(yellow);
	cout << "Are you sure you want to restart?" << endl; //Still not complete needs restart and end game function
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	int playAgainChoice = input(2);
	system("CLS"); //Clears the console
	switch (playAgainChoice)
	{
	case(1):
	{
		playGame();
	}
	case(2):
	{
		getRoomActions(mapRooms[player1.getcurrentRoom()]);
	}
	}
}
void playerDeath()	//Plays a death message
{
	if (!player1.getIsAlive())
	{
		cout << endl;
		cout << red << "You have died!" << endl << endl;	//Make more descriptive later
		settextcolor(white);
		gameOver();
	}
	else
	{
	}
}
void imposterEncounter()
{
	cout << "You feel another presence near you..." << endl;
	cout << "You're being attacked!" << endl << endl;

	int RPSResult = startRPS();	//0=tie, 1=loss, 2=win


	while (RPSResult != 2)	//Checks if player has not won RPS. Imposter keeps attacking until the player wins
	{
		if (RPSResult == 1)	//Checks if RPS was lost. Take damage on loss. Continue playing on tie
		{
			player1.takeDamage(10);
			playerDeath();
			cout << "Current Oxygen: " << green << player1.getCurrentHP() << yellow << " / " << player1.getMaxHP() << endl << endl;
		}

		RPSResult = startRPS();
	}
	cout << "Phew... The attacker fled. It looks like you made it out of there alive somehow." << endl;
	cout << "Let's continue exploring." << endl << endl;;
}

#include <iostream>
using namespace std;
void Help();

int main()
{
	int helpDisplay = 911;
	int userInput;
	cout << "Enter '911' if you need help!" << endl;
	cin >> userInput;

	if (userInput == helpDisplay)
	{
		Help();
	}
	else
	{
		cout << "Invalid Input!" << endl;
	}
	system("pause");
	return 0;
}

void Help()
{
	cout << "Choose a room to navigate to from the displayed map / room list" << endl;
	cout << "Each room will have a description when you go into the room with a minigame to fix gadgets or objects you can pick up(Air tank, weapon, tools, paper with a code on it for another minigame they may have to remember.)" << endl;
	cout << "To win the game, you must repair all gadgetsand get the weapon before the killer" << endl;
	cout << "Failing at a minigame too many times, lowers total air supply which can kill you.You are able to replenish your air supply by picking up air tanks around the map." << endl;
	cout << "Be careful because if the Killer gets to you or you run out of time trying to repair the ship, YOU WILL LOSE" << endl;
}
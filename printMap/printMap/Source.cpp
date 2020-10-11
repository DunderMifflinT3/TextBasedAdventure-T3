#include <iostream>
using namespace std;
void map();

int main()
{
	int mapDisplay = 999;
	int userInput;
	cout << "Enter '999' to show map" << endl;
	cin >> userInput;

	if (userInput == mapDisplay)
	{
		map();
	}
	else
	{
		cout << "Invalid Input!" << endl;
	}
	system("pause");
	return 0;
}

void map()
{
	cout << "  ----------Navigation-------------Weapons" << endl;
	cout << "  |             |                    |" << endl;
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
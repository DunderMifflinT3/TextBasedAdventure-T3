#include "Questions.h"
#include "StartRoom.h"
#include "CommRoom.h"
#include "Kitchen.h"
#include "Medbay.h"
#include "RightEngineRoom.h"
using namespace std;

int main()
{
	double version = 1.2;

	//makes the starting room
	StartRoom Room;
	Room.startMsg();
	Room.roomInfo();
	Room.startRoom();
	
	system("pause");
	return 0;
}
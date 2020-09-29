#include "StartRoom.h"
#include "Questions.h"
#include "Medbay.h"
#include "CommRoom.h"
#include "Kitchen.h"
#include "RightEngineRoom.h"
using namespace std;

int main()
{
	int version = 1.1;
	string ans;

	StartRoom Room;
	Room.startMsg();
	Room.roomInfo();

	Question First;
	First.getQuestion();
	First.getAnswer();
	First.displayQuestion();
	cin >> ans;
	First.correctAnswer(ans);

	//Needs function to move rooms

	system("pause");
	return 0;
	
}
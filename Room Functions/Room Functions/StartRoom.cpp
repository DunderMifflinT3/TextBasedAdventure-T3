#include "StartRoom.h"
#include "Questions.h"

int main()
{
	int version = 1;
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
	
	system("pause");
	return 0;
}
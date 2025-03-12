#include <iostream>
#include "SpeechCompetition.h"

using namespace std;

int main()
{
	SpeechCompetition sp;

	int select = 0;

	while (true)
	{
		sp.showMenu();
		cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ£º" << endl;
		cin >> select;

		switch (select)
		{
		case 1:
			sp.startCompetition();
			break;
		case 2:
			sp.showRecord();
			break;
		case 3:
			sp.clearRecorg();
			break;
		case 0:
			sp.exitProgrammer();
			break;
		default:
			system("cls");
			break;
		}
	}

	return 0;
}
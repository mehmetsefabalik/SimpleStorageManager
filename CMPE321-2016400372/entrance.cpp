#include "entrance.h"

Entrance *Entrance::instance = NULL;

Entrance::Entrance() 
{

}

Entrance *Entrance::getInstance()
{
	if (!instance)
		instance = new Entrance();
	return instance;
}

void Entrance::console()
{
	int selected;
	do {
		cout << "Storage Manager" << endl;
		cout << "0- Exit" << endl;
		cout << "1- DML Operations" << endl;
		cout << "2- DDL Operations" << endl;
		cin >> selected;

		system("cls");

		if (selected == 0) {
			return;
		}
		else if (selected == 1) {

			break;
		}
		else if (selected == 2) {
			
			break;
		}
		else {
			break;
		}

	} while (1);
}


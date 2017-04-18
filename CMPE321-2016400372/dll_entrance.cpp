#include "dll_entrance.h"

using namespace std;

DdlEntrance *DdlEntrance::instance = NULL;

DdlEntrance::DdlEntrance() {

}

DdlEntrance *DdlEntrance::getInstance() {
	if (!instance)
		instance = new DdlEntrance();
	return instance;
}

void DdlEntrance::console() {
	int selected;
	do {
		cout << "DDL OPERATIONS" << endl;
		cout << "0- Previous Menu" << endl;
		cout << "1- Create a type" << endl;
		cout << "2- Delete a type" << endl;
		cout << "3- List all types" << endl;
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
		else if (selected == 3) {
			
			break;
		}
		else {
			break;
		}

	} while (1);
}
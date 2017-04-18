#include "dml_entrance.h"

using namespace std;

DmlEntrance *DmlEntrance::instance = NULL;

DmlEntrance::DmlEntrance() {

}

DmlEntrance *DmlEntrance::getInstance() {
	if (!instance)
		instance = new DmlEntrance();
	return instance;
}

void DmlEntrance::console() {
	int selected;
	do {
		cout << "DDL OPERATIONS" << endl;
		cout << "0- Previous Menu" << endl;
		cout << "1- Create a record" << endl;
		cout << "2- Delete a record" << endl;
		cout << "3- Update a record" << endl;
		cout << "4- Search for a record by primary key" << endl;
		cout << "5- List all records of a type" << endl;
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
		else if (selected == 4) {

			break;
		}
		else if (selected == 5) {

			break;
		}
		else {
			break;
		}

	} while (1);
}
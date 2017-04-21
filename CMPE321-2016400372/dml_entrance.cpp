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
			Entrance::getInstance()->console();
			return;
		}
		else if (selected == 1) {
			Dml::getInstance()->createRecord();
			break;
		}
		else if (selected == 2) {
			Dml::getInstance()->deleteRecord();
			break;
		}
		else if (selected == 3) {
			Dml::getInstance()->updateRecord();
			break;
		}
		else if (selected == 4) {
			Dml::getInstance()->searchRecord();
			break;
		}
		else if (selected == 5) {
			Dml::getInstance()->listRecords();
			break;
		}
		else {
			break;
		}

	} while (1);
}
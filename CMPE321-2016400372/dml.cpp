#include "dml.h"

using namespace std;

Dml *Dml::instance = NULL;

Dml *Dml::getInstance() {
	if (!instance)
		instance = new Dml();
	return instance;
}

Dml::Dml() {

}

bool Dml::createRecord() {
	char  F1[15], F2[15], F3[15], F4[15], F5[15];
	int selected, NOF;
	Type type;
	cout << "Please select the type: " << endl;
	Ddl::getInstance()->listTypes();
	cin >> selected;
	type = Syscat::getInstance()->get_type((selected - 1) * sizeof(Type));
	NOF = type.getNumberOF();
	for(int i = 1; i <= NOF; i++) {
		switch (i)
		{
		case 1:
			cout << type.getF1() << " = ";
			cin >> F1;
			break;
		case 2:
			cout <<endl<< type.getF2() << " = ";
			cin >> F2;
			break;
		case 3:
			cout <<endl<< type.getF3() << " = ";
			cin >> F3;
			break;
		case 4:
			cout <<endl<< type.getF4() << " = ";
			cin >> F4;
			break;
		case 5:
			cout <<endl<< type.getF5() << " = ";
			cin >> F5;
			break;
		default:
			break;
		}
	}
	fstream syscat;
	char id = '0';
	syscat.open(".\\record2.cat", ios::in | ios::beg);
	if (!syscat.is_open()) {
		syscat.open(".\\record2.cat", ios::out | ios::app);
		syscat.put(0);
		syscat.close();
	}
	else {
		syscat.get(id);
		syscat.close();
	}

	File::reg_rec(Record(type,(int)id,F1,F2,F3,F4,F5));

	return true;
}

bool Dml::deleteRecord() {
	return true;
}

bool Dml::searchRecord() {
	return true;
}

bool Dml::updateRecord() {
	return true;
}

bool Dml::listRecords() {
	return true;
}
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
	syscat.open(".\\page2.dat", ios::in | ios::beg);
	if (!syscat.is_open()) {
		syscat.open(".\\page2.dat", ios::out | ios::app);
		syscat.put(0);
		syscat.close();
		File::reg_page(Record(type, 0, F1, F2, F3, F4, F5));
		goto escape;
	}
	else {
		syscat.get(id);
		syscat.close();
	}

	File::reg_page(Record(type,(int)id,F1,F2,F3,F4,F5));
escape:
	DmlEntrance::getInstance()->console();
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
	Type type;
	Type typeptr1;
	fstream file;
	Page page;
	Record record;
	int selected, nofrecords;
	cout << "What type of records?" << endl << endl;
	Ddl::getInstance()->listTypes();
	cin >> selected;
	type = Syscat::getInstance()->get_type((selected - 1) * sizeof(Type));
	//typeptr = &type;
	char page2num;
	file.open(".\\page2.dat", ios::in | ios::beg);
	file.get(page2num);
	file.close();
	int page2 = ((page2num - '0') + 48);
	//cout << "page2 " << page2;
	if (page2 == 0) {
		cout << "There are no types yet :(";
		return true;
	}
	for (int i = 1; i <= page2; i++) {
		file.open(".\\page.dat", ios::in | ios::binary);
		file.seekg((i - 1) * sizeof(Page));
		file.read((char*)&page, sizeof(Page));
		cout << "----------Reading Page " << page.getId() + 1 << "---------" << endl;
		file.close();
		nofrecords = page.getNor();
		//cout << nofrecords << "page id : " << page.getId();
		for (int j = 1; j <= nofrecords; j++) {
			switch (j)
			{
			case 1:
				record = page.getR1();
				//cout << "1 " << record.getF2() << endl;
				typeptr1 = record.getType();
				//cout << "compare : " << strcmp(typeptr->getName(), typeptr1->getF1());
				if (!strcmp(type.getName(), typeptr1.getName())) {
					cout << endl;
					cout << type.getF1() << " = " << record.getF1() << endl;
					cout << type.getF2() << " = " << record.getF2() << endl;
					cout << type.getF3() << " = " << record.getF3() << endl;
					cout << type.getF4() << " = " << record.getF4() << endl;
					cout << type.getF5() << " = " << record.getF5() << endl;
					cout << endl;
				}
				break;
			case 2:
				record = page.getR2();
				typeptr1 = record.getType();
				//cout << "2 " << record.getF2() << endl;
				if (!strcmp(type.getName(), typeptr1.getName())) {
					cout << endl;
					cout << type.getF1() << " = " << record.getF1() << endl;
					cout << type.getF2() << " = " << record.getF2() << endl;
					cout << type.getF3() << " = " << record.getF3() << endl;
					cout << type.getF4() << " = " << record.getF4() << endl;
					cout << type.getF5() << " = " << record.getF5() << endl;
					cout << endl;
				}
				break;
			case 3:
				record = page.getR3();
				typeptr1 = record.getType();
				//cout << "3 " << record.getF2() << endl;
				if (!strcmp(type.getName(), typeptr1.getName())) {
					cout << endl;
					cout << type.getF1() << " = " << record.getF1() << endl;
					cout << type.getF2() << " = " << record.getF2() << endl;
					cout << type.getF3() << " = " << record.getF3() << endl;
					cout << type.getF4() << " = " << record.getF4() << endl;
					cout << type.getF5() << " = " << record.getF5() << endl;
					cout << endl;
				}
				break;
			case 4:
				record = page.getR4();
				typeptr1 = record.getType();
				if (!strcmp(type.getName(), typeptr1.getName())) {
					cout << endl;
					cout << type.getF1() << " = " << record.getF1() << endl;
					cout << type.getF2() << " = " << record.getF2() << endl;
					cout << type.getF3() << " = " << record.getF3() << endl;
					cout << type.getF4() << " = " << record.getF4() << endl;
					cout << type.getF5() << " = " << record.getF5() << endl;
					cout << endl;
				}
				break;
			case 5:
				record = page.getR5();
				typeptr1 = record.getType();
				if (!strcmp(type.getName(), typeptr1.getName())) {
					cout << endl;
					cout << type.getF1() << " = " << record.getF1() << endl;
					cout << type.getF2() << " = " << record.getF2() << endl;
					cout << type.getF3() << " = " << record.getF3() << endl;
					cout << type.getF4() << " = " << record.getF4() << endl;
					cout << type.getF5() << " = " << record.getF5() << endl;
					cout << endl;
				}
				break;
			default:
				break;
			}
		}
	}
	DmlEntrance::getInstance()->console();

	return true;
}
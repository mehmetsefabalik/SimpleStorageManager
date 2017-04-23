#include "file.h"

using namespace std;

File *File::instance = NULL;

File::File() {

}

File *File::getInstance() {
	if (!instance) {
		instance = new File();
	}
	return instance;
}

bool File::reg_rec(Record record) {
	fstream syscat;
	int tid = record.getId() - 48;
	syscat.open(".\\record.dat", ios::out | ios::binary | ios::app);
	syscat.seekp(tid * sizeof(Type));
	cout << tid * sizeof(Type);
	syscat.write((char *)&record, sizeof(Type));
	syscat.close();
	syscat.open(".\\record2.dat", ios::out | ios::beg | ios::trunc);
	syscat.put((char)(record.getId() + 1));
	syscat.close();
	return true;
}

bool File::reg_page(Record record) {
	fstream file;
	Page page;
	char BUFFER[100000];
	char page2num;
	file.open(".\\page2.dat", ios::in | ios::beg);
	file.get(page2num);
	file.close();
	int page2 = page2num - '0';
	if (page2 == -48) {
		endww:
		Page page1;
		page1.setId(((page2num - '0') + 48));
		page1.setNor(1);
		page1.setR1(record);
		cout << "recordid" << record.getId() << endl;
		cout << "page created" << endl;
		file.open(".\\page.dat", ios::out | ios::binary | ios::app);
		file.write((char *)&page1, sizeof(Page));
		file.close();
		file.open(".\\page2.dat", ios::out | ios::beg | ios::trunc);
		file.put((char)(page1.getId() + 1));
		cout << page1.getId() + 1;
		file.close();
	}
	else {
		cout << page2num - '0';
		//switch (page2num - '0') {
		//case -47:
		//while ((page2num - '0') > -48) {
			Record record1;
			file.open(".\\page.dat", ios::in | ios::binary);
			file.seekg(((page2num - '0') + 47) * sizeof(Page));
			file.read((char *)&page, sizeof(Page));
			file.close();
			//cout << "nor " << page->getNor() << endl;
			switch (page.getNor()) {
			case 1:
				page.setId(((page2num - '0') + 47));
				page.setNor(2);
				page.setR2(record);
				file.open(".\\page.dat", ios::in | ios::binary | ios::beg);
				file.read(BUFFER, ((page2num - '0') + 47)*sizeof(Page));
				file.close();
				file.open(".\\temp.dat", ios::out | ios::binary);
				file.write(BUFFER, ((page2num - '0') + 47)*sizeof(Page));
				file.close();
				file.open(".\\temp.dat", ios::out | ios::binary | ios::app);
				file.write((char *)&page, sizeof(Page));
				remove(".\\page.dat");
				file.close();
				if (rename("temp.dat", "page.dat"))
					cout << "error renaming";
				cout << "nor " << page.getNor() << endl;
				cout << "id" << page.getId() << endl;
				return true;
				break;
			case 2:
				page.setId(((page2num - '0') + 47));
				page.setNor(3);
				page.setR3(record);
				file.open(".\\page.dat", ios::in | ios::binary | ios::beg);
				file.read(BUFFER, ((page2num - '0') + 47) * sizeof(Page));
				file.close();
				file.open(".\\temp.dat", ios::out | ios::binary);
				file.write(BUFFER, ((page2num - '0') + 47)*sizeof(Page));
				file.close();
				file.open(".\\temp.dat", ios::out | ios::binary | ios::app);
				file.write((char *)&page, sizeof(Page));
				remove(".\\page.dat");
				file.close();
				if (rename("temp.dat", "page.dat"))
					cout << "error renaming";
				cout << "nor " << page.getNor() << endl;
				cout << "id" << page.getId() << endl;
				return true;
				break;
			case 3:
				page.setId(((page2num - '0') + 47));
				page.setNor(4);
				page.setR4(record);
				file.open(".\\page.dat", ios::in | ios::binary | ios::beg);
				file.read(BUFFER, ((page2num - '0') + 47) * sizeof(Page));
				file.close();
				file.open(".\\temp.dat", ios::out | ios::binary);
				file.write(BUFFER, ((page2num - '0') + 47)*sizeof(Page));
				file.close();
				file.open(".\\temp.dat", ios::out | ios::binary | ios::app);
				file.write((char *)&page, sizeof(Page));
				remove(".\\page.dat");
				file.close();
				if (rename("temp.dat", "page.dat"))
					cout << "error renaming";
				cout << "nor " << page.getNor() << endl;
				cout << "id" << page.getId() << endl;
				return true;
				break;
			case 4:
				page.setId(((page2num - '0') + 47));
				page.setNor(5);
				page.setR5(record);
				file.open(".\\page.dat", ios::in | ios::binary | ios::beg);
				file.read(BUFFER, ((page2num - '0') + 47) * sizeof(Page));
				file.close();
				file.open(".\\temp.dat", ios::out | ios::binary);
				file.write(BUFFER, ((page2num - '0') + 47)*sizeof(Page));
				file.close();
				file.open(".\\temp.dat", ios::out | ios::binary | ios::app);
				file.write((char *)&page, sizeof(Page));
				remove(".\\page.dat");
				file.close();
				if (rename("temp.dat", "page.dat"))
					cout << "error renaming";
				cout << "nor " << page.getNor() << endl;
				cout << "id" << page.getId() << endl;
				return true;
				break;
			case 5:
				goto endww;
			}
			/*record1 = page->getR1();
			cout << "record1 " << record1->getId();
			Type* type = record1->getType();
			cout << "type " << type->getName();*/

			file.close();
		}

	
	//}

		
	
	
	return true;
}

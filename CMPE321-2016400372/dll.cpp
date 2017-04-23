#include "dll.h"

using namespace std;

Ddl *Ddl::instance = NULL;

Ddl *Ddl::getInstance() {
	if (!instance)
		instance = new Ddl();
	return instance;
}

Ddl::Ddl() {

}

bool Ddl::createType() {

	char F[15];

	cout << "Please write type name: " << endl;
	cin >> typeName;
	system("cls");
beginfor:
	for (int i = 1; i < 6; i++) {
		
		cout << endl << "Please write field " << i << " of type " << typeName << endl;
		cin >> F;

		switch(F[0]){
			case 'q':
			switch (i) {
				case 1:
					cout << "you should provide at least 1 field!"<< endl;
					goto beginfor;
				case 2:
					strcpy_s(F2, F);
					strcpy_s(F3, F);
					strcpy_s(F4, F);
					strcpy_s(F5, F);
					NOF = 1;
					break;
				case 3:
					strcpy_s(F3, F);
					strcpy_s(F4, F);
					strcpy_s(F5, F);
					NOF = 2;
					break;
				case 4:
					strcpy_s(F4, F);
					strcpy_s(F5, F);
					NOF = 3;
					break;
				case 5:
					strcpy_s(F5, F);
					NOF = 4;
					break;
				}

				goto endfor;
				default:

					switch (i)
					{
					case 1:
						strcpy_s(F1, F);
						NOF = 1;
						break;
					case 2:
						strcpy_s(F2, F);
						NOF = 2;
						break;
					case 3:
						strcpy_s(F3, F);
						NOF = 3;
						break;
					case 4:
						strcpy_s(F4, F);
						NOF = 4;
						break;
					case 5:
						strcpy_s(F5, F);
						NOF = 5;
						break;

					default:
						break;
					}
	
			}
}
endfor:

	fstream syscat;
	char id = '0';
	syscat.open(".\\sys2.cat", ios::in | ios::beg);
	if (!syscat.is_open()) {
		syscat.open(".\\sys2.cat", ios::out | ios::app);
		syscat.put(0);
		syscat.close();
	}
	else {
		syscat.get(id);
		syscat.close();
	}

	Syscat::reg_type(Type((int) id, typeName, NOF, F1, F2, F3, F4, F5));
	
	return true;
}

bool Ddl::deleteType() {
	Type type;
	fstream file;
	int selected;
	char max;
	file.open(".\\sys2.cat", ios::in | ios::beg);
	file.get(max);
	file.close();
	file.open(".\\sys.cat", ios::in | ios::binary);
	
	int i = 0;
	cout << "Please type the index of type to be deleted: " << endl;
	int maxint = max - '0';
	for (int position = 0; position < maxint*(int)sizeof(Type); position += sizeof(Type)) {
		i++;
		file.seekg(position);
		file.read((char *)&type, sizeof(Type));
		cout << i << ". " << type.getName() << endl;
	}
	cin >> selected;
	system("cls");
	file.close();

	Syscat::getInstance()->del_type(selected);

	return true;
}

bool Ddl::listTypes() {
	Type types[15];
	fstream file;
	char max;
	file.open(".\\sys2.cat", ios::in | ios::beg);
	file.get(max);
	file.close();
	int maxint = max - '0';
	int i = 0;
	for (int position = 0; position < maxint*(int)sizeof(Type); position += sizeof(Type)) {
		types[i] = Syscat::getInstance()->get_type(position);
		i++;
	}
	int j = 0;
	cout << "TYPES: " << endl << endl;
	while (j < i) {
		cout << j+1 << " " << types[j].getName() << endl;
		j++;
	}

	cout << endl << endl << "---------" << endl ;
	return true;
}
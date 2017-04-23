#include "syscat.h"

using namespace std;

Syscat *Syscat::instance = NULL;

Syscat::Syscat() {

}

Syscat *Syscat::getInstance() {
	if (!instance) {
		instance = new Syscat();
	}
	return instance;
}

bool Syscat::reg_type(Type type) {
	fstream syscat;
	int tid = type.getId() - 48;
	syscat.open(".\\sys.cat", ios::out| ios::binary | ios::app);
	syscat.seekp(tid * sizeof(Type));
	cout << tid * sizeof(Type);
	syscat.write((char *)&type, sizeof(Type));
	syscat.close();
	syscat.open(".\\sys2.cat", ios::out | ios::beg | ios::trunc );
	syscat.put((char)(type.getId() + 1));
	syscat.close();
	return true;

}

Type Syscat::get_type( int position) {
	Type type;
	fstream syscat;
	syscat.open(".\\sys.cat", ios::in | ios::binary);
	syscat.seekg(position);
	syscat.read((char *)&type, sizeof(Type));
	syscat.close();
	return type;
}

bool Syscat::del_type(int id) {
	fstream syscat;
	Type typeend;
	syscat.open(".\\sys.cat", ios::out | ios::in | ios::binary);

	fstream file;
	char max;
	char BUFFER[100000];
	file.open(".\\sys2.cat", ios::out | ios::in | ios::beg);
	file.get(max);
	int maxint = max - '0';
	char newmax = (maxint-1) + '0';
	//cout << "newmax: " << newmax << endl;
	file.seekp(0);
	file.put(newmax);
	file.close();

	syscat.seekg((maxint-1)*(int)sizeof(Type));
	syscat.read((char *)&typeend, sizeof(Type));
	typeend.setId(id-1);
	//cout << "id setted " << id - 1 << endl << typeend.getId() << endl;
	syscat.seekp((id-1)*(int)sizeof(Type));
	syscat.write((char *)&typeend, sizeof(Type));
	syscat.seekg(0);
	syscat.read(BUFFER, (maxint - 1)*(int)sizeof(Type));
	syscat.close();

	syscat.open(".\\temp.cat", ios::out | ios::binary);
	syscat.write(BUFFER, (maxint - 1)*(int)sizeof(Type));
	remove(".\\sys.cat");
	syscat.close();
	int ren = rename("temp.cat", "sys.cat");
	if (ren)
		cout << "error renaming";
	

	return true;

}
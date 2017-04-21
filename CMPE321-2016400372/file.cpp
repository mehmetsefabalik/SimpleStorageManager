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
	/*fstream datafile;

	datafile.open(".\\record.dat", ios::in);

	if (datafile.is_open()) {
		datafile.close(); 
		return true;
	}
	else {
		datafile.open(".\\data.dat", ios::out);
		datafile.close();
		return true;
	}*/
	return true;

}

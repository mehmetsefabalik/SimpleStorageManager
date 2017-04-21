#include "Record.h"

using namespace std;

Record::Record() {

}

Record::Record(Type type, int id, char *f1, char *f2, char *f3,
	char *f4, char *f5) {
	this->type = type;
	this->id = id;
	strcpy_s(F1, f1);
	strcpy_s(F2, f2);
	strcpy_s(F3, f3);
	strcpy_s(F4, f4);
	strcpy_s(F5, f5);
}


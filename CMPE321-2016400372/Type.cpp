#include "Type.h"

using namespace std;

Type::Type() {
	/*this->name = NULL;
	this->numberOF = NULL;
	this->F1 = NULL;
	this->F2 = NULL;
	this->F3 = NULL;*/
}

Type::Type(int id, char *name, int numberOfFields, char *field1, char *field2
	, char *field3, char *field4, char *field5) {
	strcpy_s(this->name, name);
	this->id = id;
	this->numberOF = numberOfFields;
	strcpy_s(this->F1, field1);
	strcpy_s(this->F2, field2);
	strcpy_s(this->F3, field3);
	strcpy_s(this->F4, field4);
	strcpy_s(this->F5, field5);
}

int Type::getNumberOF() {
	return numberOF;
}

char *Type::getName() {
	return name;
}

char *Type::getF1() {
	return F1;
}

char *Type::getF2() {
	return F2;
}

char *Type::getF3() {
	return F3;
}

char *Type::getF4() {
	return F4;
}

char *Type::getF5() {
	return F5;
}

int Type::getId() {
	return id;
}

void Type::setId(int id) {
	this->id = id;
}
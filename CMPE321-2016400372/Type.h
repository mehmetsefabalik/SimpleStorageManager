#ifndef TYPE_H
#define TYPE_H

#include <iostream>
#include <fstream>

class Type {
	char name[15], F1[15], F2[15], F3[15], F4[15], F5[15];
	int id, numberOF;
public:
	Type();
	Type(int id, char *name, int numberOfFields, char *field1, char *field2
		, char *field3, char *field4, char *field5);
	char *getName();
	int getId();
	void setId(int id);
	int getNumberOF();
	char *getF1();
	char *getF2();
	char *getF3();
	char *getF4();
	char *getF5();
};


#endif // !TYPE_H

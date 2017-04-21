#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <fstream>
#include "Type.h"

class Record {
	char F1[15], F2[15], F3[15], F4[15], F5[15];
	Type type;
	int id;
public:
	Record();
	Record(Type type,int id, char *f1, char *f2, char *f3, 
			char *f4, char *f5);
	Type getType();
	int getId();
	void setId(int id);
};
#endif // !RECORD_H

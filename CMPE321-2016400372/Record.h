#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <fstream>
#include "dml_entrance.h"
#include "Page.h"
#include "file.h"

class Record {
	char name[15], F1[15], F2[15], F3[15], F4[15], F5[15];
	int id;
public:
	Record();
	Record();
	char getName();
	int getId();
	void setId(int id);
};
#endif // !RECORD_H

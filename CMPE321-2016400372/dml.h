#ifndef DML_H
#define DML_H 

#include <iostream>
#include "file.h"
#include "syscat.h"

using namespace std;

class Dml {
	static Dml *instance;
	Dml();
public:
	static Dml *getInstance();
	bool createRecord();
	bool deleteRecord();
	bool updateRecord();
	bool searchRecord();
	bool listRecords();
};
#endif // !DML_H
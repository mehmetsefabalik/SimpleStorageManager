#ifndef DLL_H
#define DLL_H 

#include <iostream>
#include "file.h"
#include "syscat.h"
#include <iomanip>
#include "dll_entrance.h"

using namespace std;

class Ddl {
	static Ddl *instance;
	Ddl();
	char typeName[15], F1[15], F2[15], F3[15], F4[15], F5[15];
	int NOF;
public:
	static Ddl *getInstance();
	bool createType();
	bool deleteType();
	bool listTypes();
};
#endif // !DLL_H
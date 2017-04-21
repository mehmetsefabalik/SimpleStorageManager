#ifndef ENTRANCE_H
#define ENTRANCE_H 

#include <iostream>
#include "dll_entrance.h"
#include "dml_entrance.h"

using namespace std;

class Entrance {
	static Entrance *instance;
	Entrance();
public:
	static Entrance *getInstance();
	void console();
};
#endif // !ENTRANCE_H
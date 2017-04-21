#ifndef DML_ENTRANCE_H
#define DML_ENTRANCE_H

#include <iostream>
#include "dml.h"
#include "entrance.h"

using namespace std;

class DmlEntrance
{
	static DmlEntrance *instance;
	DmlEntrance();
public:
	static DmlEntrance *getInstance();
	void console();
};
#endif // !DML_ENTRANCE_H 
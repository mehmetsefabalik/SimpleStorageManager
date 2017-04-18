#ifndef DML_ENTRANCE_H
#define DML_ENTRANCE_H

#include <iostream>

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
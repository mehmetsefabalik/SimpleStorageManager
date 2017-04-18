#ifndef DLL_ENTRANCE_H
#define DLL_ENTRANCE_H

#include <iostream>

using namespace std;

class DdlEntrance 
{
	static DdlEntrance *instance;
	DdlEntrance();
public:
	static DdlEntrance *getInstance();
	void console();
};
#endif // !DLL_ENTRANCE_H

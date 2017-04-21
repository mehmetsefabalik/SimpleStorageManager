#ifndef SYSCAT_H
#define SYSCAT_H

#include <iostream>
#include <fstream>
#include "file.h"
#include "Type.h"


class Syscat {
	static Syscat *instance;
	Syscat();
public:
	static Syscat *getInstance();
	static bool reg_type(Type type);
	static Type get_type(int pos);
	static bool del_type(int id);
};
#endif // !SYSCAT_H

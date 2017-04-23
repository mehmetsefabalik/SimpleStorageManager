#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <iostream>
#include "Record.h"
#include "Page.h"

class File {
	static File *instance;
	File();
public:
	static File *getInstance();
	static bool reg_rec(Record record);
	static bool reg_page(Record record);
	static bool get_rec();
	static bool get_page();
};
#endif // !FILE_H

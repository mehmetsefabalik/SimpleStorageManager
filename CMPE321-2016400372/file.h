#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <iostream>

class File {
	static File *instance;
	File();
public:
	static File *getInstance();
	bool createFile();
	bool createPage();
	bool isPageFull();
};
#endif // !FILE_H

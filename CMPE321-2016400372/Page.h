#ifndef PAGE_H
#define PAGE_H

#include <iostream>
#include <fstream>
#include "file.h"
#include "Record.h"

class Page {
	char name[15];
	Record R1, R2, R3, R4, R5;
	int id;
public:
	Page();	
	Page(char *name, int id, Record r1, Record r2, Record r3, 
		Record r4, Record r5);
	char getName();
	int getId();
	Record getR1();
	Record getR2();
	Record getR3();
	Record getR4();
	Record getR5();
	void setId(int id);
	void setName(char *name);
	void setR1(Record r1);
	void setR2(Record r2);
	void setR3(Record r3);
	void setR4(Record r4);
	void setR5(Record r5);
	
};

#endif // !PAGE_H

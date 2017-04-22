#ifndef PAGE_H
#define PAGE_H

#include <iostream>
#include <fstream>
#include "Record.h"

class Page {
	Record *R1, *R2,* R3, *R4, *R5;
	int id, NOR;
public:
	Page();	
	int getId();
	Record* getR1();
	Record* getR2();
	Record* getR3();
	Record* getR4();
	Record* getR5();
	int getNor();
	void setId(int id);
	void setR1(Record* r1);
	void setR2(Record* r2);
	void setR3(Record* r3);
	void setR4(Record* r4);
	void setR5(Record* r5);
	void setNor(int nor);
};

#endif // !PAGE_H

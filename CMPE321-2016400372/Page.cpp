#include "Page.h"

using namespace std;

Page::Page(){

}

Page::Page(int id, Record r1, Record r2, Record r3,
	Record r4, Record r5) {
	this->id = id;
	r1 = R1;
	r2 = R2;
	r3 = R3;
	r4 = R4;
	r5 = R5;
}


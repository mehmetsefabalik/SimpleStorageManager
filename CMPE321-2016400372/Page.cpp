#include "Page.h"

using namespace std;

Page::Page(){
	Record R1;
	Record R2;
	Record R3;
	Record R4;
	Record R5;
}

int Page::getId() {
	return id;
}

int Page::getNor() {
	return NOR;
}

Record Page::getR2() {
	return R2;
}

Record Page::getR1() {
	return R1;
}

Record Page::getR3() {
	return R3;
}

Record Page::getR4() {
	return R4;
}

Record Page::getR5() {
	return R5;
}

void Page::setId(int id) {
	this->id = id;
}

void Page::setNor(int nor) {
	this->NOR = nor;
}

void Page::setR1(Record r1) {
	this->R1 = r1;
}

void Page::setR2(Record r2) {
	this->R2 = r2;
}

void Page::setR3(Record r3) {
	this->R3 = r3;
}

void Page::setR4(Record r4) {
	this->R4 = r4;
}

void Page::setR5(Record r5) {
	this->R5 = r5;
}



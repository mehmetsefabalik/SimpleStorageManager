#include "dml.h"

using namespace std;

Dml *Dml::instance = NULL;

Dml *Dml::getInstance() {
	if (!instance)
		instance = new Dml();
	return instance;
}

Dml::Dml() {

}

bool Dml::createRecord() {
	return true;
}

bool Dml::deleteRecord() {
	return true;
}

bool Dml::searchRecord() {
	return true;
}

bool Dml::updateRecord() {
	return true;
}

bool Dml::listRecords() {
	return true;
}
#include "Driver.h"

Driver::Driver() {
	vArray = new Vertex[20];//Predetermined maximums
	eArray = new Edge[20];
}

Driver::Driver(Driver& d) {
	vArray = d.vArray;
	eArray = d.eArray;
}

Driver::Driver(Vertex* vArray, Edge* eArray) {
	this->vArray = vArray;
	this->eArray = eArray;
}

Driver::~Driver() {
	delete[] vArray;
	delete[] eArray;
}
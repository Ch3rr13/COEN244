#include <iostream>
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
	this->vArray = new Vertex[20];
	this->eArray = new Edge[20];
	this->vArray = vArray;
	this->eArray = eArray;
}

bool Driver::addVertices(Vertex* vArray, int size) {
	for (int i = 0; i < 20; i++) {
		if (this->vArray[i].getID() == 0) {//check if the vertice is empty
			for (int j = 0; j < size; j++) { // i dont think this works because 
				this->vArray[i] = vArray[j];
				i++;
			}
			return true;
		}
	}
	return false;
}

Vertex Driver::searchEndVertex(Vertex& vertex) {

}

bool Driver::addValue(std::string value, Vertex& vertex) {

}

bool Driver::searchValueExists(std::string value) {

}

bool Driver::addEdges(Edge* eArray, int size) {
	//same as addVertices
	for (int i = 0; i < 20; i++) {
		if (this->eArray[i].getWeight() == 0) {//check if the vertice is empty
			for (int j = 0; j < size; j++) { // i dont think this works because 
				this->eArray[i] = eArray[j];
				i++;
			}
			return true;
		}
	}
	return false;
}

bool Driver::searchEdgeExists(Edge& edge) {

}

void Driver::convertGraph() {

}

void Driver::display() {

}

Driver::~Driver() {
	delete[] vArray;
	delete[] eArray;
}
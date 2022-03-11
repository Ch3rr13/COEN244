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

bool Driver::addVertices(Vertex* vArray) {

}

Vertex Driver::searchEndVertex(Vertex& vertex) {

}

bool Driver::addValue(std::string value, Vertex& vertex) {

}

bool Driver::searchValueExists(std::string value) {

}

bool Driver::addEdges(Edge* eArray) {

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
#include <iostream>
#include "Driver.h"

Driver::Driver() {
	Max = 20;//Predetermined maximums
	NumVertex = 0;
	NumEdge = 0;
	vArray = new Vertex[Max];
	eArray = new Edge[Max];
}

Driver::Driver(Driver& d) {
	Max = d.Max;
	NumVertex = d.NumVertex;
	NumEdge = d.NumEdge;
	vArray = d.vArray;
	eArray = d.eArray;
}

Driver::Driver(Vertex* vArray, Edge* eArray, int NumV, int NumE, int Max) {
	this->Max = Max;
	this->NumVertex = NumVertex;
	this->NumEdge = NumEdge;
	this->vArray = new Vertex[20];
	this->eArray = new Edge[20];
}

bool Driver::addVertices(Vertex* vArray, int size) {
	if(NumVertex+size <= 20) {
		for (int i = 0; i < size; i++) {
			this->vArray[NumVertex+i] = vArray[i];
			NumVertex++;
		}
		return true;

	}
	else {
		return false;
	}

	/*
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
	*/
}

Vertex Driver::searchEndVertex(Vertex& vertex) {
	for (int i = 0; i < NumVertex; i++) {

	}
}

bool Driver::addValue(std::string value, Vertex& vertex) {
	for (int i = 0; i < NumVertex; i++) {
		if (vArray[i].getID() == vertex.getID()) {
			vArray[i].setValue(value);
			return true;
		}
	}
	return false;
}

bool Driver::searchValueExists(std::string value) {
	for (int i = 0; i < NumVertex; i++) {
		if (vArray[i].getValue() == value) {
			return true;
		}
	}
	return false;
}

bool Driver::addEdges(Edge* eArray, int size) {
	if (NumEdge + size <= 20) {
		for (int i = 0; i < size; i++) {
			this->eArray[NumEdge+i] = eArray[i];
			NumEdge++;
		}
		return true;

	}
	else {
		return false;
	}

	/*
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
	*/
}

bool Driver::searchEdgeExists(Edge& edge) {
	for (int i = 0; i < NumEdge; i++) {
		if (eArray[i].getStartVertex().getID() == edge.getStartVertex().getID() && eArray[i].getEndVertex().getID() == edge.getEndVertex().getID()) {
			return true;
		}
	}
	return false;
}

void Driver::convertGraph() {

}

void Driver::display() {
	for (int i = 0; i < NumEdge; i++) {
		std::cout << eArray[i].getStartVertex().getValue() << " - " << eArray->getWeight() << " - " << eArray->getEndVertex().getValue();
	}
}

Driver::~Driver() {
	delete[] vArray;
	delete[] eArray;
}
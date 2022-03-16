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

bool Driver::addVertices(Vertex* vArray) {
	if(NumVertex + sizeof(vArray) <= Max) {
		for (int i = 0; i < sizeof(vArray); i++) {
			this->vArray[NumVertex + i] = vArray[i];
			NumVertex++;
		}
		return true;
	}
	else {
		return false;
	}
}

Vertex Driver::searchEndVertex(Vertex& vertex) {
	for (int i = 0; i < NumVertex; i++) {
		if (vArray[i].getID() == vertex.getID() && vArray[i].getValue() == vertex.getValue())
		{
			return vArray[i];
		}
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

bool Driver::addEdges(Edge* eArray) {
	if (NumEdge + sizeof(eArray) <= Max) {
		for (int i = 0; i < sizeof(eArray); i++) {
			this->eArray[NumEdge + i] = eArray[i];
			NumEdge++;

			//Adds starting to the array
			this->vArray[NumVertex + i] = this->eArray[NumEdge + i].getStartVertex();
			NumVertex++;
			//Adds ending vertices to the array
			this->vArray[NumVertex + i] = this->eArray[NumEdge + i].getEndVertex();
			NumVertex++;
		}
		return true;
	}
	else {
		return false;
	}
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
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
	this->NumVertex = NumV;
	this->NumEdge = NumE;
	this->vArray = new Vertex[Max];
	this->eArray = new Edge[Max];
}

bool Driver::addVertices(Vertex* vArray, int size) {
	try//EXCEPTION: Array overflow
	{
		if (NumEdge + size >= Max)
		{
			throw size;
		}
		else
		{
			for (int i = 0; i < size; i++) {
				this->vArray[NumVertex] = vArray[i];
				NumVertex++;
			}
			return true;
		}
	}
	catch (int i)
	{
		std::cout << "List of vertices has reached max capacity" << std::endl;
		return false;
	}
}


bool Driver::addValue(std::string value, Vertex& vertex) {//EXCEPTION: Array overflow + input type
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

bool Driver::addEdges(Edge* eArray, int size) {//Exception: Array overflow
	if (NumEdge + size <= Max) {
		for (int i = 0; i < size; i++) {
			//search if start and end vertex of edge exists
			if(this->searchValueExists(eArray[i].getStartVertex().getValue()) && this->searchValueExists(eArray[i].getEndVertex().getValue())) {
				this->eArray[NumEdge] = eArray[i];
				NumEdge++;
			}
		}
		return true;
	}
	else {
		return false;
	}

	/*try
	{
		if (NumEdge + size >= Max)
		{
			throw size;
		}
	}
	catch (int i)
	{
		std::cout << "List of vertices has reached max capacity" << std::endl;
	}*/
}

bool Driver::searchEdgeExists(Edge* edge) {
	for (int i = 0; i < NumEdge; i++) {
		if (eArray[i].getStartVertex().getID() == edge->getStartVertex().getID() && eArray[i].getEndVertex().getID() == edge->getEndVertex().getID()) {
			return true;
		}
	}
	return false;
}

/*
void Driver::convertGraph() {

}
*/

void Driver::display() {
	
	std::cout << "List of Vertex: " << std::endl;
	std::cout << "ID - Value" << std::endl;
	for (int i = 0; i < NumVertex; i++) {
		std::cout << vArray[i].getID() << " = " << vArray[i].getValue() << std::endl;
	}

	std::cout << "List of Edges: " << std::endl;
	for (int i = 0; i < NumEdge; i++) {
		std::cout << eArray[i].getStartVertex().getValue() << " --" << eArray[i].getWeight() << "--> " << eArray[i].getEndVertex().getValue() << std::endl;
	}
}
void Driver::displaypaths() {
	std::cout << "List of Edges: " << std::endl;
	for (int i = 0; i < NumEdge; i++) {
		std::cout << eArray[i].getStartVertex().getValue() << " --" << eArray[i].getWeight() << "--> " << eArray[i].getEndVertex().getValue() << std::endl;
	}
}
void Driver::displaypathsfromVertex(Vertex& v) {
	for (int i = 0; i < NumEdge; i++) {
		if (eArray[i].getStartVertex().getValue() == v.getValue()) {
			std::cout << v.getValue() << " --" << eArray[i].getWeight() << "--> " << eArray[i].getEndVertex().getValue() << std::endl;;
		}
	}
}

Driver::~Driver() {
	delete[] vArray;
	delete[] eArray;
}
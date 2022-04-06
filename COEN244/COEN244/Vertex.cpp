#include "Vertex.h"

Vertex::Vertex() {
	ID = UniqueID;
	value = "NO VALUE ";
}

Vertex::Vertex(Vertex& v) {
	ID = v.ID;
	value = v.value;
}

Vertex::Vertex(std::string value) {
	UniqueID++;
	ID = UniqueID;
	this->value = value;
}

void Vertex::setID(int ID) {
	this->ID = ID;
}

int Vertex::getID() {
	return ID;
}

void Vertex::setValue(std::string value) {
	UniqueID++;
	ID = UniqueID;
	this->value = value;
}

std::string Vertex::getValue(){
	return value;
}

Vertex::~Vertex() {
	//Deletes smt
}
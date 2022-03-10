#include "Vertex.h"

Vertex::Vertex() {
	ID = 0;
	value = " ";
}

Vertex::Vertex(Vertex& v) {
	ID = v.ID;
	value = v.value;
}

Vertex::Vertex(int ID, std::string value) {
	this->ID = ID;
	this->value = value;
}

void Vertex::setID(int ID) {
	this->ID = ID;
}

int Vertex::getID() {
	return ID;
}

void Vertex::setValue(std::string value) {
	this->value = value;
}

std::string Vertex::getValue() {
	return value;
}

Vertex::~Vertex() {
	//Deletes smt
}
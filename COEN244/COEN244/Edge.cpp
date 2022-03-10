#include "Edge.h"

Edge::Edge() {
	weight = 0;
	startVertex = new Vertex;
	endVertex = new Vertex;
}

Edge::Edge(Edge& e) {
	weight = e.weight;
	startVertex = e.startVertex;
	endVertex = e.endVertex;
}

Edge::Edge(int weight, Vertex* startVertex, Vertex* endVertex) {
	this->weight = weight;
	this->startVertex = startVertex;
	this->endVertex = endVertex;
}

void Edge::setWeight(int weight) {
	this->weight = weight;
}

int Edge::getWeight() {
	return weight;
}

void Edge::setStartVertex(Vertex& startVertex) {
	this->startVertex = &startVertex;
}

Vertex Edge::getStartVertex() {
	return *startVertex;
}

void Edge::setEndVertex(Vertex& endVertex) {
	this->endVertex = &endVertex;
}

Vertex Edge::getEndVertex() {
	return *endVertex;
}

Edge::~Edge() {
	delete startVertex;
	delete endVertex;
}
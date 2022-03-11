#include "Graph.h"

Graph::Graph() {
	vArray = new Vertex[20];//Predetermined maximums
	eArray = new Edge[20];
}

Graph::Graph(Graph& g) {
	vArray = g.vArray;
	eArray = g.eArray;
}

Graph::Graph(Vertex* vArray, Edge* eArray) {
	this->vArray = vArray;
	this->eArray = eArray;
}

Graph::~Graph() {
	delete[] vArray;
	delete[] eArray;
}
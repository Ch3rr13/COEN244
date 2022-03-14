#pragma once
#include "Graph.h"

class Driver: public Graph
{
private:
	Vertex* vArray;
	Edge* eArray;

public:
	Driver();//Default constructor
	Driver(Driver&);//Copy constructor
	Driver(Vertex*, Edge*);//Parameter constructor

	bool addVertices(Vertex*, int);
	Vertex searchEndVertex(Vertex&);

	bool addValue(std::string, Vertex&);
	bool searchValueExists(std::string);

	bool addEdges(Edge*, int);
	bool searchEdgeExists(Edge&);

	void convertGraph();

	void display();

	~Driver();
};


#pragma once
#include "Vertex.h"

class Edge
{
private:
	int weight;
	Vertex* startVertex;
	Vertex* endVertex;

public:
	Edge();//Default constructor

	void setWeight(int);
	int getWeight();

	void setStartVertex(Vertex&);
	Vertex getStartVertex();

	void setEndVertex(Vertex&);
	Vertex getEndVertex();

	~Edge();//Destructor
};


#pragma once
#include "Vertex.h"

class Edge
{
private:
	std::string weight;
	Vertex* startVertex;
	Vertex* endVertex;

public:
	Edge();//Default constructor
	Edge(Edge&);//Copy constructor          
	Edge(std::string, Vertex&, Vertex&);//Parameter constructor

	void setInfo(std::string, Vertex&, Vertex&);

	void setWeight(std::string);
	std::string getWeight();

	void setStartVertex(Vertex&);
	Vertex getStartVertex();

	void setEndVertex(Vertex&);
	Vertex getEndVertex();

	~Edge();//Destructor
};


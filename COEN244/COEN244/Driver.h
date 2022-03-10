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


};


#pragma once
#include "Graph.h"

class Driver: public Graph
{
private:
	int Max;
	int NumVertex;
	int NumEdge;
	Vertex* vArray;
	Edge* eArray;

public:
	Driver();//Default constructor
	Driver(Driver&);//Copy constructor
	Driver(Vertex*, Edge*,int,int, int);//Parameter constructor

	bool addVertices(Vertex*, int);
	void displaypathsfromVertex(Vertex&);

	bool addValue(std::string, Vertex&);
	bool searchValueExists(std::string);

	bool addEdges(Edge*, int);
	bool searchEdgeExists(Edge*);

	//void convertGraph();

	void display();
	void displaypaths();
	~Driver();
};

class UndirectedDriver : public Graph
{
private:
	int Max;
	int NumVertex;
	int NumEdge;
	Vertex* vArray;
	Edge* eArray;

public:
	UndirectedDriver();//Default constructor
	UndirectedDriver(UndirectedDriver&);//Copy constructor
	UndirectedDriver(Vertex*, Edge*, int, int, int);//Parameter constructor

	bool addVertices(Vertex*, int);
	void displaypathsfromVertex(Vertex&);

	bool addValue(std::string, Vertex&);
	bool searchValueExists(std::string);

	bool addEdges(Edge*, int);
	bool searchEdgeExists(Edge*);

	void display();
	void displaypaths();
	~UndirectedDriver();
};


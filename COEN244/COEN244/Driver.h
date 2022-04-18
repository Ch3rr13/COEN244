#pragma once
#include "Graph.h"

class Driver: public Graph
{
private:
	int Max;
	int NumVertex;
	int NumEdge;
	int loopcounter;
	Vertex* vArray;
	Edge* eArray;

public:
	Driver();//Default constructor
	Driver(Driver&);//Copy constructor
	Driver(Vertex*, Edge*,int,int, int);//Parameter constructor

	bool addVertices(Vertex*, int);
	void displaypathsfromVertex(Vertex&);
	void displaypathsfromVertex(std::string value);

	//void displaypathsbetweenVertex(Vertex&, Vertex&);		//does not work

	Vertex& searchVertex(std::string);

	bool addValue(std::string, Vertex&);
	bool searchValueExists(std::string);

	bool addEdges(Edge*, int);
	bool searchEdgeExists(Edge*);
	bool searchEdgeExists(std::string weight, std::string v1, std::string v2);

	void Vertexpath2(int i, Vertex& v);
	void Vertexpath(Vertex& a);

	void display();
	void displaypaths();
	~Driver();
};

//	-------------------------------------------

class UndirectedDriver : public Graph
{
private:
	int Max;
	int NumVertex;
	int NumEdge;
	int loopcounter;
	Vertex* vArray;
	Edge* eArray;

public:
	UndirectedDriver();//Default constructor
	UndirectedDriver(UndirectedDriver&);//Copy constructor
	UndirectedDriver(Vertex*, Edge*, int, int, int);//Parameter constructor

	bool addVertices(Vertex*, int);
	void displaypathsfromVertex(Vertex&);
	void displaypathsfromVertex(std::string value);
	//void displaypathsfromVertextest(std::string value);

	//void displaypathsbetweenVertex(Vertex&, Vertex&);

	Vertex& searchVertex(std::string);

	bool addValue(std::string, Vertex&);
	bool searchValueExists(std::string);
	bool searchEdgeExists(std::string weight, std::string v1, std::string v2);

	bool addEdges(Edge*, int);
	bool searchEdgeExists(Edge*);

	void Vertexpath2(int i, Vertex& v);
	void Vertexpath(Vertex& v);

	void display();
	void displaypaths();
	~UndirectedDriver();
};


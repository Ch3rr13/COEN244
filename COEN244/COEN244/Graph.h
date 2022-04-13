#pragma once
#include <string>
#include "Edge.h"
#include "Vertex.h"

class Graph
{//Abstract class
private:
	Vertex* vArray;
	Edge* eArray;

public:
	Graph();//Default
	Graph(Graph&);//Copy constructor
	Graph(Vertex*, Edge*);//Parameter constructor

	//Adds list of Vertices to graph; Returns bool value if successful
	virtual bool addVertices(Vertex*, int) = 0;
	//Searches for ending points of a starting point
	//virtual Vertex searchEndVertex(Vertex&) = 0;					//think later

	//Add value to Vertex; Returns bool value if successful
	virtual bool addValue(std::string, Vertex&) = 0;
	//Searches if certain value in Vertices exists; Returns bool value if exists
	virtual bool searchValueExists(std::string) = 0;

	virtual Vertex& searchVertex(std::string) = 0;
	
	//Adds list of edges to graph; Returns bool value if successful
	virtual bool addEdges(Edge*, int) = 0;
	//Searches if Edge exists; Returns bool value if exists
	virtual bool searchEdgeExists(Edge*) = 0;
	virtual bool searchEdgeExists(std::string weight, std::string v1, std::string v2) = 0;


	//Displays a list of edges
	virtual void display() = 0;
	virtual void displaypaths() = 0;
	virtual void displaypathsfromVertex(Vertex&) = 0;
	virtual void displaypathsfromVertex(std::string value) = 0;

	virtual ~Graph();
};


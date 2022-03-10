#pragma once
#include <string>
#include "Edge.h"
#include "Vertex.h"

class Graph
{
	Graph();

	//Adds list of Vertices to graph; Returns bool value if successful
	virtual bool addVertices(Vertex*) = 0;
	//Searches for ending points of a starting point
	virtual Vertex searchEndVertex(Vertex&) = 0;

	//Add value to Vertex; Returns bool value if successful
	virtual bool addValue(std::string, Vertex&) = 0;
	//Searches if certain value in Vertices exists; Returns bool value if exists
	virtual bool searchValueExists(std::string) = 0;

	//Adds list of edges to graph; Returns bool value if successful
	virtual bool addEdges(Edge*) = 0;
	//Searches if Edge exists; Returns bool value if exists
	virtual bool searchEdgeExists(Edge&) = 0;

	//Converts graph from directional to undirectional and viceversa
	virtual void convertGraph() = 0;//TO GO BACK TO LATER

	//Displays a list of edges
	virtual void display() const = 0;

	virtual ~Graph();
};


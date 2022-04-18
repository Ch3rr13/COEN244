#include <iostream>
#include "Driver.h"

Driver::Driver() {
	Max = 20;//Predetermined maximums
	NumVertex = 0;
	NumEdge = 0;
	vArray = new Vertex[Max];
	eArray = new Edge[Max];
	loopcounter = 0;
}

Driver::Driver(Driver& d) {
	Max = d.Max;
	NumVertex = d.NumVertex;
	NumEdge = d.NumEdge;
	vArray = d.vArray;
	eArray = d.eArray;
	loopcounter = d.loopcounter;
}

Driver::Driver(Vertex* vArray, Edge* eArray, int NumV, int NumE, int Max) {
	this->Max = Max;
	this->NumVertex = NumV;
	this->NumEdge = NumE;
	this->vArray = new Vertex[Max];
	this->eArray = new Edge[Max];
	loopcounter = 0;
}

bool Driver::addVertices(Vertex* vArray, int size) {
	try//EXCEPTION: Array overflow
	{
		if (NumVertex + size > Max)
		{
			throw size;
		}
		else
		{
			for (int i = 0; i < size; i++) {
				this->vArray[NumVertex] = vArray[i];
				NumVertex++;
			}
			return true;
		}
	}
	catch (...)
	{
		std::cout << "List of vertices has reached max capacity" << std::endl;
		return false;
	}
}


bool Driver::addValue(std::string value, Vertex& vertex) {
	for (int i = 0; i < NumVertex; i++) {
		if (vArray[i].getID() == vertex.getID()) {
			vArray[i].setValue(value);
			return true;
		}
	}
	return false;
}

bool Driver::searchValueExists(std::string value) {
	for (int i = 0; i < NumVertex; i++) {
		if (vArray[i].getValue() == value) {
			return true;
		}
	}
	return false;
}

bool Driver::addEdges(Edge* eArray, int size) {
	try//Exception: Array overflow
	{
		if (NumEdge + size >= Max)
		{
			throw size;
		}
		else
		{
			for (int i = 0; i < size; i++) {
				//search if start and end vertex of edge exists
				if (this->searchValueExists(eArray[i].getStartVertex().getValue()) && this->searchValueExists(eArray[i].getEndVertex().getValue())) {
					this->eArray[NumEdge] = eArray[i];
					NumEdge++;
				}
			}
			return true;
		}
	}
	catch (...)
	{
		std::cout << "List of edges has reached max capacity" << std::endl;
		return false;
	}
}

bool Driver::searchEdgeExists(Edge* edge) {
	for (int i = 0; i < NumEdge; i++) {
		if (eArray[i].getStartVertex().getID() == edge->getStartVertex().getID() && eArray[i].getEndVertex().getID() == edge->getEndVertex().getID()) {
			return true;
		}
	}
	return false;
}

bool Driver::searchEdgeExists(std::string weight, std::string v1, std::string v2) {		//function overloading
	for (int i = 0; i < NumEdge; i++) {
		if (eArray[i].getWeight() == weight && eArray[i].getStartVertex().getID() == searchVertex(v1).getID() && eArray[i].getEndVertex().getID() == searchVertex(v2).getID()) {
			return true;
		}
	}
	return false;
}


void Driver::display() {
	
	std::cout << "List of Vertex: " << std::endl;
	std::cout << "ID - Value" << std::endl;
	for (int i = 0; i < NumVertex; i++) {
		std::cout << vArray[i].getID() << " = " << vArray[i].getValue() << std::endl;
	}

	std::cout << "List of Edges: " << std::endl;
	for (int i = 0; i < NumEdge; i++) {
		std::cout << eArray[i].getStartVertex().getValue() << " --" << eArray[i].getWeight() << "--> " << eArray[i].getEndVertex().getValue() << std::endl;
	}
}
void Driver::displaypaths() {
	std::cout << "List of Edges: " << std::endl;
	for (int i = 0; i < NumEdge; i++) {
		std::cout << eArray[i].getStartVertex().getValue() << " --" << eArray[i].getWeight() << "--> " << eArray[i].getEndVertex().getValue() << std::endl;
	}
}
void Driver::displaypathsfromVertex(Vertex& v) {
	for (int i = 0; i < NumEdge; i++) {
		if (eArray[i].getStartVertex().getValue() == v.getValue()) {
			std::cout << v.getValue() << " --" << eArray[i].getWeight() << "--> " << eArray[i].getEndVertex().getValue() << std::endl;;
		}
	}
}

void Driver::displaypathsfromVertex(std::string value) {
	for (int i = 0; i < NumEdge; i++) {
		if (eArray[i].getStartVertex().getValue() == value) {
			std::cout << value << " --" << eArray[i].getWeight() << "--> " << eArray[i].getEndVertex().getValue() << std::endl;
		}
	}
}

/*				// DOES NOT WORK
void Driver::displaypathsbetweenVertex(Vertex& v1, Vertex& v2) {
	if (!searchValueExists(v1.getValue()) || !searchValueExists(v2.getValue())) {
		std::cout << "Vertex does not exists\n";
		return;
	}
	
	if (v1.getID() == v2.getID()) {
		std::cout << "Vertex is the same\n";
		return;
	}
	

	for (int i = 0; i < NumEdge; i++) {
		if (eArray[i].getStartVertex().getID() == v1.getID()) {		//found starting point
			if (eArray[i].getEndVertex().getID() == v2.getID()) {
				std::cout << eArray[i].getStartVertex().getValue() << " --" << eArray[i].getWeight() << "--> " << eArray[i].getEndVertex().getValue() << std::endl;
			}
			displaypathsbetweenVertex(searchVertex(eArray[i].getEndVertex().getValue()), v2);

		}
		
		
	}
}
*/

void Driver::Vertexpath2(int i, Vertex& v)
{	
	try
	{
		if (loopcounter > NumEdge)
		{
			throw loopcounter;
		}
		else
		{
			loopcounter++;

			for (int j = 0; j < NumEdge; j++)
			{
				if (eArray[i].getEndVertex().getValue() == eArray[j].getStartVertex().getValue())
				{
					if (eArray[i].getStartVertex().getValue() != v.getValue()) {
						std::cout << v.getValue() << "---->";
					}
					std::cout << eArray[i].getStartVertex().getValue() << "--" << eArray[i].getWeight() << "-->" << eArray[i].getEndVertex().getValue();
					std::cout << "--" << eArray[j].getWeight() << "-->" << eArray[j].getEndVertex().getValue() << std::endl;
					Vertexpath2(j, v);
				}
			}
		}
	}
	catch (int x)
	{
		return;
	}
}

void Driver::Vertexpath(Vertex& v)
{
	std::cout << "List of all possible paths from the starting vertex: " << std::endl;

	for (int i = 0; i < NumEdge; i++)
	{
		if (eArray[i].getStartVertex().getValue() == v.getValue())
		{
			std::cout << v.getValue() << "--" << eArray[i].getWeight() << "-->" << eArray[i].getEndVertex().getValue() << std::endl;
			Vertexpath2(i, v);

			std::cout << std::endl;
			loopcounter = 0;
		}
		
	}
}

Vertex& Driver::searchVertex(std::string val) {
	for (int i = 0; i < NumVertex; i++) {
		if (vArray[i].getValue() == val) {
			return vArray[i];
		}
	}
	Vertex a;
	return a;
}


Driver::~Driver() {
	delete[] vArray;
	delete[] eArray;
}



//
//Implementation for undirected graph
//



UndirectedDriver::UndirectedDriver() {
	Max = 20;//Predetermined maximums
	NumVertex = 0;
	NumEdge = 0;
	vArray = new Vertex[Max];
	eArray = new Edge[Max];
	loopcounter = 0;
}

UndirectedDriver::UndirectedDriver(UndirectedDriver& d) {
	Max = d.Max;
	NumVertex = d.NumVertex;
	NumEdge = d.NumEdge;
	vArray = d.vArray;
	eArray = d.eArray;
	loopcounter = 0;
}

UndirectedDriver::UndirectedDriver(Vertex* vArray, Edge* eArray, int NumV, int NumE, int Max) {
	this->Max = Max;
	this->NumVertex = NumV;
	this->NumEdge = NumE;
	this->vArray = new Vertex[Max];
	this->eArray = new Edge[Max];
	loopcounter = 0;
}

bool UndirectedDriver::addVertices(Vertex* vArray, int size) {
	try//EXCEPTION: Array overflow
	{
		if (NumEdge + size >= Max)
		{
			throw size;
		}
		else
		{
			for (int i = 0; i < size; i++) {
				this->vArray[NumVertex] = vArray[i];
				NumVertex++;
			}
			return true;
		}
	}
	catch (...)
	{
		std::cout << "List of vertices has reached max capacity" << std::endl;
		return false;
	}
}


bool UndirectedDriver::addValue(std::string value, Vertex& vertex) {
	for (int i = 0; i < NumVertex; i++) {
		if (vArray[i].getID() == vertex.getID()) {
			vArray[i].setValue(value);
			return true;
		}
	}
	return false;
}

bool UndirectedDriver::searchValueExists(std::string value) {
	for (int i = 0; i < NumVertex; i++) {
		if (vArray[i].getValue() == value) {
			return true;
		}
	}
	return false;
}

bool UndirectedDriver::addEdges(Edge* eArray, int size) {
	try//Exception: Array overflow
	{
		if (NumEdge + size >= Max)
		{
			throw size;
		}
		else
		{
			for (int i = 0; i < size; i++) {
				//search if start and end vertex of edge exists
				if (this->searchValueExists(eArray[i].getStartVertex().getValue()) && this->searchValueExists(eArray[i].getEndVertex().getValue())) {
					this->eArray[NumEdge] = eArray[i];
					NumEdge++;
				}
			}
			return true;
		}
	}
	catch (...)
	{
		std::cout << "List of vertices has reached max capacity" << std::endl;
		return false;
	}
}

bool UndirectedDriver::searchEdgeExists(Edge* edge) {
	for (int i = 0; i < NumEdge; i++) {
		if (eArray[i].getStartVertex().getID() == edge->getStartVertex().getID() && eArray[i].getEndVertex().getID() == edge->getEndVertex().getID() && eArray[i].getWeight() == edge->getWeight()) {
			return true;	//check if first vertex is the same and second is the same
		}
		if (eArray[i].getStartVertex().getID() == edge->getEndVertex().getID() && eArray[i].getEndVertex().getID() == edge->getStartVertex().getID() && eArray[i].getWeight() == edge->getWeight()) {
			return true;	//check if first vertex is the second vertex and vice-versa
		}
	}
	return false;
}


void UndirectedDriver::display() {

	std::cout << "List of Vertex: " << std::endl;
	std::cout << "ID - Value" << std::endl;
	for (int i = 0; i < NumVertex; i++) {
		std::cout << vArray[i].getID() << " = " << vArray[i].getValue() << std::endl;
	}

	std::cout << "List of Edges: " << std::endl;
	for (int i = 0; i < NumEdge; i++) {
		std::cout << eArray[i].getStartVertex().getValue() << " <--" << eArray[i].getWeight() << "--> " << eArray[i].getEndVertex().getValue() << std::endl;
	}
}
void UndirectedDriver::displaypaths() {
	std::cout << "List of Edges: " << std::endl;
	for (int i = 0; i < NumEdge; i++) {
		std::cout << eArray[i].getStartVertex().getValue() << " --" << eArray[i].getWeight() << "--> " << eArray[i].getEndVertex().getValue() << std::endl;
		std::cout << eArray[i].getEndVertex().getValue() << " --" << eArray[i].getWeight() << "--> " << eArray[i].getStartVertex().getValue() << std::endl;
	}

}
void UndirectedDriver::displaypathsfromVertex(Vertex& v) {
	for (int i = 0; i < NumEdge; i++) {
		if (eArray[i].getStartVertex().getValue() == v.getValue() || eArray[i].getEndVertex().getValue() == v.getValue()) {
			std::cout << v.getValue() << " --" << eArray[i].getWeight() << "--> " << eArray[i].getEndVertex().getValue() << std::endl;;
		}
	}
}
void UndirectedDriver::displaypathsfromVertex(std::string value) {
	for (int i = 0; i < NumEdge; i++) {
		if (eArray[i].getStartVertex().getValue() == value) {
			std::cout << value << " --" << eArray[i].getWeight() << "--> " << eArray[i].getEndVertex().getValue() << std::endl;
		}
		if (eArray[i].getEndVertex().getValue() == value) {
			std::cout << value << " --" << eArray[i].getWeight() << "--> " << eArray[i].getStartVertex().getValue() << std::endl;
		}
	}
}



bool UndirectedDriver::searchEdgeExists(std::string weight, std::string v1, std::string v2) {		//function overloading
	for (int i = 0; i < NumEdge; i++) {
		if (eArray[i].getWeight() == weight && eArray[i].getStartVertex().getID() == searchVertex(v1).getID() && eArray[i].getEndVertex().getID() == searchVertex(v2).getID()) {
			return true;
		}
		if (eArray[i].getWeight() == weight && eArray[i].getStartVertex().getID() == searchVertex(v2).getID() && eArray[i].getEndVertex().getID() == searchVertex(v1).getID()) {
			return true;
		}
	}
	return false;
}

Vertex& UndirectedDriver::searchVertex(std::string val) {
	for (int i = 0; i < NumVertex; i++) {
		if (vArray[i].getValue() == val) {
			return vArray[i];
		}
	}
	Vertex a;
	return a;
}

void UndirectedDriver::Vertexpath2(int i, Vertex& v)
{
	try
	{
		if (loopcounter > NumEdge)
		{
			throw loopcounter;
		}
		else
		{
			loopcounter++;

			for (int j = 0; j < NumEdge; j++)
			{
				if (eArray[i].getEndVertex().getValue() == eArray[j].getStartVertex().getValue())
				{
					if (eArray[i].getStartVertex().getValue() != v.getValue()) {
						std::cout << v.getValue() << "<---->";
					}
					std::cout << eArray[i].getStartVertex().getValue() << "<--" << eArray[i].getWeight() << "-->" << eArray[i].getEndVertex().getValue();
					std::cout << "<--" << eArray[j].getWeight() << "-->" << eArray[j].getEndVertex().getValue() << std::endl;
					Vertexpath2(j, v);
				}
			}
		}
	}
	catch (int x)
	{
		return;
	}
}

void UndirectedDriver::Vertexpath(Vertex& v)
{
	std::cout << "List of all possible paths from the starting vertex: " << std::endl;

	for (int i = 0; i < NumEdge; i++)
	{
		if (eArray[i].getStartVertex().getValue() == v.getValue())
		{
			std::cout << v.getValue() << "<--" << eArray[i].getWeight() << "-->" << eArray[i].getEndVertex().getValue() << std::endl;
			Vertexpath2(i, v);

			std::cout << std::endl;
			loopcounter = 0;
		}

	}
}

UndirectedDriver::~UndirectedDriver() {
	delete[] vArray;
	delete[] eArray;
}


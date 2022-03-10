#pragma once
#include <string>

class Vertex
{
private:
	int ID;
	std::string value;//Value will be course sequence codes

public:
	Vertex();//Default constructor
	Vertex(Vertex&);//Copy constructor
	Vertex(int, std::string);//Parameter constructor
	
	void setID(int);
	int getID();

	void setValue(std::string);
	std::string getValue();

	~Vertex();//Destructor
};


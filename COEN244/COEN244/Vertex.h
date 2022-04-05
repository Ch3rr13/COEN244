#pragma once
#include <string>

class Vertex
{
private:
	int ID;
	static int UniqueID;
	std::string value;//Value will be course sequence codes


public:
	Vertex();//Default constructor
	Vertex(Vertex&);//Copy constructor
	Vertex(std::string);//Parameter constructor
	
	void setID(int);
	int getID();

	void setValue(std::string);
	std::string getValue();

	~Vertex();//Destructor
};


#pragma once
class Vertex
{
private:
	int ID;
	int value;//Value will be divisibility of numbers

public:
	Vertex();//Default constructor

	void setID(int);
	int getID();

	void setValue(int);
	int getValue();

	~Vertex();//Destructor
};


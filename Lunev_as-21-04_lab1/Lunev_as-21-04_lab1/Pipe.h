#pragma once
#include <iostream>
class Pipe
{
public:
	Pipe();
	static int MaxID;
	int id;
	std::string Name;
	double Length, Diameter;
	bool InRepair;
	int inputStation;
	int outputStation;
	friend std::ostream& operator << (std::ostream& out, const Pipe& pipe);
	friend std::istream& operator >> (std::istream& in, Pipe& pipe);
	friend void EditPipe(Pipe& pipe);
};

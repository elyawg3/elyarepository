#pragma once
#include <string>
#include <iostream>
class Station
{
public:
	Station();
	static int MaxID;
	int id;
	std::string Name;
	int NumWShop, NumWShopInWork, NumWShopSL;
	double Efficiency;
	int LaunchStop;
	friend std::ostream& operator << (std::ostream& out, const Station& cstation);
	friend std::istream& operator >> (std::istream& in, Station& cstation);
	friend void EditStation(Station& cstation);
};


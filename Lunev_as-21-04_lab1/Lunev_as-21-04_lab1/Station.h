#pragma once
#include <string>
#include <iostream>
class Station
{
public:
	Station();
	std::string Name;
	int NumWShop, NumWShopInWork, NumWShopSL;
	double Efficiency;
	int LaunchStop;
	std::string GetName() const;
};


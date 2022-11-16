#include "Station.h"
using namespace std;
Station::Station()
{

    Name = "Unknown";
    NumWShop = 0;
    NumWShopInWork = 0; 
    NumWShopSL = 0;
    Efficiency = 0;
}

std::string Station::GetName() const
{
    return Name;
}

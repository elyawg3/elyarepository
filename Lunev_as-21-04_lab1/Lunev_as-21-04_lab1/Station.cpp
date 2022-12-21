#include "Station.h"
#include "Utils.h"
using namespace std;

int Station::MaxID = 1;

Station::Station() {
	id = MaxID++;
	Name = "Unknown";
	NumWShop = 0;
	NumWShopInWork = 0;
	NumWShopSL = 0;
}

ostream& operator << (ostream& out, const Station& cstation) {
	if ((cstation.NumWShop > 0) && (cstation.NumWShopInWork > 0) && (cstation.NumWShop >= cstation.NumWShopInWork)) {
		out << "ID:" << cstation.id << endl << "��� ������������� �������: " << cstation.Name << endl << "���������� ����� ������������� �������: " << cstation.NumWShop << endl
			<< "���������� ����� � ������ ������������� ������� : " << cstation.NumWShopInWork << endl << "������������� ������������� �������: " << cstation.Efficiency
			<< "%" << endl;
	}
	else {
		cout << "�� �� �������� ��" << endl;
	}
	return out;
}

istream& operator >> (istream& in, Station& cstation) {
	cout << "������� �������� ������������� �������: ";
	in >> cstation.Name;
	cout << "������� ���������� ����� ������������� �������: ";
	cstation.NumWShop = GetCorrectNumber(0, 10000);
	cout << "������� ���������� ����� � ������: ";
	cstation.NumWShopInWork = GetCorrectNumber(0, cstation.NumWShop);
	cstation.Efficiency = (double(cstation.NumWShopInWork) / double(cstation.NumWShop)) * 100;
	cout << "������������� ������������� �������: " << cstation.Efficiency << "%\n";
	cout << "������������� ������� ���������\n";
	return in;
}

void EditStation(Station& cstation) {
	MenuClear();
	cout << "�������������� �� " << cstation.Name << endl;
	cout << "���������� ����� " << cstation.NumWShop << endl;
	cout << "���������� ����� � ������ " << cstation.NumWShopInWork << endl;
	cout << "1. �������� " << endl << "2. ���������" << endl << "�������� ��������: ";
	switch (GetCorrectNumber(1, 2)) {
	case 1:
	{
		cout << "������� ���������� �����, ������� ���������� ��������: ";
		cstation.NumWShopSL = GetCorrectNumber(0, cstation.NumWShop - cstation.NumWShopInWork);
		cstation.NumWShopInWork += cstation.NumWShopSL;
		break;
	}
	case 2:
	{
		cout << "������� ���������� �����, ������� ���������� ���������: ";
		cstation.NumWShopSL = GetCorrectNumber(0, cstation.NumWShopInWork);
		cstation.NumWShopInWork -= cstation.NumWShopSL;
		break;
	}
	cstation.Efficiency = (double(cstation.NumWShopInWork) / double(cstation.NumWShop)) * 100;
	cout << "����� ������������� ������������� �������: " << cstation.Efficiency << "%" << endl;
	cout << "�������������� ������ �������" << endl;
	}
}
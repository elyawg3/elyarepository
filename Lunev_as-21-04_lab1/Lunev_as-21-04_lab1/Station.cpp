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
		out << "ID:" << cstation.id << endl << "Имя компрессорной станции: " << cstation.Name << endl << "Количество цехов компрессорной станции: " << cstation.NumWShop << endl
			<< "Количество цехов в работе компрессорной станции : " << cstation.NumWShopInWork << endl << "Эффективность компрессорной станции: " << cstation.Efficiency
			<< "%" << endl;
	}
	else {
		cout << "Вы не добавили кс" << endl;
	}
	return out;
}

istream& operator >> (istream& in, Station& cstation) {
	cout << "Введите название компрессорной станции: ";
	in >> cstation.Name;
	cout << "Введите количество цехов компрессорной станции: ";
	cstation.NumWShop = GetCorrectNumber(0, 10000);
	cout << "Введите количество цехов в работе: ";
	cstation.NumWShopInWork = GetCorrectNumber(0, cstation.NumWShop);
	cstation.Efficiency = (double(cstation.NumWShopInWork) / double(cstation.NumWShop)) * 100;
	cout << "Эффективность компрессорной станции: " << cstation.Efficiency << "%\n";
	cout << "Компрессорная станция добавлена\n";
	return in;
}

void EditStation(Station& cstation) {
	MenuClear();
	cout << "Редактирование кс " << cstation.Name << endl;
	cout << "Количество цехов " << cstation.NumWShop << endl;
	cout << "Количество цехов в работе " << cstation.NumWShopInWork << endl;
	cout << "1. Включить " << endl << "2. Отключить" << endl << "Выберите действие: ";
	switch (GetCorrectNumber(1, 2)) {
	case 1:
	{
		cout << "Введите количество цехов, которые необходимо включить: ";
		cstation.NumWShopSL = GetCorrectNumber(0, cstation.NumWShop - cstation.NumWShopInWork);
		cstation.NumWShopInWork += cstation.NumWShopSL;
		break;
	}
	case 2:
	{
		cout << "Введите количество цехов, которые необходимо отключить: ";
		cstation.NumWShopSL = GetCorrectNumber(0, cstation.NumWShopInWork);
		cstation.NumWShopInWork -= cstation.NumWShopSL;
		break;
	}
	cstation.Efficiency = (double(cstation.NumWShopInWork) / double(cstation.NumWShop)) * 100;
	cout << "Новая эффективность компрессорной станции: " << cstation.Efficiency << "%" << endl;
	cout << "Редактирование прошло успешно" << endl;
	}
}
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Pipe.h"
#include "Station.h"


using namespace std;


void menuPrint()
{
	cout << "1. Добавить трубу\n";
	cout << "2. Добавить КС\n";
	cout << "3. Просмотр всех объектов\n";
	cout << "4. Редактировать трубу\n";
	cout << "5. Редактировать КС\n";
	cout << "6. Сохранить\n";
	cout << "7. Загрузить\n";
	cout << "0. Выход\n";
}

void MenuClear() {
	system("cls");
}

template <typename T>
T GetCorrectNumber(T min, T max) {
	T x;
	while ((cin >> x).fail() || x < min || x < max) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите число (от " << min << " до" << max << "):";
	}
	return x;
}

//void createPipe(Pipe& pipe)
//{
//	cout << "Введите длину трубы: ";
//	pipe.Length = GetCorrectNumber(0.0, 10000.0);
//	cout << "Введите диаметр трубы: ";
//	pipe.Diameter = GetCorrectNumber(0.0, 10000.0);
//	cout << "В ремонте(1 - да, 0 - нет): ";
//	cin >> pipe.InRepair;
//	MenuClear();
//	cout << "Труба добавлена\n";
//}


//void createCStation(Station& cstation)
//{
//	cout << "Введите название компрессорной станции: ";
//	//getline(cin, cstation.GetName());
//	cout << cstation.GetName();
//	cout << "Введите количество цехов компрессорной станции: ";
//	cstation.NumWShop = GetCorrectNumber(0, 10000);
//	cout << "Введите количество цехов в работе: ";
//	cstation.NumWShopInWork = GetCorrectNumber(0, cstation.NumWShop);
//	cstation.Efficiency = (double(cstation.NumWShopInWork) / double(cstation.NumWShop)) * 100;
//	MenuClear();
//	cout << "Эффективность компрессорной станции: " << cstation.Efficiency << "%\n";
//	cout << "Компрессорная станция добавлена\n";
//}

void ViewObject(const Pipe& pipe, const Station& cstation) {
	MenuClear();
	if ((pipe.Length > 0) || (pipe.Diameter > 0)) {
		cout << "Длина трубы: " << pipe.Length << endl << "Диаметр трубы: " << pipe.Diameter << endl << "В ремонте: "
			<< pipe.InRepair << endl;
	}
	else {
		cout << "Вы не добавили трубу" << endl;
	}
	if ((cstation.NumWShop > 0) && (cstation.NumWShopInWork > 0) && (cstation.NumWShop >= cstation.NumWShopInWork)) {
		cout << "Имя компрессорной станции: " << cstation.Name << endl << "Количество цехов компрессорной станции: " << cstation.NumWShop << endl
			<< "Количество цехов в работе компрессорной станции : " << cstation.NumWShopInWork << endl << "Эффективность компрессорной станции: " << cstation.Efficiency
			<< "%" << endl;
	}
	else {
		cout << "Вы не добавили кс" << endl;
	}
}



void EditPipe(Pipe& pipe) {
	MenuClear();
	cout << "Редактирование трубы\n";
	cout << "В ремонте: " << pipe.InRepair << endl;
	cout << "В ремонте? (1 - да, 0 - нет)";
	cin >> pipe.InRepair;

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
	}
	case 2:
	{
		cout << "Введите количество цехов, которые необходимо отключить: ";
		cstation.NumWShopSL = GetCorrectNumber(0, cstation.NumWShopInWork);
	}
	cstation.Efficiency = (double(cstation.NumWShopInWork) / double(cstation.NumWShop)) * 100;
	cout << "Новая эффективность компрессорной станции: " << cstation.Efficiency << "%" << endl;
	cout << "Редактирование прошло успешно" << endl;
	}
}
void SaveToFile(string filename, Pipe& pipe, Station& cstation) {
	ofstream fout;
	fout.open(filename + ".txt");
	if (!fout.is_open()) {
		cout << "Ошибка открытия файла" << endl;
	}
	else {
		if (pipe.Diameter > 0) {
			fout << "1" << endl;
			fout << pipe.Length << endl;
			fout << pipe.Diameter << endl;
			fout << pipe.InRepair << endl;
		}
		if (!cstation.Name.empty()) {
			fout << "2" << endl;
			fout << cstation.Name << endl;
			fout << cstation.NumWShop << endl;
			fout << cstation.NumWShopInWork << endl;
			fout << cstation.Efficiency << endl;
		}
	}
	cout << "Данные загружены";
	fout.close();
}

void LoadFromFile(string filename, Pipe& pipe, Station& cstation) {
	ifstream fin;
	int q = 0;
	fin.open(filename + ".txt");
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла" << endl;
	}
	else {
		cout << "Файл открыт!" << endl;
		string str;
		getline(fin, str);
		if (str == "1") {
			fin >> pipe.Length;
			fin >> pipe.Diameter;
			fin >> pipe.InRepair;
			getline(fin, str);
			getline(fin, str);
		}
		if (str == "2") {
			getline(fin, cstation.Name);
			fin >> cstation.NumWShop;
			fin >> cstation.NumWShopInWork;
			fin >> cstation.Efficiency;
		}
	}
	fin.close();
}
ostream&  operator << (ostream& out, Station& cstation) {
	if ((cstation.NumWShop > 0) && (cstation.NumWShopInWork > 0) && (cstation.NumWShop >= cstation.NumWShopInWork)) {
		cout << "Имя компрессорной станции: " << cstation.Name << endl << "Количество цехов компрессорной станции: " << cstation.NumWShop << endl
			<< "Количество цехов в работе компрессорной станции : " << cstation.NumWShopInWork << endl << "Эффективность компрессорной станции: " << cstation.Efficiency
			<< "%" << endl;
	}
	else {
		cout << "Вы не добавили кс" << endl;
	}
}

istream& operator >> (istream& in, Station& cstation) {
	cout << "Введите название компрессорной станции: ";
	in >> cstation.GetName();
	cout << cstation.GetName();
	cout << "Введите количество цехов компрессорной станции: ";
	cstation.NumWShop = GetCorrectNumber(0, 10000);
	cout << "Введите количество цехов в работе: ";
	cstation.NumWShopInWork = GetCorrectNumber(0, cstation.NumWShop);
	cstation.Efficiency = (double(cstation.NumWShopInWork) / double(cstation.NumWShop)) * 100;
	MenuClear();
	cout << "Эффективность компрессорной станции: " << cstation.Efficiency << "%\n";
	cout << "Компрессорная станция добавлена\n";
}

int main()
{
	setlocale(LC_ALL, "Rus");
	vector <Station> cstation;
	vector <Pipe> pipe;
	string FileName;
	for (; ; ) {
		menuPrint();
		cout << "Выберите пункт меню: ";
		switch (GetCorrectNumber(0, 7)) {
		case 1:
			MenuClear();
			createPipe(pipe);
			break;
		case 2:
			MenuClear();
			createCStation(cstation);
			break;
		case 3:
			MenuClear();
			ViewObject(pipe, cstation);
			break;
		case 4:
			MenuClear();
			EditPipe(pipe);
			break;
		case 5:
			MenuClear();
			EditStation(cstation);
			break;
		case 6:
		{
			cout << "Введите название файла: ";
			getline(cin, FileName);
			getline(cin, FileName);
			SaveToFile(FileName, pipe, cstation);
			break;
		}
		case 7:
		{
			cout << "Введите название файла: ";
			getline(cin, FileName);
			getline(cin, FileName);
			LoadFromFile(FileName, pipe, cstation);
			break;
		}
		case 0:
			return 0;
		}
	}
	return 0;
}
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Pipe.h"
#include "Station.h"
#include "Utils.h"
#include "GTS.h"

using namespace std;

void SaveToFile(string filename, vector <Pipe> pipes, vector <Station> cstations) {
	ofstream fout;
	fout.open(filename + ".txt", ios::out);
	if (!fout.is_open()) {
		cout << "Ошибка открытия файла" << endl;
	}
	else {
		for (auto& i : pipes) {
			fout << "p" << endl
				<< i.Name << endl
				<< i.id << endl
				<< i.Length << endl
				<< i.Diameter << endl
				<< i.InRepair << endl;
		}
		for (auto& i : cstations) {
			fout << "s" << endl <<
				i.Name << endl << i.id <<
				endl << i.NumWShop << endl <<
				i.NumWShopInWork << endl <<
				i.Efficiency << endl;
		}
	}
	cout << "Данные загружены" << endl;
	fout.close();
}

void LoadFromFile(string filename, vector <Pipe>& pipes, vector <Station>& stations) {
	ifstream fin;
	fin.open(filename + ".txt", ios::in);
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла" << endl;
	}
	else {
		cout << "Файл открыт!" << endl;
		bool empty = false;
		while (!fin.eof()) {
			char ch;
			empty = true;
			fin >> ch;
			if (ch == 'p') {
				Pipe p;
				fin >> ws;
				getline(fin, p.Name);
				fin >> p.id >> p.Diameter >>  p.Length  >> p.InRepair;
				pipes.push_back(p);
			}
			if (ch == 's') {
				Station cs;
				fin >> ws;
				getline(fin, cs.Name);
				fin >> cs.id >> cs.NumWShop >> cs.NumWShopInWork >> cs.Efficiency;
				stations.push_back(cs);
			}
			ch = 'smth';
		}
		cout << ((empty) ? "Успешно загрузилось" : "Файл пустой") << endl;
		fin.close();
	}
}

Pipe& IndexPipe(vector<Pipe>& p) {
	cout << "Введите индекс трубы:";
	size_t q = 1;
	int index = GetCorrectNumber(q, p.size());
	return p[index - 1];
}

Station& IndexStation(vector<Station>& s) {
	cout << "Введите индекс станции:";
	size_t q = 1;
	int index = GetCorrectNumber(q, s.size());
	return s[index - 1];
}


template<typename T>
void EditPipes(vector <Pipe> pipes, T param) {
	string name;
	bool onezero;
	if (pipes.size() > 0) {
		for (int i : FindPipesByFilter(pipes, CheckByNamep, param))
			cout << pipes[i];
		cout << "1. Редактировать все" << endl;
		cout << "2. Редактировать по выбору" << endl;
		cout << "3. Удалить все" << endl;
		cout << "4. Удалить по выбору" << endl;
		cout << "5. Выход" << endl;
		switch (GetCorrectNumber(1, 5)) {
		case 1: {
			cout << "1. Изменить название" << endl;
			cout << "2. Изменить статус в работе" << endl;
			switch (GetCorrectNumber(1, 2)) {
			case 1: {
				cout << "Введите новое название:";
				cin >> name;
				for (size_t i : pipes.size())
					pipes[i].Name = name;
			}
			case 2: {
				cout << "Введите статус в работе:";
				cin >> onezero;
				for (int i : pipes.size())
					pipes[i].InRepair = onezero;
			}
			}
		}
		case 2: {
			cout << "1. Редактировать по названию" << endl;
			cout << "2. Редактировать по  статусу в работе" << endl;
			switch (GetCorrectNumber(1, 2)) {
			case 1: {
				cout << "Введите название: ";
				cin >> name;
				cout << "Изменить статус в работе: " << endl;
				cin >> onezero;
				for (int i : FindPipesByFilter(pipes, CheckByNamep, name)) {
					pipes[i].InRepair = onezero;
				}
			}
			case 2: {
				cout << "В работе: ";
				cin >> onezero;
				cout << "Изменить название: " << endl;
				cin >> name;
				for (int i : FindPipesByFilter(pipes, CheckByRepair, onezero)) {
					pipes[i].Name = name;
				}
			}
			}
		}
		case 3: {

		}
		case 4: {

		}
		case 5: {
			break;
		}
		}
	}
	else {
		cout << "Ничего не найдено" << endl;
	}
}

void  FindPipes(vector <Pipe> pipes) {
	cout << "1. Поиск по названию" << endl;
	cout << "2. Поиск по признаку в ремонте" << endl;
	cout << "Выберите пункт:";
	switch (GetCorrectNumber(1, 3)) {
	case 1:
	{
		string name;
		cout << "Название: ";
		cin >> name;
		if (pipes.size() > 0) {
			for (int i : FindByFilter(pipes, CheckByName, name))
				cout << pipes[i];
		}
		break;
	}
	case 2:
	{
		bool onezero;
		cout << "В ремонте: ";
		cin >> onezero;
		for (int i : FindByFilter(pipes, CheckByRepair, onezero))
			cout << pipes[i];
		break;
	}
	}
}


int main()
{
	setlocale(LC_ALL, "Rus");
	vector <Station> cstations;
	vector <Pipe> pipes;
	string FileName;
	for (; ; ) {
		menuPrint();
		cout << "Выберите пункт меню: ";
		switch (GetCorrectNumber(0, 11)) {
		case 1: {
			Pipe pipe;
			MenuClear();
			cin >> pipe;
			pipes.push_back(pipe);
			break;
		}
		case 2: {
			Station cstation;
			MenuClear();
			cin >> cstation;
			cstations.push_back(cstation);
			break;
		}
		case 3: {
			MenuClear();
			if (pipes.size() > 0) {
				cout << IndexPipe(pipes);
			}
			else {
				cout << "Труб нет" << endl;
			}
			if (cstations.size() > 0) {
				cout << IndexStation(cstations);
			}
			else {
				cout << "Станций нет" << endl;
			}
			break;
		}
		case 4: {
			MenuClear();
			EditPipe(IndexPipe(pipes));
			break;
		}
		case 5: {
			MenuClear();
			EditStation(IndexStation(cstations));
			break;
		}
		case 6:{
			cout << "Введите название файла: " << endl;
			getline(cin, FileName);
			getline(cin, FileName);
			SaveToFile(FileName, pipes, cstations);
			break;
		}
		case 7:
		{
			cout << "Введите название файла:";
			getline(cin, FileName);
			getline(cin, FileName);
			LoadFromFile(FileName, pipes, cstations);
			break;
		}
		case 8:
		{
			FindPipes(pipes);
			break;
		}
		case 9:
		{
			cout << "1. Поиск по названию" << endl;
			cout << "2. Поиск по проценту незадействованных цехов" << endl;
			switch (GetCorrectNumber(1, 2)) {
			case 1:
			{
				string name;
				cout << "Название: ";
				cin >> name;
				for (int i : FindByFilter(cstations, CheckByName, name))
					cout << cstations[i];
				break;
			}
			case 2:
			{
				double percent;
				cout << "Процент: ";
				cin >> percent;
				for (int i : FindByFilter(cstations, CheckByEfficiency, percent))
					cout << cstations[i];
				break;
			}
			}
			break;

		}
		case 10:
		{

		}
		case 11:
		{

		}
		case 0:
			return 0;
		}
	}
}
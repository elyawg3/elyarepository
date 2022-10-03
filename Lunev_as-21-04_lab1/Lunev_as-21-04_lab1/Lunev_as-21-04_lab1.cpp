#include <iostream>
#include <string>
#include <fstream>


using namespace std;


struct Pipe {
	float Length, Diameter;
	bool InRepair;
};

struct Station {
	string Name;
	int NumWShop, NumWShopInWork, NumWShopSL;
	double Efficiency;
	int LaunchStop;
};

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

void CinClear() {
	cin.clear();
	cin.ignore(312312, '\n');
}

void createPipe(struct Pipe& pipe)
{
	cout << "Введите длину трубы: ";
	cin >> pipe.Length;
	for (;;) {
		if (cin.fail()) {
			cout << "Ошибка! Данные некорректны\n";
			CinClear();
			cout << "Введите длину трубы: ";
			cin >> pipe.Length;
		}
		else {
			if (pipe.Length <= 0) {
				cout << "Длина трубы должна быть больше 0!\n";
				cout << "Введите длину трубы: ";
				cin >> pipe.Length;
			}
		}
		if ((pipe.Length > 0) && (!cin.fail())) {
			break;
		}
	}
	cout << "Введите диаметр трубы: ";
	cin >> pipe.Diameter;
	for (;;) {
		if (cin.fail()) {
			cout << "Ошибка! Данные некорректны\n";
			CinClear();
			cout << "Введите диаметр трубы: ";
			cin >> pipe.Diameter;
		}
		else {
			if (pipe.Diameter <= 0) {
				cout << "Диаметр трубы должен быть больше 0!\n";
				cout << "Введите диаметр трубы: ";
				cin >> pipe.Diameter;
			}
		}
		if ((pipe.Diameter > 0) && (!cin.fail())) {
			break;
		}
	}
	cout << "В ремонте(1 - да, 0 - нет): ";
	cin >> pipe.InRepair;
	for (;;) {
		if (cin.fail()) {
			cout << "Ошибка! Данные некорректны\n";
			CinClear();
			cout << "В ремонте(1 - да, 0 - нет): ";
			cin >> pipe.InRepair;
		}
		else {
			break;
		}
	}
	MenuClear();
	cout << "Труба добавлена\n";
}


void createCStation(struct Station& cstation)
{
	cout << "Введите название компрессорной станции: ";
	getline(cin, cstation.Name);
	for (;;) {
		getline(cin, cstation.Name);
		if (cin.fail()) {
			cout << "Ошибка! Данные некорректны\n";
			CinClear();
			cout << "Введите название компрессорной станции: ";
			getline(cin, cstation.Name);
		}
		else {
			break;
		}

	}
	cout << "Введите количество цехов компрессорной станции: ";
	cin >> cstation.NumWShop;
	for (;;) {
		if (cin.fail()) {
			cout << "Ошибка! Данные некорректны\n";
			CinClear();
			cout << "Введите количество цехов компрессорной станции: ";
			cin >> cstation.NumWShop;
		}
		else {
			if (cstation.NumWShop >= 0) {
				break;
			}
			else {
				cout << "Количество цехов должно быть положительно!" << endl;
				CinClear();
				cout << "Введите количество цехов компрессорной станции: ";
				cin >> cstation.NumWShop;
			}
		}
	}
	cout << "Введите количество цехов в работе: ";
	cin >> cstation.NumWShopInWork;
	for (;;) {
		if (cin.fail()) {
			cout << "Ошибка! Данные некорректны\n";
			CinClear();
			cout << "Введите количество цехов в работе: ";
			cin >> cstation.NumWShopInWork;
		}
		else {
			if (cstation.NumWShopInWork >= 0) {
				if (cstation.NumWShop >= cstation.NumWShopInWork) {
					break;
				}
				else {
					cout << "Количество цехов в работе должно быть меньше или равно количеству цехов в целом!" << endl;
					CinClear();
					cout << "Введите количество цехов в работе компрессорной станции: ";
					cin >> cstation.NumWShopInWork;
				}
			}
			else {
				cout << "Количество цехов в работе должно быть положительно!" << endl;
				CinClear();
				cout << "Введите количество цехов в работе компрессорной станции: ";
				cin >> cstation.NumWShopInWork;
			}

		}
	}
	cstation.Efficiency = (double(cstation.NumWShopInWork) / double(cstation.NumWShop)) * 100;
	MenuClear();
	cout << "Эффективность компрессорной станции: " << cstation.Efficiency << "%\n";
	cout << "Компрессорная станция добавлена\n";
}

void ViewObject(struct  Pipe& const pipe, struct  Station& const cstation) {
	MenuClear();
	int NumViewMenu;
	for (;;) {
		cout << "1. Посмотреть трубу\n";
		cout << "2. Посмотреть компрессорную станцию\n";
		cout << "Выберите пункт: ";
		cin >> NumViewMenu;
		switch (NumViewMenu)
		{
		case 1:
			if ((pipe.Length > 0) || (pipe.Diameter > 0)) {
				MenuClear();
				cout << "Длина трубы: " << pipe.Length << endl << "Диаметр трубы: " << pipe.Diameter << endl << "В ремонте: "
					<< pipe.InRepair << endl;
				return;
			}
			else {
				MenuClear();
				cout << "Вы не добавили трубу" << endl;
			}
			break;
		case 2:
			if ((cstation.NumWShop > 0) && (cstation.NumWShopInWork > 0) && (cstation.NumWShop >= cstation.NumWShopInWork)) {
				MenuClear();
				cout << "Имя компрессорной станции: " << cstation.Name << endl << "Количество цехов компрессорной станции: " << cstation.NumWShop << endl
					<< "Количество цехов в работе компрессорной станции : " << cstation.NumWShopInWork << endl << "Эффективность компрессорной станции: " << cstation.Efficiency
					<< "%" << endl;
				return;
			}
			else {
				MenuClear();
				cout << "Вы не добавили кс" << endl;
			}
			break;
		default:
			MenuClear();
			cout << "Число некорректно" << endl;
			CinClear();
			break;
		}
	}

}

void EditPipe(struct Pipe& pipe) {
	MenuClear();
	for (;;) {
		if ((pipe.Length > 0) && (pipe.Diameter > 0)) {
			cout << "Редактирование трубы\n";
			cout << "В ремонте: " << pipe.InRepair << endl;
			cout << "В ремонте? (1 - да, 0 - нет)";
			cin >> pipe.InRepair;
			for (;;) {
				if (cin.fail()) {
					cout << "Ошибка! Данные некорректны\n";
					CinClear();
					cout << "В ремонте(1 - да, 0 - нет): ";
					cin >> pipe.InRepair;
				}
				else {
					break;
				}
			}
			if ((pipe.Length > 0) && (pipe.Diameter > 0)) {
				MenuClear();
				cout << "Редактирование прошло успешно" << endl;
				return;
			}
			else {
				cout << "Ошибка" << endl;
			}
		}
		else {
			cout << "Труба не добавлена" << endl;
			break;
		}
	}
}

void EditStation(struct Station& cstation) {
	MenuClear();
	for (;;) {
		if ((cstation.NumWShop > 0) && (cstation.NumWShopInWork >=  0) && (cstation.NumWShop >= cstation.NumWShopInWork) && (!cstation.Name.empty())) {
			cout << "Редактирование кс " << cstation.Name << endl ;
			cout << "Количество цехов " << cstation.NumWShop << endl;
			cout << "Количество цехов в работе " << cstation.NumWShopInWork << endl;
			cout << "1. Включить " << endl << "2. Отключить" << endl << "Выберите действие: ";
			cin >> cstation.LaunchStop;
			for (;;) {
				if (cin.fail() || ((cstation.LaunchStop != 1) && (cstation.LaunchStop != 2))){
					cout << "Ошибка! Данные некорректны\n";
					CinClear();
					cout << "1. Включить " << endl << "2. Отключить" << endl << "Выберите действие: ";
					cin >> cstation.LaunchStop;
				}
				else {
					switch (cstation.LaunchStop) {
					case 1:
					{
						cout << "Введите количество цехов, которые необходимо включить: ";
						cin >> cstation.NumWShopSL;
						for (;;) {
							if ((cstation.NumWShopInWork + cstation.NumWShopSL <= cstation.NumWShop) && (cstation.NumWShopSL >= 0)) {
								cstation.NumWShopInWork += cstation.NumWShopSL;
								cout << "Количество цехов в работе: " << cstation.NumWShopInWork << endl;
								return;
							}
							else {
								cout << "Вы включили недопустимое число цехов" << endl;
								CinClear();
								cout << "Введите количество цехов, которые необходимо включить: ";
								cin >> cstation.NumWShopSL;
							}
						}
						break;
					}
					case 2:
					{
						cout << "Введите количество цехов, которые необходимо отключить: ";
						cin >> cstation.NumWShopSL;
						for (;;) {
							if ((cstation.NumWShopInWork - cstation.NumWShopSL >= 0) && (cstation.NumWShopSL >= 0)) {
								cstation.NumWShopInWork -= cstation.NumWShopSL;
								cout << "Количество цехов в работе: " << cstation.NumWShopInWork << endl;
								return;
							}
							else {
								cout << "Вы отключили недопустимое число цехов" << endl;
								CinClear();
								cout << "Введите количество цехов, которые необходимо отключить: ";
								cin >> cstation.NumWShopSL;
							}
						}
						break;
					}
					}
				
				}
			}
			cstation.Efficiency = (double(cstation.NumWShopInWork) / double(cstation.NumWShop)) * 100;
			cout << "Новая эффективность компрессорной станции: " << cstation.Efficiency << "%" << endl;
			if ((cstation.NumWShop > 0) && (cstation.NumWShopInWork > 0) && (cstation.NumWShop >= cstation.NumWShopInWork) && (!cstation.Name.empty())) {
				cout << "Редактирование прошло успешно" << endl;
				return;
			}
			else {
				cout << "Ошибка" << endl;
				break;
			}

		}
		else {
			cout << "КС не добавлена" << endl;
			break;
		}
	}
}

void SaveToFile(string filename, struct Pipe& pipe, struct Station& cstation) {
	ofstream fout;
	fout.open(filename + ".txt");
	if (!fout.is_open()) {
		cout << "Ошибка открытия файла" << endl;
	}
	else {
		if ((pipe.Diameter > 0) && (!cstation.Name.empty())) {
			fout << "Информация о трубе" << endl;
			fout << "Длина трубы: " << pipe.Length << endl;
			fout << "Диаметр трубы: " << pipe.Diameter << endl;
			if (pipe.InRepair == 1) {
				fout << "В ремонте: да" << endl;
			}
			else {
				fout << "В ремонте: нет" << endl;
			}
			fout << endl;
			fout << "Информация о кс" << endl;
			fout << "Имя кс: " << cstation.Name << endl;
			fout << "Количество цехов кс: " << cstation.NumWShop << endl;
			fout << "Количество цехов в работе кс: " << cstation.NumWShopInWork << endl;
			fout << "Эффективность кс: " << cstation.Efficiency << "%" << endl;
		}
		else {
			cout << "Введены не все данные!" << endl;
		}

	}
	fout.close();
}

void LoadFromFile(string filename) {
	ifstream fin;
	fin.open(filename + ".txt");
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла" << endl;
	}
	else {
		cout << "Файл открыт!" << endl;
		string str;
		while (!fin.eof()) {
			str = "";
			getline(fin, str);
			cout << str << endl;
		}
	}
	fin.close();
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Station cstation;
	Pipe pipe;
	int NumMenu;
	for (; ; ) {
		menuPrint();
		cout << "Выберите пункт меню: ";
		cin >> NumMenu;
		if (cin.fail()) {
			cout << "Ошибка\n";
			CinClear();
		}
		else {
			if ((NumMenu >= 0) && (NumMenu <= 7)) {
				switch (NumMenu) {
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
					string FileName;
					cin >> FileName;
					SaveToFile(FileName, pipe, cstation);
					break;
				}
				case 7:
				{
					cout << "Введите название файла: ";
					string FileName;
					cin >> FileName;
					LoadFromFile(FileName);
					break;
				}
				case 0:
					return 0;
				}
			}
			else {
				MenuClear();
				cout << "Ошибка\n";
				CinClear();

			}
		}
	}
	return 0;
}




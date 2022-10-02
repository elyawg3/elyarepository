#include <iostream>
#include <string>


using namespace std;

struct Pipe {
	float Length, Diameter;
	bool InRepair;
};

struct Station {
	string Name;
	int NumWShop, NumWShopInWork;
	double Efficiency;
	bool Launch;
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


void createPipe(struct Pipe& pipe)
{
	cout << "Введите длину трубы: ";
	cin >> pipe.Length;
	for (;;) {
		if (cin.fail()) {
			cout << "Ошибка! Данные некорректны\n";
			cin.clear();
			cin.ignore(312312, '\n');
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
			cin.clear();
			cin.ignore(312312, '\n');
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
			cin.clear();
			cin.ignore(312312, '\n');
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
			cin.clear();
			cin.ignore(312312, '\n');
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
			cin.clear();
			cin.ignore(312312, '\n');
			cout << "Введите количество цехов компрессорной станции: ";
			cin >> cstation.NumWShop;
		}
		else {
			if (cstation.NumWShop >= 0) {
				break;
			}
			else {
				cout << "Количество цехов должно быть положительно!" << endl;
				cin.clear();
				cin.ignore(312312, '\n');
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
			cin.clear();
			cin.ignore(312312, '\n');
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
					cin.clear();
					cin.ignore(312312, '\n');
					cout << "Введите количество цехов в работе компрессорной станции: ";
					cin >> cstation.NumWShopInWork;
				}
			}
			else {
				cout << "Количество цехов в работе должно быть положительно!" << endl;
				cin.clear();
				cin.ignore(312312, '\n');
				cout << "Введите количество цехов в работе компрессорной станции: ";
				cin >> cstation.NumWShopInWork;
			}

		}
	}
	cout << "Запустить станцию(1 - да, 0 - нет): ";
	cin >> cstation.Launch;
	for (;;) {
		if (cin.fail()) {
			cout << "Ошибка! Данные некорректны\n";
			cin.clear();
			cin.ignore(312312, '\n');
			cout << "Запустить станцию(1 - да, 0 - нет): ";
			cin >> cstation.Launch;
		}
		else {
			if ((cstation.Launch != 1) && (cstation.Launch != 0)) {
				cout << "Ошибка! Данные некорректны\n";
				cin.clear();
				cin.ignore(312312, '\n');
				cout << "Запустить станцию(1 - да, 0 - нет): ";
				cin >> cstation.Launch;
			}
			else {
				break;
			}
		}
	}
	cstation.Efficiency = (double(cstation.NumWShopInWork) / double(cstation.NumWShop)) * 100;
	MenuClear();
	cout << "Эффективность компрессорной станции: " << cstation.Efficiency << "%\n";
	cout << "Компрессорная станция добавлена\n";
}

void ViewObject(struct Pipe& pipe, struct Station& cstation) {
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
				if (cstation.Launch == 0) {
					cout << "Кс остановлена" << endl;
				}
				if (cstation.Launch == 1) {
					cout << "Кс запущена" << endl;
				}
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
			cin.clear();
			cin.ignore(312312, '\n');
			break;
		}
	}

}

void EditPipe(struct Pipe& pipe) {
	MenuClear();
	for (;;) {
		if ((pipe.Length > 0) && (pipe.Diameter > 0)) {
			cout << "Редактирование трубы\n";
			cout << "Длина трубы: " << pipe.Length << endl;
			cout << "Введите новую длину трубы: ";
			cin >> pipe.Length;
			for (;;) {
				if (cin.fail()) {
					cout << "Ошибка! Данные некорректны\n";
					cin.clear();
					cin.ignore(312312, '\n');
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
			cout << "Диаметр трубы: " << pipe.Diameter << endl;
			cout << "Введите новый диаметр трубы: ";
			cin >> pipe.Diameter;
			for (;;) {
				if (cin.fail()) {
					cout << "Ошибка! Данные некорректны\n";
					cin.clear();
					cin.ignore(312312, '\n');
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
			cout << "В ремонте: " << pipe.InRepair << endl;
			cout << "В ремонте? (1 - да, 0 - нет)";
			cin >> pipe.InRepair;
			for (;;) {
				if (cin.fail()) {
					cout << "Ошибка! Данные некорректны\n";
					cin.clear();
					cin.ignore(312312, '\n');
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
		if ((cstation.NumWShop > 0) && (cstation.NumWShopInWork > 0) && (cstation.NumWShop >= cstation.NumWShopInWork) && (!cstation.Name.empty())) {
			cout << "Редактирование кс\n";
			cout << "Имя компрессорной станции: " << cstation.Name << endl;
			cout << "Введите новое имя кс:";
			getline(cin, cstation.Name);
			for (;;) {
				getline(cin, cstation.Name);
				if (cin.fail()) {
					cout << "Ошибка! Данные некорректны\n";
					cin.clear();
					cin.ignore(312312, '\n');
					cout << "Введите название компрессорной станции: ";
					getline(cin, cstation.Name);
				}
				else {
					break;
				}
			}
			cout << "Количество цехов компрессорной станции: " << cstation.NumWShop << endl;
			cout << "Новое количество цехов компрессорной станции: ";
			cin >> cstation.NumWShop;
			for (;;) {
				if (cin.fail()) {
					cout << "Ошибка! Данные некорректны\n";
					cin.clear();
					cin.ignore(312312, '\n');
					cout << "Введите количество цехов компрессорной станции: ";
					cin >> cstation.NumWShop;
				}
				else {
					if (cstation.NumWShop >= 0) {
						break;
					}
					else {
						cout << "Количество цехов должно быть положительно!" << endl;
						cin.clear();
						cin.ignore(312312, '\n');
						cout << "Введите количество цехов компрессорной станции: ";
						cin >> cstation.NumWShop;
					}
				}
			}
			cout << "Количество цехов в работе компрессорной станции : " << cstation.NumWShopInWork << endl;
			cout << "Новое количество цехов в работе компрессорной станции : ";
			cin >> cstation.NumWShopInWork;
			for (;;) {
				if (cin.fail()) {
					cout << "Ошибка! Данные некорректны\n";
					cin.clear();
					cin.ignore(312312, '\n');
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
							cin.clear();
							cin.ignore(312312, '\n');
							cout << "Введите количество цехов в работе компрессорной станции: ";
							cin >> cstation.NumWShopInWork;
						}
					}
					else {
						cout << "Количество цехов в работе должно быть положительно!" << endl;
						cin.clear();
						cin.ignore(312312, '\n');
						cout << "Введите количество цехов в работе компрессорной станции: ";
						cin >> cstation.NumWShopInWork;
					}

				}
			}
			cstation.Efficiency = (double(cstation.NumWShopInWork) / double(cstation.NumWShop)) * 100;
			cout << "Новая эффективность компрессорной станции: " << cstation.Efficiency << "%" << endl;
			if (cstation.Launch == 0) {
				cout << "Кс остановлена" << endl;
				cout << "Запустить станцию(1 - да, 0 - нет): ";
				cin >> cstation.Launch;
				for (;;) {
					if (cin.fail()) {
						cout << "Ошибка! Данные некорректны\n";
						cin.clear();
						cin.ignore(312312, '\n');
						cout << "Запустить станцию(1 - да, 0 - нет): ";
						cin >> cstation.Launch;
					}
					else {
						if ((cstation.Launch != 1) && (cstation.Launch != 0)) {
							cout << "Ошибка! Данные некорректны\n";
							cin.clear();
							cin.ignore(312312, '\n');
							cout << "Запустить станцию(1 - да, 0 - нет): ";
							cin >> cstation.Launch;
						}
						else {
							break;
						}
					}
				}
			}
			else {
				cout << "Кс запущена" << endl;
				cout << "Оставить станцию запущенной(1 - да, 0 - нет): ";
				cin >> cstation.Launch;
				for (;;) {
					if (cin.fail()) {
						cout << "Ошибка! Данные некорректны\n";
						cin.clear();
						cin.ignore(312312, '\n');
						cout << "Запустить станцию(1 - да, 0 - нет): ";
						cin >> cstation.Launch;
					}
					else {
						if ((cstation.Launch != 1) && (cstation.Launch != 0)) {
							cout << "Ошибка! Данные некорректны\n";
							cin.clear();
							cin.ignore(312312, '\n');
							cout << "Запустить станцию(1 - да, 0 - нет): ";
							cin >> cstation.Launch;
						}
						else {
							break;
						}
					}
				}
			}
			if ((cstation.NumWShop > 0) && (cstation.NumWShopInWork > 0) && (cstation.NumWShop >= cstation.NumWShopInWork) && (!cstation.Name.empty())) {
				MenuClear();
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

int main()
{
	setlocale(LC_ALL, "Rus");
	Station cstation;
	Pipe pipe;
	pipe.Length = 0;
	int NumMenu;
	for (; ; ) {
		menuPrint();
		cout << "Выберите пункт меню: ";
		cin >> NumMenu;
		if (cin.fail()) {
			cout << "Ошибка\n";
			cin.clear();
			cin.ignore();
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
					break;
				case 7:
					break;
				case 0:
					return 0;
				}
			}
			else {
				MenuClear();
				cout << "Ошибка\n";
				cin.clear();
				cin.ignore();

			}
		}
	}
	return 0;
}




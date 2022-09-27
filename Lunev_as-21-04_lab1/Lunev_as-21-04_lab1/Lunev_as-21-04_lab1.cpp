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

void IntInputError(string entervalue, int value) {
	for (;;) {
		if (cin.fail()) {
			cout << "Ошибка! Данные некорректны\n";
			cin.clear();
			cin.ignore(312312, '\n');
			cout << entervalue;
			cin >> value;
		}
		if (!cin.fail()) {
			return;
		}
	}
}

void StrInputError(string entervalue, string value) {
	for (;;) {
		if (cin.fail()) {
			cout << "Ошибка! Данные некорректны\n";
			cin.clear();
			cin.ignore(312312, '\n');
			cout << entervalue;
			cin >> value;
		}
		if (!cin.fail()) {
			return;
		}
	}
}

//void BoolInputError(string entervalue, bool value) {
//	if (cin.fail()) {
//		cout << "Ошибка! Данные некорректны\n";
//		cin.clear();
//		cin.ignore(312312, '\n');
//		cout << entervalue;
//		cin >> value;
//	}
//}

void PropertiesError(int value, string entervalue, string valuecomment) {
	cout << entervalue;
	cin >> value;
	for (;;) {
		IntInputError(entervalue, value);
		if (value < 0) {
			cout << valuecomment;
			cout << entervalue;
			cin >> value;
		}
		if ((value >= 0) && (!cin.fail())) {
			return;
		}
	}
}

void createPipe(struct Pipe pipe)
{
	PropertiesError(pipe.Length, "Введите длину трубы: ", "Длина трубы должна быть больше 0!\n");
	PropertiesError(pipe.Diameter, "Введите диаметр трубы: ", "Диаметр трубы должен быть больше 0!\n");
	cout << "В ремонте(1 - да, 0 - нет): ";
	cin >> pipe.InRepair;
	MenuClear();
	cout << "Труба добавлена\n";
}


void createCStation(struct Station cstation)
{
	for (;;) {
		cout << "Введите название компрессорной станции: ";
		cin >> cstation.Name;
		StrInputError("Введите название компрессорной станции: ", cstation.Name);
		cout << "Введите количество цехов компрессорной станции: ";
		cin >> cstation.NumWShop;
		IntInputError("Введите количество цехов компрессорной станции: ", cstation.NumWShop);
		cout << "Введите количество цехов в работе: ";
		cin >> cstation.NumWShopInWork;
		IntInputError("Введите количество цехов в работе: ", cstation.NumWShopInWork);
		if ((cstation.NumWShop >= cstation.NumWShopInWork) && (cstation.NumWShop > 0) && (cstation.NumWShopInWork > 0) &&
			(!cstation.Name.empty())) {
			cstation.Efficiency = (double(cstation.NumWShopInWork) / double(cstation.NumWShop)) * 100;
			MenuClear();
			cout << "Эффективность компрессорной станции: " << cstation.Efficiency << "%\n";
			cout << "Компрессорная станция добавлена\n";
			return;
		}
		else {
			MenuClear();
			cout << "Данные некорректны\n";
		}
	}



}


int main()
{
	Station cstation{};
	Pipe pipe{};
	setlocale(LC_ALL, "Rus");
	int num_menu;
	for (; ; ) {
		menuPrint();
		cout << "Выберите пункт меню: ";
		cin >> num_menu;
		if (cin.fail()) {
			cout << "Ошибка\n";
			cin.clear();
			cin.ignore();
		}
		else {
			switch (num_menu) {
			case 1:
				createPipe(pipe);
				break;
			case 2:
				createCStation(cstation);
				break;
			case 3:

				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 0:
				break;
			default:
				break;
			}
		}
	}
	return 0;
}




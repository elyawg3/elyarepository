#include <iostream>


using namespace std;

void menu_Print()
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


int main()
{
	setlocale(LC_ALL, "Rus");
	int num_menu;
	menu_Print();
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
			break;
		case 2:
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


		}
	}
	return 0;
}




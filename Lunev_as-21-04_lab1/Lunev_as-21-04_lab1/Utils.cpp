#include "Utils.h"
#include <vector>

void menuPrint()
{
	cout << "1. Добавить трубу\n" << "2. Добавить КС\n"<< "3. Просмотр всех объектов\n" << "4. Редактировать трубу\n"
	<< "5. Редактировать КС\n"<< "6. Сохранить\n" << "7. Загрузить\n" << "8. Поиск труб по заданному фильтру\n"
	<< "9. Поиск станций по заданному фильтру\n" << "10. Добавить газотранспортную сеть\n" << "11. Топологическая сортировка\n" << "0. Выход\n";
}

void MenuClear() {
	cin.clear();
	cin.ignore(1024, '\n');
}

bool CheckByEfficiency(const Station& cs, double param)
{
	return (100.0 - cs.Efficiency) == param;
}

bool CheckByDiametr(const Pipe& pipe, double param) {
	return param == pipe.Diameter;
}	

bool CheckByRepair(const Pipe& pipe, bool param)
{
	return pipe.InRepair == param;
}


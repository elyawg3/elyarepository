#include "Pipe.h"
#include "Utils.h"

using namespace std;

int Pipe::MaxID = 1;

Pipe::Pipe() {
	Name = "Unknown";
	id = MaxID++;
	Diameter = 0;
	Length = 0;
	InRepair = 0;
	inputStation = 0;
	outputStation = 0;
}

ostream& operator << (ostream& out, const Pipe& pipe) {
	if ((pipe.Length > 0) || (pipe.Diameter > 0)) {
		out << "ID: " << pipe.id << endl << "Название трубы:" << pipe.Name << endl << "Длина трубы: " << pipe.Length << endl << "Диаметр трубы: " << pipe.Diameter << endl << "В ремонте: "
			<< pipe.InRepair << endl;
	}
	else {
		out << "Вы не добавили трубу" << endl;
	}
	return out;
}

istream& operator >> (istream& in, Pipe& pipe) {
	cout << "Введите название трубы:";
	in >> pipe.Name;
	cout << "Введите длину трубы: ";
	pipe.Length = GetCorrectNumber(0.0, 10000.0);
	cout << "Введите диаметр трубы: ";
	pipe.Diameter = GetCorrectNumber(0.0, 10000.0);
	cout << "В ремонте(1 - да, 0 - нет): ";
	pipe.InRepair = GetCorrectNumber(0, 1);
	cout << "Труба добавлена\n";
	return in;
}

void EditPipe(Pipe& pipe) {
	MenuClear();
	cout << "Редактирование трубы\n";
	cout << "В ремонте: " << pipe.InRepair << endl;
	cout << "В ремонте? (1 - да, 0 - нет)";
	cin >> pipe.InRepair;

}

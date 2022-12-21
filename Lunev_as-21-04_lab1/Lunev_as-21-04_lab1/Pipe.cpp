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
		out << "ID: " << pipe.id << endl << "�������� �����:" << pipe.Name << endl << "����� �����: " << pipe.Length << endl << "������� �����: " << pipe.Diameter << endl << "� �������: "
			<< pipe.InRepair << endl;
	}
	else {
		out << "�� �� �������� �����" << endl;
	}
	return out;
}

istream& operator >> (istream& in, Pipe& pipe) {
	cout << "������� �������� �����:";
	in >> pipe.Name;
	cout << "������� ����� �����: ";
	pipe.Length = GetCorrectNumber(0.0, 10000.0);
	cout << "������� ������� �����: ";
	pipe.Diameter = GetCorrectNumber(0.0, 10000.0);
	cout << "� �������(1 - ��, 0 - ���): ";
	pipe.InRepair = GetCorrectNumber(0, 1);
	cout << "����� ���������\n";
	return in;
}

void EditPipe(Pipe& pipe) {
	MenuClear();
	cout << "�������������� �����\n";
	cout << "� �������: " << pipe.InRepair << endl;
	cout << "� �������? (1 - ��, 0 - ���)";
	cin >> pipe.InRepair;

}

#include "Utils.h"
#include <vector>

void menuPrint()
{
	cout << "1. �������� �����\n" << "2. �������� ��\n"<< "3. �������� ���� ��������\n" << "4. ������������� �����\n"
	<< "5. ������������� ��\n"<< "6. ���������\n" << "7. ���������\n" << "8. ����� ���� �� ��������� �������\n"
	<< "9. ����� ������� �� ��������� �������\n" << "10. �������� ���������������� ����\n" << "11. �������������� ����������\n" << "0. �����\n";
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


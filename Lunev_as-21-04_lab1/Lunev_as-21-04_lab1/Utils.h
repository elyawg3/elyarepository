#pragma once
#include <iostream>
#include "Pipe.h"
#include "Station.h"
using namespace std;
template <typename T>
T GetCorrectNumber(T min, T max) {
	T x;
	while ((std::cin >> x).fail() || x < min || x > max) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "¬ведите число (от " << min << " до " << max << "):";
	}
	return x;
}


//template <typename T1, typename T2>
//using Filter = bool(*)(const T1& obj, T2 parametr);
//template <typename T1, typename T2>
//int findByFilter(vector <T1>& objects, Filter<T1, T2> f, T2 parametr) {
//	int result;
//	for (auto& it : objects)
//	{
//		if (f(it.second, parametr))
//		{
//			result.emplace(it.first);
//		}
//	}
//	return result;
//}

template<typename T1, typename T2>
using Filter = bool(*)(const T1& obj, T2 param);
template<typename T1, typename T2>
vector<int> FindByFilter(const vector<T1>& obj, Filter<T1, T2> f, T2 param) {
	vector <int> ans;
	int i = 0;
	for (auto& s : obj) {
		if (f(s, param)) {
			ans.push_back(i);
			i++;
		}
	}
	return ans;
}

void menuPrint();
void MenuClear();

template <typename T>
bool CheckByName(const T& obj, string param)
{
	return T.Name == param;
}
bool CheckByRepair(const Pipe& pipe, bool param);
bool CheckByDiametr(const Pipe& pipe, double parametr);
bool CheckByEfficiency(const Station& cs, double param);
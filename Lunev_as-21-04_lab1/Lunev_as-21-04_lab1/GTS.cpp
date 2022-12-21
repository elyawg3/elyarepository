#include "GTS.h"

GTS::GTS() {

};

void GTS::addGTS(vector <Pipe>& pipes, vector <Station>& stations) {
	int idStationIn = GetCorrectNumber(1, Station::MaxID);
	int idStationOut = GetCorrectNumber(1, Station::MaxID);
	if ((idStationIn == idStationOut)) {
		cout << "ERROR" << endl;
		return;
	}
	double d;
	cout << "Введите диаметр (1 - 500; 2 - 700; 3 - 1400)" << endl;
	switch (GetCorrectNumber(1, 3))
	{
	case 1:
	{
		d = 500.0;
		break;
	}
	case 2:
	{
		d = 700.0;
		break;
	}
	case 3:
	{
		d = 1400.0;
		break;
	}
	}
	int foundPipes = FindByFilter(pipes,CheckByDiametr, d);
	int q = 0;

	for (int i = 0; i < foundPipes; i++) {
		if (pipes[i].inputStation == 0) {
			pipes[i].inputStation = idStationIn;
			pipes[i].outputStation = idStationOut;
			q = i;
			IncludeToGraph(pipes[q]);
			break;
		}
	}

	if (q == 0) {
		Pipe p;
		cin >> p;
		p.Diameter = d;
		q = p.id;
		pipes[q].inputStation = idStationIn;
		pipes[q].outputStation = idStationOut;
		IncludeToGraph(pipes[q]);
	}
}


void GTS::IncludeToGraph(Pipe p) {
	int in = p.inputStation;
	int out = p.outputStation;
	if (graph.find(in)) {
		int qw;
		qw.emplace(out);
		graph.emplace(in, qw);
	}
	else {
		graph[in].emplace(out);
	}
}



void GTS::dfs(int v) {
	used[v] = true;
	for (int i : graph[v]) {
		if (!used[i])
			dfs(i);
	}
	ans.push_back(v);
}


void GTS::topological_sort() {
	int j = 0;
	for (auto& it : graph) {
		idks.emplace(it.first);
		for (int i : it.second) {
			if (!idks.contains(i)) idks.emplace(i);
		}
	}

	for (int i : idks) {
		used.emplace(i, 0);
		j++;
	}

	ans.clear();


	for (int i : idks) {
		if (!used[i]) dfs(i);
	}

	reverse(ans.begin(), ans.end());
	used.clear();
	for (int i : ans) {
		cout << i << " -> ";
	}
	cout << endl;
}
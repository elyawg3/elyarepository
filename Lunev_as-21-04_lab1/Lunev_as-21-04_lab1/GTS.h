#pragma once
#include "Pipe.h"
#include "Station.h"
#include "Utils.h"
#include <vector>
class GTS
{
public:
	GTS();
	int id;
	static int MAXid;
	vector<int> graph;
	void addGTS(vector <Pipe>& pipes, vector <Station>& stations);
	void IncludeToGraph(Pipe p);
	vector<int> tsort();
	void dfs(int v);
	void topological_sort();
};


#pragma once
#include <list>
#include <vector>
#include <iostream>
using namespace std;
class graph
{
public:
private:
	int v, e;
	vector < list<int> > adjacencyList;
public:
	graph();
	graph(int v, int e);
	void init();
	void dfs(int source);
	void dfsRec(int source,vector<bool>  &visited);
	void bfs(int source);
	bool isAConnectedGraph();
};


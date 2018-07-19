#include "stdafx.h"
#include "graph.h"
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
graph::graph()
{
	v = 0;e = 0;
}
graph::graph(int v, int e)
{
	this->v = v;
	this->e = e;
	adjacencyList = vector<list<int>>(v);
}
void graph::init()
{
	adjacencyList[0].push_back(1);
	adjacencyList[0].push_back(2);

	adjacencyList[1].push_back(3);

	adjacencyList[2].push_back(3);

	adjacencyList[3].push_back(4);
	adjacencyList[3].push_back(5);

	adjacencyList[4].push_back(5);
}
void graph::dfsRec(int source, vector<bool>  &visited)
{
	if (!visited[source])
	{
		cout << source << endl;
		visited[source] = true;
	}
	for (auto i = adjacencyList[source].begin();i != adjacencyList[source].end();i++)
	{
		if (!visited[*i])
			dfsRec(*i, visited);
	}
}
void graph::dfs(int source)
{
	vector<bool>  visited(v);
	stack <int> s;
	s.push(source);
	while (!s.empty())
	{
		int temp = s.top();
		s.pop();
		cout << temp << endl;
		for (auto i = adjacencyList[temp].begin();i != adjacencyList[temp].end();i++)
		{
			if (!visited[*i])
			{
				s.push(*i);
				visited[*i] = true;
			}
		}
	}
}
void graph::bfs(int source)
{
	queue<int> q;
	q.push(source);
	vector <bool> visited(v);
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		cout << temp << endl;
		for (auto i = adjacencyList[temp].begin();i != adjacencyList[temp].end();i++)
		{
			if (!visited[*i])
			{
				q.push(*i);
				visited[*i] = true;
			}
		}
	}
}
bool graph::isAConnectedGraph()
{
	vector<bool>  visited(v,false);
	stack <int> s;
	s.push(0);
	visited[0] = true;
	while (!s.empty())
	{
		int temp = s.top();
		s.pop();
		for (auto i = adjacencyList[temp].begin();i != adjacencyList[temp].end();i++)
		{
			if (!visited[*i])
			{
				s.push(*i);
				visited[*i] = true;
			}
		}
	}
	for (int i = 0;i < v;i++)
	{
		if (visited[i] == false)
			return false;
	}
	return true;
}

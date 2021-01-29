#include <iostream>
#include "bits/stdc++.h"
using namespace std;
class DFS
{
public:
	DFS(int size);
	void addEdge(int v, int w);
	void traverse(int s);
private:
	bool *visited;
	list<int> *adj;
	int size;
};
DFS::DFS(int size)
{
	this->size = size;
	adj = new list<int>[size];
	visited = new bool[size];

	for(int i = 0; i<size; i++)
		visited[i] = false;
}
void DFS::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void DFS::traverse(int s)
{
	if(visited[s]==0)
	{
		visited[s] = true;
		cout<<s<<" ";
		list<int>::iterator it;
		for(it = adj[s].begin(); it!=adj[s].end(); it++)
		{
			traverse(*it);
		}
	}
}

int main()
{
	DFS g(8);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,1);
	g.addEdge(2,3);
	g.addEdge(3,1);
	g.addEdge(3,4);
	g.addEdge(3,2);
	g.addEdge(3,5);
	g.addEdge(4,3);
	g.addEdge(4,5);
	g.addEdge(4,1);
	g.addEdge(5,4);
	g.addEdge(5,3);
	g.addEdge(5,6);
	g.addEdge(5,7);
	g.addEdge(6,5);
	g.addEdge(7,5);

	g.traverse(1);
	return 0;
}
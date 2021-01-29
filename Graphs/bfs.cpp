#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
	Graph(int V);
	~Graph(){};
	void AddEdge(int v, int w);
	void BFS(int s);
private:
	list<int> *adj;
	int V;

};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
void Graph::AddEdge(int v, int w)
{
	adj[v].push_back(w);
}
void Graph::BFS(int s)
{
	bool *visited = new bool[V];
	for(int i = 0; i<V; i++)
		visited[i] = false;
	list<int> queue;
	visited[s] = true; 
	queue.push_back(s);

	list<int>::iterator i;

	while(!queue.empty())
	{
		int v = queue.front();
		cout<<v<<" ";
		queue.pop_front();

		for(i = adj[v].begin(); i!=adj[v].end(); i++)
		{
			if(!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}
int main()
{
	Graph g(4);
	g.AddEdge(0,1);
	g.AddEdge(0,2);
	g.AddEdge(1,2);
	g.AddEdge(2,0);
	g.AddEdge(2,3);
	g.AddEdge(3,3);

	g.BFS(2);
	return 0;
}
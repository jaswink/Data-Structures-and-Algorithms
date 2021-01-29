#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class DFS{
	public:
		DFS(int n);
		void addEdge(int v, int w);
		void traverse(int s);
	private:
		int V;
		list<int> *adj;
		bool *visited;
};
DFS::DFS(int n) {
	this->V=n;
	adj = new list<int>[V];
	visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i] = false;
}
void DFS::addEdge(int v, int w) {
	adj[v].push_back(w);
}
void DFS::traverse(int s) {
	list<int> ::iterator it;
	if(visited[s]==false)
	{
		visited[s]=true;
		cout<<s<<" ";
		for(it=adj[s].begin();it!=adj[s].end();it++)
		{
				traverse(*it);
		}
	}
}
int main()
{
	DFS g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.traverse(2);
	return 0;
}

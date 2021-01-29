#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class BFS
{
	private:
		int size;
		list<int> *adj;
		bool *visited;
	public:
		BFS(int n);
		void addEdge(int v,int w);
		void traverse(int s);
};
BFS:: BFS(int n)
{
	this->size=n;
	adj = new list<int>[size];
	visited = new bool[size];
}
void BFS::addEdge(int v,int w)
{
	adj[v].push_back(w);
}
void BFS::traverse(int s)
{
	for(int i=0;i<size;i++)
	{
		visited[i]=false;
	}
	list<int> q;
	q.push_back(s);
	visited[s]=true;
	while(!q.empty())
	{
		int l=q.front();
		cout<<l<<" ";
		visited[l]=true;
		q.pop_front();
		list<int> :: iterator it;
		for(it=adj[l].begin();it!=adj[l].end();it++)
		{
			if(visited[*it]==false)
			{
				visited[*it]=true;
				q.push_back(*it);
			}
		}
	}
}
int main() {
	BFS g(4);
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.traverse(2);
	return 0;
}
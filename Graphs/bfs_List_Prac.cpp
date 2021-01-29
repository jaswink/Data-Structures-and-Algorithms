#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class BFS{
	public:
		BFS(int n);
		void addEdge(int v, int w);
		void traverse(int s);
	private:
		int V;
		list<int> *adj;
		bool *visited;
};
BFS::BFS(int n) {
	this->V=n;
	adj = new list<int>[V];
	visited = new bool[V];
}
void BFS::addEdge(int v, int w) {
	adj[v].push_back(w);
}
void BFS::traverse(int s) {
	for(int i=0;i<V;i++) {
		visited[i]=false;
	}
	list<int> queue;
	queue.push_back(s);
	visited[s]=true;
	list<int> ::iterator it;
	while(!queue.empty()) {
		int l = queue.front();
		cout<<l<<" ";
		queue.pop_front();
		for(it=adj[l].begin();it!=adj[l].end();it++) {
			if(visited[*it]==false) {
				visited[*it] = true;
				queue.push_back(*it);
			}
		}
	}
}
int main()
{
	BFS g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	g.traverse(2);
	return 0;
}
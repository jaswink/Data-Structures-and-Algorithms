#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class DFS {
	public:
		DFS(int n);
		void addEdge(int v,int w);
		void traverse(int s);
	private:
		int size;
		bool *visited;
		int **matrix;
};
DFS::DFS(int n) {
	this->size = n;
	visited = new bool[n];
	matrix = new int *[n];
	int i,j;
	for(i=0;i<size;i++) {
		matrix[i] = new int[n];
		for(j=0;j<size;j++) {
			matrix[i][j] = 0;
		}
	}
	for(i=0;i<size;i++) {
		visited[i] = false;
	}
}
void DFS::addEdge(int v, int w) {
	matrix[v][w] = 1;
}
void DFS::traverse(int s) {
	if(visited[s] == false) {
		cout<<s<<" ";
		visited[s] = true;
		for(int i=0;i<size;i++) {
			if(matrix[s][i]==1 && visited[i]==false)
				traverse(i);
		}
	}
}
int main()
{
	DFS bfs(5);
	bfs.addEdge(0,2);
	bfs.addEdge(0,1);
	bfs.addEdge(1,0);
	bfs.addEdge(1,3);
	bfs.addEdge(2,0);
	bfs.addEdge(2,3);
	bfs.addEdge(2,4);
	bfs.addEdge(3,1);
	bfs.addEdge(3,4);
	bfs.addEdge(4,3);
	bfs.addEdge(4,2);	
	bfs.traverse(0);
	return 0;
}
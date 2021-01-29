#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class BFS
{
public:
	BFS(int size);
	void addEdge(int v, int w);
	void traverse(int s);
private:
	int size;
	bool *visited;

	int **matrix;
};
BFS::BFS(int n)
{

	this->size = n;
	visited = new bool[n];

	matrix = new int*[n];

	for(int i = 0; i<n; i++)
	{
		matrix[i] = new int[n];

		for(int j = 0; j<n; j++)
			matrix[i][j] = 0;
	}
}
void BFS::addEdge(int v, int w)
{
	matrix[v][w] = 1;
}

void BFS::traverse(int s)
{

	for(int i =0; i<size; i++)
	{
		visited[i] = false;
	}

	list<int> queue;
	visited[s] = true;
	queue.push_back(s);

	while(!queue.empty())
	{
		int v = queue.front();
		cout<<v<<" ";
		queue.pop_front();
		for(int i = 1;i<size; i++)
		{
			int temp = matrix[v][i];
			if(temp!=0 && !visited[i])
			{
				visited[i] = true;
				queue.push_back(i);

			}
		}
	}
}

int main()
{
	BFS bfs(8);
	bfs.addEdge(1,2);
	bfs.addEdge(1,4);
	bfs.addEdge(1,3);
	bfs.addEdge(2,1);
	bfs.addEdge(2,3);
	bfs.addEdge(3,1);
	bfs.addEdge(3,4);
	bfs.addEdge(3,2);
	bfs.addEdge(3,5);
	bfs.addEdge(4,3);
	bfs.addEdge(4,1);
	bfs.addEdge(4,5);
	bfs.addEdge(5,4);
	bfs.addEdge(5,3);
	bfs.addEdge(5,6);
	bfs.addEdge(5,7);
	bfs.addEdge(6,5);
	bfs.addEdge(7,5);

	bfs.traverse(1);


	return 0;
}
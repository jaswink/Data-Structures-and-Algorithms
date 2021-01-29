#include<iostream>
using namespace std;
class DFS
{
public:
	DFS(int size);
	void addEdge(int v, int w);
	void traverse(int s);
private:
	int **matrix;
	bool *visited;
	int size;
};

DFS::DFS(int size)
{
	this->size = size;
	matrix = new int*[size];
	for(int i = 0; i<size; i++)
	{
		matrix[i] = new int[size];
	}
	for(int i = 0; i<size; i++)
	{
		for(int col = 0; col<size; col++)
		{
			matrix[i][col] = 0;
		}
	}
	visited = new bool[size];
	for(int i = 0; i<size; i++)
		visited[i] = false;
}

void DFS::addEdge(int v, int w)
{

	matrix[v][w] = 1;
}
void DFS::traverse(int s)
{

	if(visited[s]==false)
	{
		visited[s] = true;
		cout<<s<<" "; 
		for(int i = 0; i<size; i++)
		{
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
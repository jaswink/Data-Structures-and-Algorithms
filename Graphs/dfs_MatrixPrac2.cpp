#include<bits/stdc++.h>
using namespace std;
class DFS
{
	private:
		int size;
		int **matrix;
		bool *visited;
	public:
		DFS(int n);
		void addEdge(int v,int w);
		void traverse(int s);
};
DFS::DFS(int n)
{
	this->size=n;
	int i,j;
	visited=new bool[n];
	for(i=0;i<n;i++)
	{
		visited[i]=false;
	}
	matrix=new int *[n];
	for(i=0;i<n;i++)
	{
		matrix[i]=new int[n];
		for(j=0;j<n;j++)
		{
			matrix[i][j]=0;
		}
	}
}
void DFS::addEdge(int v,int w)
{
	matrix[v][w]=1;
	matrix[w][v]=1;
}
void DFS::traverse(int s)
{
	if(visited[s]==false)
	{
		visited[s]=true;
		cout<<s<<" ";
		for(int i=0;i<size;i++)
		{
			if(matrix[s][i]==1 && visited[i]==false)
				traverse(i);
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

#include<bits/stdc++.h>
using namespace std;
class BFS
{
	private:
		int size;
		int **matrix;
		bool *visited;
	public:
		BFS(int n);
		void addEdge(int v,int w);
		void traverse(int s);
};
BFS::BFS(int n)
{
	this->size=n;
	matrix=new int *[n];
	visited=new bool[n];
	int i;
	for(i=0;i<n;i++)
	{	
		visited[i]=false;
	}
	for(i=0;i<n;i++)
	{
		matrix[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			matrix[i][j]=0;
		}
	}
}
void BFS::addEdge(int v,int w)
{
	matrix[v][w]=1;
	matrix[w][v]=1;
}
void BFS::traverse(int s)
{
	list<int> q;
	q.push_back(s);
	visited[s]=true;
	while(!q.empty())
	{
		int l=q.front();
		cout<<l<<" ";
		q.pop_front();
		for(int i=0;i<size;i++)
		{
			int x=matrix[l][i];
			if(visited[i]==false && x==1)
			{
				visited[i]=true;
				q.push_back(i);
			}
		}
	}
}
int main() {
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
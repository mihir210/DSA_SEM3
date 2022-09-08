
#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
   
	vector<list<int>> adj;
public:
	Graph(int V); 
	void addEdge(int v, int w);

	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	vector<bool> visited;
	visited.resize(V,false);

	queue<int> q;

	visited[s] = true;
	q.push(s);

	while(!q.empty())
	{
		s = q.front();
		cout << s << " ";
		q.pop();
      
		for (auto adjecent: adj[s])
		{
			if (!visited[adjecent])
			{
				visited[adjecent] = true;
				q.push(adjecent);
			}
		}
	}
}

int main()
{
Graph b(5);
   b.addEdge(0,1);
    b.addEdge(1,0);
    b.addEdge(1,2);
    b.addEdge(1,3);
    b.addEdge(2,1);
    b.addEdge(3,1);
    b.addEdge(2,4);
    b.addEdge(4,2);
    b.addEdge(3,4);
    b.addEdge(4,3);
    b.addEdge(4,5);
    b.addEdge(5,4);
    b.addEdge(4,6);
    b.addEdge(6,4);
    b.BFS(1);


	return 0;
}

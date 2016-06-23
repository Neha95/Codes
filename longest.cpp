#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
struct node
{
	int v,w;
};

class Graph
{
	int V;
	vector<node> *adj;
	int *vis;
	stack<int> s;
	public:
	Graph(int V);
	void addEdge(int u,int v,int w);
	void cycle();
	void visit(int n);
	void longest(int s);
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<node> [V];
    vis=new int[V];
    for(int i=0;i<V;i++)
    	vis[i]=0;
}
void Graph::addEdge(int u,int v,int w)
{
	node x;
	x.v=v;
	x.w=w;
	adj[u].push_back(x);
}
void Graph::cycle()
{
	for(int i=0;i<V;i++)
	{
		if(!vis[i])
			visit(i);
	}
	while(!s.empty())
	{
		int x=s.top();
		cout<<x<<endl;
		s.pop();
	}
}
void Graph::visit(int n)
{
	if(!vis[n])
	{
		for(int i=0;i<adj[n].size();i++)
		{
			visit(adj[n][i].v);
			vis[(adj[n][i].v)]=1;
		}
		vis[n]=1;
		s.push(n);
	}
}

int main() {

	Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    cout << "Following is a Longest Path of the given graph \n";
    g.longest(1);
  //  cout<<cost;
	return 0;
}
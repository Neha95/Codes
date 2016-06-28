#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V; 
    vector<int> *adj;
    vector<int> indegree;
 	vector<int> vis;
 	vector<int> s;
public:
    Graph(int V);  
    void addEdge(int v, int w);

    void alltopSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
 
    // Initialising all indegree with 0
    for (int i = 0; i < V; i++)
    {    indegree.push_back(0);
		 vis.push_back(0);
    }
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
    indegree[w]++;
}
void Graph:: alltopSort()
{
	bool flag=0;
	for(int i=0;i<V;i++)
	{
		if(!vis[i] && indegree[i]==0)
		{
			vis[i]=1;
			for(int j=0;j<adj[i].size();j++)
				indegree[adj[i][j]]--;
			s.push_back(i);
			alltopSort();
			vis[i]=0;
			s.erase(s.end()-1);
			for(int j=0;j<adj[i].size();j++)
				indegree[adj[i][j]]++;
				flag=1;
		}
	}
	if(!flag)
	{
		for(int i=0;i<s.size();i++)
			cout<<s[i]<<" ";
		cout<<endl;
	}
}
int main() {
Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "All Topological sorts\n";
 
    g.alltopSort();
	return 0;
}
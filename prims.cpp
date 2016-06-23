#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
 
using namespace std;
int n,m;
struct st{
	int x,y,wt;};
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];
 
int cnt;
void prim(int x)
{
	priority_queue<PII, vector<PII>, greater<PII> > Q;
	int y;
	PII p;
	Q.push(make_pair(0, x));
	while(!Q.empty())
	{
 
		p=Q.top();
		Q.pop();
		x=p.second;
		if(marked[x])
			continue;
		marked[x]=1;
		//	cout<<cnt<<endl;
		cnt++;
 
		for(int i=0;i<adj[x].size();i++)
		{
			y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
		}
	}
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		cnt=0;vector<st> temp;
		int x,y,wt;
		cin>>n>>m;
		for(int i=0;i<=n;i++)
			marked[i]=0;
		for(int i=0;i<m;i++)
		{
			cin>>x>>y>>wt;
			st A;
			A.x=x;
			A.y=y;
			A.wt=wt;
			temp.push_back(A);
 
		}
			for(int i=0;i<n-1;i++)
		{
			int num;
			cin>>num;
			num--;
			int x=temp[num].x;
			int y=temp[num].y;
			int wt=temp[num].wt;
			adj[x].push_back(make_pair(wt,y));
			adj[y].push_back(make_pair(wt,x));
		}
 
		prim(1);
		if(cnt==(n))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
#include <iostream>
using namespace std;
int in[100005],tree[400005];
long long int p[100005];
int n;
void initialise()
{
	p[0]=1;
	for(int i=1;i<=100000;i++)
		p[i]=((p[i-1]%3)*(2%3))%3;
}
void build(int idx,int st,int en)
{
	if(st==en)
	{
		tree[idx]=in[st]%3;
	//	cout<<tree[idx]<<" ";
		return;
	}
	
	int mid=(st+en)/2;
	build(2*idx+1,st,mid);
	build(2*idx+2,mid+1,en);
	tree[idx]=(tree[2*idx+1]*p[en-mid]+tree[2*idx+2])%3;
	//	cout<<tree[idx]<<" ";
}	
void update(int st,int en,int idx,int l)
{
	
	if(st==en)
	{
		if(st==l)
			tree[idx]=1;
		return;
	}
	
	int mid=(st+en)/2;
	update(st,mid,2*idx+1,l);
	update(mid+1,en,2*idx+2,l);
	tree[idx]=(tree[2*idx+1]*p[en-mid]+tree[2*idx+2])%3;

}
int query(int st,int en,int idx,int l,int r)
{
//	cout<<st<<" "<<l<<" "<<en<<" "<<r<<" "<<35<<" ";
	
	if(st<0 || en>=n)
		return 0;
	if(st>=l && en<=r)
	{
	//	cout<<67;
//		cout<<tree[idx]<<" ";
		return tree[idx];
	}
//	cout<<45;
	int mid=(st+en)/2;
	int x=query(st,mid,2*idx+1,l,r);
	int y=query(mid+1,en,2*idx+2,l,r);
	int ans=(x+y)%3;
//	cout<<ans<<" ";
	return ans;
}
int main() {
	int n;
	cin>>n;
	string s;
	//cout<<-1;
	cin>>s;
	initialise();
//	cout<<0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		 	in[i]=1;
	 	else
	 		in[i]=0;
	}
//	cout<<1;
	
	build(0,0,n-1);
	cout<<endl;
//	cout<<2;
	int q;
	cin>>q;
//	cout<<q<<endl;
//	cout<<3;
	while(q--)
	{
		int type;
		cin>>type;
		if(type==0)
		{
			int l,r;
			cin>>l>>r;
	//		cout<<l<<" "<<r<<" "<<" ";
			cout<<query(0,n-1,0,l,r)<<endl;
		}
		else
		{
			int l;
			cin>>l;
	//		cout<<l<<endl;
			update(0,n-1,0,l);
		}
	}
	return 0;
}
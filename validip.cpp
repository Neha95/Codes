#include <iostream>
using namespace std;
bool isvalid(string ip)
{
	int n=ip.size();
	int i=0;
	int cnt=0;
	while(i<n)
	{
		int num=0;
		while(i<n && ip[i]!='.')
		{
			int x=ip[i]-'0';
			num=num*10+x;
			i++;
		}
		cnt++;
		if(0<=num && num<=255 )
		{ i++;	continue;}
		else
			return 0;
	}
	if(cnt==4)
		return 1;
	return 0;
}
int main() {
	cout<< isvalid("134.11.24.201")<<endl;
	cout<< isvalid("134.11.24.281")<<endl;
	return 0;
}
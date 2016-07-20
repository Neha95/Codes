#include <iostream>
using namespace std;
struct trienode
{
	trienode* child[10];
	bool isleaf;
	string domain;
};	
class trie
{
	public:
	trienode* root;
	int cnt;
	trienode* getnode(void);
	trie()
	{
		root=getnode();
		cnt=0;
	}
	void insert(string key,string value);
	bool delete_key_helper(trienode* t,string key,int lvl,int len);
	void delete_key(string key);
	string search(string key);
	bool isfree(trienode* t)
	{
		for(int i=0;i<10;i++)
		{
			if(t->child[i])
				return 0;
		}
		return 1;
	}
	
};

trienode* trie::getnode(void)
{
	trienode *t=NULL;
	t=new trienode;
	for(int i=0;i<10;i++)
	{
		t->child[i]=NULL;
	}
	t->isleaf=0;
	t->domain="";
	return t;
}
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

void trie::insert(string key,string value)
{
	if( !isvalid(key))
	{
		cout<<"Not valid IP address";
		return;
	}
	int n=key.size();
	trienode* crawl=this->root;
	for(int i=0;i<n;i++)
	{
		if(key[i]=='.')
			continue;
		int c=key[i]-'0';
		if(crawl->child[c] !=NULL)
			crawl=crawl->child[c];
		
		else
		{
			trienode* tmp=getnode();
			crawl->child[c]=tmp;
			crawl=crawl->child[c];
			
		}
	}
	crawl->isleaf=1;
	crawl->domain=value;
	cnt++;
}
string trie::search(string key)
{
	int n=key.size();
	trienode* crawl=root;
	for(int i=0;i<n;i++)
	{
		if(key[i]=='.')	
			continue;
		int c=key[i]-'0';
		if(! (crawl->child[c]))
			return "NOT FOUND";
		else
		{
			crawl=crawl->child[c];
		}
	}
	if(crawl->isleaf == 1)
		return crawl->domain;
	return "NOT FOUND";
}/*
bool trie:: delete_key_helper(trienode* t,string key,int lvl,int n)
{
//	cout<<"deleted "<<key[lvl]<<endl;

	if(t)
	{
		//	cout<<"deleted "<<key[lvl]<<endl;
		if(lvl==n)
		{
			if(t->isleaf)
			{
				t->isleaf=0;
				if(isfree(t))
					return 1;
				return 0;
			}
		}
			else
	{
		
		int c=key[lvl]-'0';
		if( delete_key_helper(t->child[c], key, lvl+1, n) )
            {
                // last node marked, delete it
                
                
                free (t->child[c]);
                t->child[c]=NULL;
 
                // recursively climb up, and delete eligible nodes
                return ( !(t->isleaf !=0) && (isfree(t)) );
            }
	}
	}

	return false;
}
void trie::delete_key(string key)
{
	trienode *crawl=root;
	int n=key.size();
	delete_key_helper(root,key,0,n);
}*/
int main() {
	trie t;
	t.insert("192.12.10.0","google.com");
	t.insert("142.12.10.7","facebook.com");
	t.insert("192.12.11.1","ideone.com");
	cout<<t.search("192.12.10.0")<<endl;
	cout<<t.search("192.12.11.1")<<endl;
	cout<<t.search("192.12.11.0")<<endl;
	return 0;
}
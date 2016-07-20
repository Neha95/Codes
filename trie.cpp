#include <iostream>
using namespace std;
struct trienode
{
	trienode* child[26];
	bool isleaf;
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
	void insert(string key);
	bool delete_key_helper(trienode* t,string key,int lvl,int len);
	void delete_key(string key);
	int search(string key);
	bool isfree(trienode* t)
	{
		for(int i=0;i<26;i++)
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
	for(int i=0;i<26;i++)
	{
		t->child[i]=NULL;
	}
	t->isleaf=0;
	return t;
}
void trie::insert(string key)
{
	int n=key.size();
	trienode* crawl=this->root;
	for(int i=0;i<n;i++)
	{
		int c=key[i]-'a';
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
	cnt++;
}
int trie::search(string key)
{
	int n=key.size();
	trienode* crawl=root;
	for(int i=0;i<n;i++)
	{
		int c=key[i]-'a';
		if(! (crawl->child[c]))
			return 0;
		else
		{
			crawl=crawl->child[c];
		}
	}
	if(crawl->isleaf == 1)
		return 1;
	return 0;
}
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
		int c=key[lvl]-'a';
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
}
int main() {
	trie t;
	t.insert("she");
	t.insert("sells");
	t.insert("sea");
	t.insert("shore");
	t.insert("where");
	cout<<t.search("sea")<<endl;
	cout<<t.search("what")<<endl;
	cout<<t.search("whe")<<endl;
	cout<<t.search("where")<<endl;
	cout<<t.search("ass")<<endl;
	t.delete_key("where");
	cout<<t.search("where")<<endl;
	return 0;
}
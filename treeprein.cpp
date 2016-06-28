#include <bits/stdc++.h>
using namespace std;
struct treenode
{
  char data;
  treenode* left;
   treenode* right;
};

treenode* newnode(char data)
{
  treenode* node = new treenode;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  
  return(node);
}

int preidx=0;
int search(string in,char x,int st,int en)
{
	for(int i=st;i<=en;i++)
	{
		if(x==in[i])
			return i;
	}
}
treenode* buildTree(string in,string pre,int st,int en)
{
	if(st>en)
		return NULL;
	char data=pre[preidx];
	preidx++;
	treenode* node=newnode(data);
	int idx=search(in,node->data,st,en);
	node->left=buildTree(in,pre,st,idx-1);
	node->right=buildTree(in,pre,idx+1,en);
	return node;
}
void printInorder(treenode* node)
{
  if (node == NULL)
     return;

  printInorder(node->left);

  cout<<(node->data)<<" ";

  printInorder(node->right);
}
 
int main() {
	 string in="DBEAFC";
	 string pre="ABDECF";
  int len=in.size();
  treenode *root = buildTree(in, pre, 0, len - 1);
 
  printf("Inorder traversal of the constructed tree is \n");
  printInorder(root);
	return 0;
}
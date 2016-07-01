#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char key;
    struct Node* left, *right;
};
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pocharers. */
Node *newNode(char k)
{
    Node *node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}
 
int closestdown(Node *root)
{
	if(!root)
		return INT_MAX;
	if(!(root->left) && !(root->right))
	{
		return 0;
	}
	return 1+min(closestdown(root->left),closestdown(root->right));
}	
int closeleafutil(Node *root,char k,Node* ancestor[],int idx)
{
	if(!root)
		return INT_MAX;
	if(root->key == k)
	{
		int res=closestdown(root);
		for(int i=0;i<idx;i++)
			res=min(res,idx-i+closestdown(ancestor[i]));
		return res;
	}
	ancestor[idx] = root;
	 return min(closeleafutil(root->left, k, ancestor, idx+1),
                  closeleafutil(root->right, k, ancestor, idx+1));
}	
int closestleaf(Node *root, char k)
{
	 Node *ancestor[100];
	 return closeleafutil(root,k,ancestor,0);
}
	
int main() { Node *root        = newNode('A');
    root->left               = newNode('B');
    root->right              = newNode('C');
    root->right->left        = newNode('E');
    root->right->right       = newNode('F');
    root->right->left->left  = newNode('G');
    root->right->left->left->left  = newNode('I');
    root->right->left->left->right = newNode('J');
    root->right->right->right      = newNode('H');
    root->right->right->right->left = newNode('K');
 
    char k = 'H';
    cout << "Distace of the closest key from " << k << " is "
         << closestleaf(root, k) << endl;
    k = 'C';
    cout << "Distace of the closest key from " << k << " is "
         << closestleaf(root, k) << endl;
    k = 'E';
    cout << "Distace of the closest key from " << k << " is "
         << closestleaf(root, k) << endl;
    k = 'B';
    cout << "Distace of the closest key from " << k << " is "
         << closestleaf(root, k) << endl;
 	// your code goes here
	return 0;
}
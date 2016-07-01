#include <iostream>
using namespace std;
Node* leftright(Node *root)
{
	if(!root)
		return NULL;
	Node *left=root->left;
	Node *clone=newNode(root->data);
	root->left=clone;
	if (left)
		left->left=leftright(left);
	root->left->right=leftright(root->right);
	return clone;
}	
void clonerandom(Node *root,Node *clone)
{
	if(!root)
		return;
	if(!(root->random))
	{	clone->random=NULL;	return;}
	else
		clone->random=root->random->left;
	if(root->left && clone->left)
		clonerandom(root->left->left,clone->left->left);
	clonerandom(root->right,clone->right);
}
void fix(Node *root, Node *clone)
{
	 if (root == NULL)
        return;
    if (clone->left)
    {
        Node* cloneLeft = clone->left->left;
        root->left = root->left->left;
        clone->left = cloneLeft;
    }
    else
        treeNode->left = NULL;
 
    fix(root->left, clone->left);
    fix(root->right, clone->right);
}
Node* clonetree(Node *root)
{
	if(!root)
		return NULL;
	Node *clone=leftright(root);
	clonerandom(root,clone);
	fix(root,clone);
	return clone;
}	
int main() {
	// your code goes here
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node* newNode (int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void inorder(node *root)
{
	if (root != NULL)
    {
		inorder(root->left);
		cout<<(root->data)<<" ";
		inorder(root->right);
    }
}	
void merge(node *root1,node *root2)
{
	node *cur1=root1,*cur2=root2;
	stack<node*> s1,s2;
	while((cur1!=NULL) || (cur2!=NULL) || (!(s1.empty())) || (!(s2.empty())) )
	{
		if((cur1!=NULL) || (cur2!=NULL))
		{
			
			if(cur1!=NULL)
			{
			//	cout<<(- cur1->data)<<endl;
				s1.push(cur1);
				cur1=cur1->left;
			}
			if(cur2 != NULL)
			{
			//	cout<<(- cur2->data)<<endl;
				s2.push(cur2);
				cur2=cur2->left;
			}
		}
		else
		{
			if(s1.empty())
			{
				while(!(s2.empty()))
				{
					cur2=s2.top();
					s2.pop();
					cur2->left=NULL;
				//	cout<<(- cur2->data)<<endl;
					inorder(cur2);
					
				}
				return;
			}
			if(s2.empty())
			{
				while(!(s1.empty()))
				{
					cur1=s1.top();
					s1.pop();
					cur1->left=NULL;
					//cout<<(- cur1->data)<<endl;
					inorder(cur1);
					
				}
				return;
			}
			
		
		cur1=s1.top();
		s1.pop();
		cur2=s2.top();
		s2.pop();
		if((cur1->data) < (cur2->data))
		{
			cout<<(cur1->data)<<" ";
			cur1=cur1->right;
			s2.push(cur2);
			cur2=NULL;
		}
		else
		{
			cout<<(cur2->data)<<" ";
			cur2=cur2->right;
			s1.push(cur1);
			cur1=NULL;
		}
		}
	}
}
int main() {
	node  *root1 = NULL, *root2 = NULL;
 
    /* Let us create the following tree as first tree
            3
          /  \
         1    5
     */
    root1 = newNode(3);
    root1->left = newNode(1);
    root1->right = newNode(5);
 
    /* Let us create the following tree as second tree
            4
          /  \
         2    6
     */
    root2 = newNode(4);
    root2->left = newNode(2);
    root2->right = newNode(6);
 
    // Print sorted nodes of both trees
    merge(root1, root2);
	return 0;
}
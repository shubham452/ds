//time complexity:O(n)
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *left,*right;
};
struct node *newnode(int val)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
bool check(vector<int> v)
{
	int size=v.size();
	int min=v[size-1];
	int max=v[size-1];
	for(int i=size-2;i>=0;i--)
	{
		if(v[i]>max)
		{
			max=v[i];
		}
		else if(v[i]<min)
		{
			min=v[i];
		}
		else
		{
			return false;
		}
	}
	return true;
}
void preorder(struct node *root, vector<int> &v)
{
	if(root==NULL)
	{
		return;
	}
	v.push_back(root->data);
	preorder(root->left,v);
	preorder(root->right,v);
}
int main()
{
    vector<int> v;
    node *root;
    root=newnode(20);
    root->left=newnode(10);
    root->left->right = newnode(11);
    root->left->right->right = newnode(13);
    
    preorder(root,v);
    if(check(v))
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    
    return 0;
}

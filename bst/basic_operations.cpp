#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *left, *right;
};
struct node *newnode(int val)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=val;
	ptr->left=ptr->right=NULL;
	return ptr;  
}
struct node *insert(struct node *root, int key)
{
	if(root==NULL)
	{
		return newnode(key);
	}
	else if(root->data<key)
	{
		root->right=insert(root->right,key);
	}
	else if(root->data>key)
	{
		root->left=insert(root->left,key);
	}
	return root;
}
void inorder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);
}
int getminright(struct node *root)
{
	struct node *temp=root;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp->data;
}
struct node *deletenode(struct node *root, int val)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(root->data>val)
	{
		root->left=deletenode(root->left,val);
	}
	else if(root->data<val)
	{
		root->right=deletenode(root->right,val);
	}
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			return NULL;
		}
		else if(root->left==NULL)
		{
			struct node *ptr=root->right;
			free(root);
			return ptr;
		}
		else if(root->right==NULL)
		{
			struct node *ptr=root->left;
			free(root);
			return ptr;
		}
		else
		{
			int minright=getminright(root->right);
			root->data=minright;
			root->right=deletenode(root->right,minright);
		}
	}
	return root;
}
int main()
{
	int x;
	struct node *root=NULL;
	cout<<"enter data and -1 to exit"<<endl;
	cin>>x;
	do
	{
		root=insert(root,x);
		cin>>x;
	}while (x!=-1);
	inorder(root);
	root=deletenode(root,2);
	cout<<"after deletion"<<endl;
	inorder(root);
	return 0;
	/*struct node *root = NULL;
    root = insert(root,100);
    root = insert(root,50);
    root = insert(root,200);
    root = insert(root,150);
    root = insert(root,300);
    inorder(root);
    cout<<endl;
    root=deletenode(root,50);
    inorder(root);
    cout<<endl;
    root=deletenode(root,200);
    inorder(root);
    return 0;*/
}
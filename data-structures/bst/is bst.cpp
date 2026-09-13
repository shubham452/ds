#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};
struct node *newnode(int val)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->right=ptr->left=NULL;
    return ptr;
}
int isbst(struct node *root, int min, int max)
{  
    if(root==NULL)
    {
        return 1;
    }
    if(root->data<min || root->data>max)
    {
        return 0;
    }
    return isbst(root->left,min,root->data) && isbst(root->right,root->data,max);
}
int main()
{
    node *root;
    root=newnode(20);
    root->left=newnode(8);
    root->right = newnode(22);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(14);
    int x=isbst(root,INT_MIN,INT_MAX);
    cout<<x<<endl;
    return 0;
}
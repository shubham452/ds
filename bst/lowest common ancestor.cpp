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
struct node *lca(struct node *root,int n1,int n2)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data>n1 && root->data>n2)
    {
        return lca(root->left,n1,n2);
    }
    if(root->data<n1 && root->data<n2)
    {
        return lca(root->right ,n1,n2);
    }
    return root;
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
    int n1=14,n2=8;
    struct node *t;
    t=lca(root,10,14);
    cout<<t->data;
    return 0;
}
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
    ptr->right=ptr->left=NULL;
    return ptr;
}
struct node *insert(struct node *root, int val)
{
    if(root==NULL)
    {
        return newnode(val);
    }
    if(root->data>val)
    {
        root->left=insert(root->left,val);
    }
    else if(root->data<val)
    {
        root->right=insert(root->right,val);
    }
    return root;
}
int getrightmin(struct node *root)
{
    struct node *temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp->data;
}
struct node *deletenode(struct node *root, int x)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data>x)
    {
        root->left=deletenode(root->left,x);
    }
    else if(root->data<x)
    {
        root->right=deletenode(root->right,x);
    }
    else
    {
        if(root->right==NULL && root->left==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->right==NULL)
        {
            struct node *ptr=root->left;
            free(root);
            return ptr;
        }
        else if(root->left==NULL)
        {
            struct node *ptr=root->right;
            free(root);
            return ptr;
        }
        else
        {
            int rightmin=getrightmin(root->right);
            root->data=rightmin;
            root->right=deletenode(root->right,rightmin);
        }
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
int main()
{
    struct node *root = NULL;
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
    return 0;
}
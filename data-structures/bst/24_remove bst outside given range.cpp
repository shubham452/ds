#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};
struct node *newnode(int val)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->left=ptr->right=NULL;
}
struct node *insert(struct node *root, int val)
{
    if(root==NULL)
    {
        return newnode(val);
    }
    if(root->data<val)
    {
        root->right=insert(root->right,val);
    }
    else if(root->data>val)
    {
        root->left=insert(root->left,val);
    }   
    return root;
}
int smallerright(struct node *root)
{
    struct node *ptr=root;
    while(ptr->left!=NULL)
    {
        ptr=ptr->left;
    }
    return ptr->data;
} 
struct node *del(struct node *root, int x)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data>x)
    {
        root->left=del(root->left,x);
    }
    else if(root->data<x)
    {
        root->right=del(root->right,x);
    }
    else{
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
        int next=smallerright(root->right);
        root->data=next;
        root->right=del(root->right,next);
    }
    }
    return root;
}
void check(struct node *root,int min,int max)
{
    if(root==NULL)
    {
        return ;
    }
    
    check(root->left,min,max);
    if(root->data>max || root->data<min)
    {
        cout<<"pahuch gae"<<root->data<<endl;
        root= del(root,root->data);
    }
    check(root->right,min,max);
   // return root;
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
   /* int a,b;
    cout<<"enter range"<<endl;
    cin>>a>>b;*/
    struct node *root=NULL;
    root=insert(root,6);
    root=insert(root,-13);
    root=insert(root,-8);
    root=insert(root,14);
    root=insert(root,13);
    root=insert(root,15);
    root=insert(root,7);
   /* cout<<"before"<<endl;
    inorder(root);
    del(root,-13);
    inorder(root);*/
   root=check(root,0,15);
   root=del(root,-13);
    inorder(root);
    return 0;
}
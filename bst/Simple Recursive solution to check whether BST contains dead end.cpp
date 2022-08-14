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
    return ptr;
}
struct node *insert(struct node *root,int key)
{
    if(root==NULL)
    {
        return newnode(key);
    }
    if(root->data>key)
    {
        root->left=insert(root->left,key);
    }
    else if(root->data<key)
    {
        root->right=insert(root->right,key);
    }
    return root;
}

bool check(struct node *root,int min, int max)
{
    if(root==NULL)
    {
        return false;
    }
    if(min==max)
    {
        return true;
    }
    cout<<"check"<<endl;
    return(check(root->left,min,root->data-1)||check(root->right,root->data+1,max));
}
int main()
{
    struct node *root=NULL;
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 4);
    cout<<"check"<<endl;
    if(check(root,1,INT_MAX)==true)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    return 0;
}
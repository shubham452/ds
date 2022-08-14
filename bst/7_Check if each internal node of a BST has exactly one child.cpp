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
bool check(struct node *root,vector<int> v)
{
    int i,a,b;
    for(i=0;i<v.size()-1;i++)
    {
        a=v[i]-v[i+1];
        b=v[i]-v[v.size()-1];
        if(a*b<0)
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
    if(check(root,v))
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    
    return 0;
}
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
void inorder(struct node *root,vector<int> &v)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
int main()
{
    vector<int> v;
    int k;
    cin>>k;
    node *root;
    root=newnode(20);
    root->left=newnode(8);
    root->right = newnode(22);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(14);
    inorder(root,v);
    cout<<v[k-1]<<endl;
    return 0;
}
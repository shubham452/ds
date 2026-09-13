#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int val)
{
    struct node *nn= new node;
    nn->data=val;
    nn->left=nn->right=NULL;
    return nn;
}
int main()
{
    struct node *root=newnode(3);
    root->left=newnode(2);
    root->right=newnode(4);
    root->left->left  = newnode(1);
    root->left->right = newnode(3);
    root->right->right = newnode(5);
}
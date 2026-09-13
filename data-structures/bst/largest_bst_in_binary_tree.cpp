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
bool isbst(struct node *root, int min, int max)
{
    if(root==NULL)
    {
        return true;
    }
    else if(root->data<min || root->data>max)
    {
        return false;
    }
    return isbst(root->left,min,root->data-1) && isbst(root->right,root->data+1,max); 
}
int size(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return size(root->left)+size(root->right)+1;
}
int largestbst(struct node *root)
{
    if(isbst(root,INT_MIN,INT_MAX)==true)
    {
        return size(root);
    }
    return max(largestbst(root->left),largestbst(root->right));
}
/*void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}*/
int main()
{
    struct node *root = newnode (67);
    root->left = newnode (72);
    root->right = newnode (77);
    root->left->left = newnode (57);
    cout<<largestbst(root);
    return 0;
}

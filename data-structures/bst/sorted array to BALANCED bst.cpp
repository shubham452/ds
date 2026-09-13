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
struct node *bsttobalanced(int ar[], int start, int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=(start+end)/2;
    struct node *root=NULL;
    root=newnode(ar[mid]);
    root->left=bsttobalanced(ar,start,mid-1);
    root->right=bsttobalanced(ar,mid+1,end);
    return root;
}
void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    
    int ar[]={1, 2, 3, 4, 5, 6, 7};
    int n=sizeof(ar)/sizeof(int);
    struct node *root=bsttobalanced(ar,0,n-1);
    preorder(root);
    return 0;
}
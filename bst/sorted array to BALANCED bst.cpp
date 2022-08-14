#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
node *arraytobst(int arr[],int start, int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=(start+end)/2;
    node *root=new node(arr[mid]);
    root->left=arraytobst(arr,start,mid-1);
    root->right=arraytobst(arr,mid+1,end);
    return root;
}
void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->right);
    
    preorder(root->left);
}
int main()
{
    int arr[]={2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    node *root=arraytobst(arr,0,n-1);
    preorder(root);
    return 0;
}
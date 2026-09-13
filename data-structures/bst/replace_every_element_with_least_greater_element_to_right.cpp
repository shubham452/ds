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
struct node *insert(struct node *root,int val, int &suc)
{
    if(root==NULL)
    {
        return newnode(val);
    }
    if(val>=root->data)
    {
        root->right=insert(root->right,val,suc);
    }
    else
    {
        suc=root->data;
        root->left=insert(root->left,val,suc);
    }
    return root;
}
int main()
{
    struct node *root=NULL;
    int ar[]={ 8,  58, 71, 18, 31, 32, 63, 92,43, 3,  91, 93, 25, 80, 28 };
    int n=sizeof(ar)/sizeof(int);
    int ans[n],i;
    for(i=n-1;i>=0;i--)
    {
        int suc=-1;
        root=insert(root,ar[i],suc);
        ans[i]=suc;
    }
    for(i=0;i<n;i++)
    {
        cout<<ans[i]<<"  ";
    }
    return 0;
}
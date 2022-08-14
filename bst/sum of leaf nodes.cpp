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
    ptr->left=ptr->right=NULL;
    return ptr;
}
struct node *insert(struct node *root,int val)
{
    if(root==NULL)
    {
        root=newnode(val);
    }
    else
    {
        if(val<root->data)
        {
            root->left=insert(root->left,val);
        }
        else if(val>root->data)
        {
            root->right=insert(root->right,val);
        }
        
    }
    return root;
}

void sumofleaf(struct node *root, int &sum)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        sum=sum+root->data;
    }
    sumofleaf(root->left,sum);
    sumofleaf(root->right,sum);
}
int main()
{
    int n,i,x;
    struct node *root=NULL;
    cout<<"enter no. of inputs"<<endl;
    cin>>n;
    cout<<"enter values"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>x;
        root=insert(root,x);
    }
    int sum=0;
    sumofleaf(root, sum);
    cout<<"sum is "<<sum<<endl;
    return 0;

}
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};
struct node *insert(struct node *root,int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(root==NULL)
    {
        newnode->data=val;
        newnode->right=newnode->left=NULL;
    }
    else
    {
        if(root->data>val)
        {
            root->left=insert(root->left,val);
        }
        else if(root->data<val)
        {
            root->right=insert(root->right,val);
        }
    }
    return root;
}
void traverse(struct node *root1, struct node *root2,int sum)
{
    if(root1==NULL)
    {
        return;
    }
    bool x=find(root2,sum-root1->data);
    if(x)
    {
        cout<<root1->data<<"  "<<sum-root1->data<<endl;
    }
    traverse(root1->left,root2,sum);
    traverse(root1->right,root2,sum);
}
bool find(struct node *root2 ,int x)
{
    if(root2==NULL)
    {
        return false;
    }
    if(root2->data==x)
    {
        return true;
    }
    return find(root2->left,x);
    return find(root2->right,x);
}

int main()
{
    int n1,n2,i,x;
    struct node *root1,*root2=NULL;
    root1=NULL;
    cout<<"enter no. of inputs in 1st tree"<<endl;
    cin>>n1;
    cout<<"enter no. of inputs in 2nd tree"<<endl;
    cin>>n2;
    cout<<"enter values of 1st tree"<<endl;
    for(i=0;i<n1;i++)
    {
        cin>>x;
        root1=insert(root1,x);
    }
    cout<<"enter values of 2nd tree"<<endl;
    for(i=0;i<n2;i++)
    {
        cin>>x;
        root1=insert(root2,x);
    }
    int sum;
    cout<<"enter sum"<<endl;
    cin>>sum;
    traverse(root1,root2,sum);
    return 0;
}
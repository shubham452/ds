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
struct info
{
    int size;
    int max;
    int min;
    int ans;
    bool isbst;
};
info largestbstinbt(struct node *root)
{
    if(root==NULL)
    {
        return{0, INT_MIN, INT_MAX, 0, true};
        
    }
    if(root->left==NULL && root->right==NULL)
    {
        return{1, root->data, root->data, 1, true};
       
    }
    info l=largestbstinbt(root->left);
    info r=largestbstinbt(root->right);
    info curr;
    curr.size=(1+l.size+r.size);
    
    if(l.isbst && r.isbst && l.max < root->data && r.min > root->data)
    {
        curr.min=min(l.min,min(root->data,r.min));
        curr.max=max(r.max,max(root->data,l.max));
        curr.ans=curr.size;
        curr.isbst=true;
        

        return curr;
    }
    
    curr.ans=max(l.ans,r.ans);
    curr.isbst=false;
    return curr;
}
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
int main()
{
    struct node *root=newnode(15);
    root->left=newnode(20);
    root->right=newnode(30);
    root->left->left=newnode(5);
    inorder(root);
    cout<<largestbstinbt(root).ans<<endl;
    return 0;
}
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
struct node *insert(struct node *root, int val)
{
    if(root==NULL)
    {
        return newnode(val);
    }
    else if(root->data>val)
    {
        root->left=insert(root->left,val);
    }
    else
    {
        root->right=insert(root->right,val);
    }
    return root;
}
void check(struct node *root, int ar[],int &index)
{
    if(root==NULL)
    {
        return;
    }
    check(root->left,ar,index);
    if(root->data==ar[index])
    {
        index++;
      //  cout<<index<<" is "<<root->data<<endl;
    }
    check(root->right,ar,index);
}

int main()
{
    //int index=0;
    struct node *root=NULL;
    root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 14);
    root = insert(root, 13);
    int ar[]={4,8,10,12};
    
    //cout<<"index is "<<index;
    int n=sizeof(ar)/sizeof(int);
    int index=0;
    check(root,ar,index);
    //cout<<index;
    if(index==n)
    {
        cout<<"yes";
    }
    else
    {
        cout<<"no";
    }
    return 0;

}
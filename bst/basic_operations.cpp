#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *right, *left;
};
struct node *root=NULL;
struct node *insert(struct node *root , int val)
{
    struct node *newnode,*ptr,*parentptr,*nodeptr;
    ptr->data=val;
    ptr->left=NULL;
    ptr->right=NULL;
    if(root==NULL)
    {
        root=ptr;
        root->left=NULL;
        root->right=NULL;
    }
    else
    {
        parentptr=NULL;
        nodeptr=root;
        while(nodeptr->data!=NULL)
        {
            parentptr=nodeptr;
            if(nodeptr->data<val)
            {
                nodeptr=nodeptr->right;
            }
            else
            {
                nodeptr=nodeptr->left;
            }
        }
        if(parentptr->data<val)
            {
                parentptr->right=ptr;
            }
            else
            {
                parentptr->left=ptr;
            }
    }
    return root;
}
struct node *del(struct node *root, int val)
{

}
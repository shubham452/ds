#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};

struct node *newnode(int val)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=temp->right=NULL;
    return temp;
}

struct node *bstfrompostorder(int post[],int *index,int key,int l, int r,int size)
{
    if(*index<0)
    {
        return NULL;
    }
    struct node *root=NULL;
    if(key>l && key<r)
    {
    root=newnode(key);
    *index=*index-1;
    if(*index>=0)
    {
        root->right=bstfrompostorder(post,index,post[*index],key,r,size);
        root->left=bstfrompostorder(post,index,post[*index],l,key,size);
    }
    }   
    return root;    
}
void printInorder (struct node* root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data<< " ";
    printInorder(root->right);
}
int main()
{
    int post[]={1,7,5,50,40,10};
    int n=sizeof(post)/sizeof(post[0]);
    int index=n-1;
    struct node *root= bstfrompostorder(post,&index,post[index],INT_MIN,INT_MAX,n);
    printInorder(root);
    return 0;
}
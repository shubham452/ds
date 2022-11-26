#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};
struct node *newnode(int val)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=temp->right=NULL;
    return temp;
}
struct node *bstfrompre(int ar[],int *index,int key,int l,int r,int size) 
   {
    if(*index>=size)
    {
        return NULL;
    }
    struct node *root=NULL;
    if(key>l && key<r)
    {
        root=newnode(key);
        *index=*index+1;
        if(*index<size)
        {
            root->left=bstfrompre(ar,index,ar[*index],l,key,size);
            root->right=bstfrompre(ar,index,ar[*index],key,r,size);
        }
    }
    return root;
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
    int ar[]={10, 5, 1, 7, 40, 50};
    int size=(sizeof(ar)/sizeof(int));
    int index=0;
    struct node *root=bstfrompre(ar,&index,ar[index],INT_MIN,INT_MAX,size);
    inorder(root);
    return 0;
}
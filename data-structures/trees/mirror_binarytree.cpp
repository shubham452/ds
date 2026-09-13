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
void mirror(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    mirror(root->left);
    mirror(root->right);

    struct node *ptr=root->left;
    root->left=root->right;
    root->right=ptr;
}
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return ;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
int main()
{
    struct node *root=newnode(3);
    root->left=newnode(2);
    root->right=newnode(4);
    root->left->left  = newnode(1);
    root->left->right = newnode(6);
    root->right->right = newnode(5);
    inorder(root);
    mirror(root);
    cout<<"--"<<endl;
    inorder(root);
    return 0;
}
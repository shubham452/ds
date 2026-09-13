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
    ptr->right=ptr->left=NULL;
}
bool isIdentical(struct node *root1, struct node *root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    else if(root1==NULL || root2==NULL)
    {
        return false;
    }
    else
    {
    bool cond1=root1->data==root2->data;
    bool cond2=isIdentical(root1->left,root2->left);
    bool cond3=isIdentical(root1->right,root2->right);
    if(cond1 && cond2 && cond3)
    {
        return true;
    }
    else
    {
        return false;
    }
    }
}
int main()
{
    struct node *root1,*root2;
    root1=newnode(5);
    root1->left=newnode(3);
    root1->right=newnode(10);
    root1->left->right=newnode(4);

    root2=newnode(5);
    root2->left=newnode(1);
    root2->right=newnode(10);
    root2->left->right=newnode(4);
    if(isIdentical(root1,root2))
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    return 0;
}
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
    return ptr;
}
struct node *lca(struct node *root,int n1,int n2)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data>n1 && root->data>n2)
    {
        return lca(root->left,n1,n2);
    }
    if(root->data<n1 && root->data<n2)
    {
        return lca(root->right ,n1,n2);
    }
    return root;
}
int main()
{
    node *root;
    root=newnode(20);
    root->left=newnode(8);
    root->right = newnode(22);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(14);
    int n1=14,n2=8;
    struct node *t;
    t=lca(root,10,14);
    cout<<t->data;
    return 0;
}
/*---------------alternative--------------------

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
struct node *lowestancestor(struct node *root,int a,int b)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data>a && root->data>b)
    {
        return lowestancestor(root->left,a,b);
    }
    if(root->data<a && root->data<b)
    {
        return lowestancestor(root->right,a,b);
    }
    return root;
}
int main()
{
    node *root=NULL;
    root=insert(root,20);
    root=insert(root,8);
    root=insert(root,22);
    root=insert(root,4);
    root=insert(root,12);
    root=insert(root,10);
    root=insert(root,14);
    int n1=14,n2=8;
    struct node *t;
    t=lowestancestor(root,10,14);
    cout<<t->data;
    return 0;
}*/

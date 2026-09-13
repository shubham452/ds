#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
struct node *newnode(int val)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->left=ptr->right=NULL;
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
void store1(struct node *root1, vector<int> &v)
{
    if(root1==NULL)
    {
        return;
    }
    v.push_back(root1->data);
    store1(root1->left,v);
    store1(root1->right,v);
}
void store2(struct node *root2, vector<int> &v)
{
    if(root2==NULL)
    {
        return;
    }
    v.push_back(root2->data);
    store1(root2->left,v);
    store1(root2->right,v);
}
void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}
/*struct node *constructbst(struct node *root)
{
    
}*/
int main()
{
    int i;
    struct node *root=NULL;
    struct node *root1=NULL;
    struct node *root2=NULL;
    root1=insert(root1,3);
    root1=insert(root1,1);
    root1=insert(root1,5);
   // root1=insert(root1,5);
    root2=insert(root2,4);
    root2=insert(root2,2);
    root2=insert(root2,6);
   // root2=insert(root2,10);
    vector<int> v;
    store1(root1,v);
    store2(root2,v);
    int n=v.size();
    for(i=0;i<n;i++)
    {
        root=insert(root,v[i]);
    }
    preorder(root);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *right,*left;
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
    if(root->data>val)
    {
        root->left=insert(root->left,val);
    }
    else if(root->data<val)
    {
        root->right=insert(root->right,val);
    }
    return root;
}
void inorder(struct node *root, vector<int> &v)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,v);
    
    v.push_back(root->data);
    inorder(root->right,v);
}
void preorder(struct node *root, vector<int> v,int *j)
{
    if(root==NULL)
    {
        return;
    }
    root->data=v[++*j];
    preorder(root->left,v,j);
    preorder(root->right,v,j);
}
void bsttomin(struct node *root)
{
    vector<int> v;
    int j=-1;
    cout<<"1"<<endl;
    inorder(root,v);
    cout<<"2"<<endl;
    preorder(root,v,&j);  
    cout<<"3"<<endl;
}
void print(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
int main()
{
    int x;
    struct node *root=NULL;
    cout<<"enter values and -1 to exit"<<endl;
    cin>>x;
    do
    {
        
        root=insert(root,x);
        cin>>x;
    } while (x!=-1);
    cout<<"before"<<endl;
    print(root);
    bsttomin(root);
    cout<<"after"<<endl;
    print(root);
    return 0;
}
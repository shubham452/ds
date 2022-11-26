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
struct node *insert(struct node *root, int key)
{
    if(root==NULL)
    {
        return newnode(key);
    }
    if(key<root->data)
    {
        root->left=insert(root->left,key);
    }
    else
    {
        root->right=insert(root->right,key);
    }
    
    return root;
}
void addgreaterele(struct node *root, int &sum)
{
    if(root==NULL)
    {
        return;
    }
    addgreaterele(root->right,sum);
    sum=sum+root->data;
    root->data=sum;
    addgreaterele(root->left,sum);
}
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    int x,sum=0;
    struct node *root=NULL;
    cout<<" enter values and enter -1 to exit"<<endl;
    cin>>x;
    do
    {
        root=insert(root,x);
        cin>>x;
    }while(x!=-1);
    cout<<"before adding"<<endl;
    inorder(root);
    cout<<endl;
    addgreaterele(root,sum);
    cout<<"after adding"<<endl;
    inorder(root);
}
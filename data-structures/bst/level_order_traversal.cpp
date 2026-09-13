#include <bits/stdc++.h>
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
    if(root->data<key)
    {
        root->left=insert(root->left,key);
    }
    else if(root->data>key)
    {
        root->right=insert(root->right,key);
    }
    return root;
}


void levelorder(struct node *root)
{
    if(root==NULL)
    return;

    queue<struct node*> q;
    q.push(root); 
    while(!q.empty())
    {
        struct node *ptr=q.front();
        cout<<ptr->data<<" ";
        q.pop();
        if(ptr->left!=NULL)
        {
            q.push(ptr->left);
        }
        if(ptr->right!=NULL) 
        {
            q.push(ptr->right);
        }
    }
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
    int x;
    struct node *root=NULL;
    cout<<" enter values and enter -1 to exit"<<endl;
    cin>>x;
    do
    {
        root=insert(root,x);
        cin>>x;
    }while(x!=-1);
    inorder(root);
    cout<<"level order is"<<endl;
    levelorder(root);
    return 0;
}
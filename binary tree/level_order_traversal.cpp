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
void level_order(struct node *root)
{
    queue<struct node*> q;
    if(root==NULL)
    {
        return;
    }
    q.push(root);
    
    while(!q.empty())
    {
        struct node *temp=q.front();
        cout<<temp->data<<endl;
        q.pop();
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
}
int main()
{
    struct node *root=newnode(3);
    root->left=newnode(2);
    root->right=newnode(4);
    root->left->left  = newnode(1);
    root->left->right = newnode(3);
    root->right->right = newnode(5);
    level_order(root);
    return 0;
}
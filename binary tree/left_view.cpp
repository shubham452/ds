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
void left_view(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    queue<struct node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();

        for(int i=1;i<=n;i++)
        {
             struct node *ptr=q.front();
            if(i==1)
            {
                cout<<ptr->data<<endl;
            }
            q.pop();
            if(ptr->left)
            {
                q.push(ptr->left);
            }
            if(ptr->right)
            {
                q.push(ptr->right);
            }
        }
    }
}
int main()
{
    struct node *root=newnode(3);
    root->left=newnode(2);
    root->right=newnode(4);
    root->left->left  = newnode(1);
    root->left->right = newnode(6);
    root->right->right = newnode(5);
    left_view(root);
    return 0;
}
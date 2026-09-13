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
}
void botview(struct node *root)
{
    queue<pair<struct node*,int>> q;
    map<int,int> m;
    if(root==NULL)
    {
        return;
    }
    q.push({root,0});
    while(!q.empty())
    {
        struct node *ptr=q.front().first;
        int h=q.front().second;
        q.pop();
        m[h]=ptr->data;
        if(ptr->left)
        {
            q.push({ptr->left,h-1});
        }
        if(ptr->right)
        {
            q.push({ptr->right,h+1});
        }
    }
    for(auto x:m)
    {
        cout<<x.second<<endl;
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
    botview(root);
    return 0;
}
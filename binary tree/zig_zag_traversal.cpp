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
void zig_zag_traversal(struct node *root)
{
    vector<int> v;
    queue<struct node*> q;
    if(root==NULL)
    {
        return;
    }
    q.push(root);
    int f=1;
    while(!q.empty())
    {  
        int n=q.size();
        vector<int> ptr;
        while(n--)
        {
            struct node *temp=q.front();
            q.pop();
            ptr.push_back(temp->data);
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        if(f%2==0)
        {
            reverse(ptr.begin(),ptr.end());
        }
        for(int i=0;i<ptr.size();i++)
        {
            v.push_back(ptr[i]);
        }
        f++;
    }
    for(int j=0;j<v.size();j++)
    {
        cout<<v[j]<<endl;
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
    zig_zag_traversal(root);
    return 0;
}
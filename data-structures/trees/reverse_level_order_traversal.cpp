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
void reverse_level(struct node *root)
{
    stack<int> st;
    queue<struct node*> q;
    q.push(root);
    while(!q.empty())
    {
        struct node *temp=q.front();
        st.push(temp->data);
        q.pop();
        if(temp->right)
        {
            q.push(temp->right);
        }        
        if(temp->left)
        {
            q.push(temp->left);
        }
    }
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
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
    reverse_level(root);
    return 0;
    
}
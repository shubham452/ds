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
int height(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lheight=height(root->left);
    int rheight=height(root->right);
    return max(lheight,rheight)+1;
}
int diameter(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lheight=height(root->left);
    int rheight=height(root->right);

    int currdiameter=lheight+rheight+1;

    int ldia=diameter(root->left);
   // cout<<root->data<<"    "<<ldia<<endl;
    int rdia=diameter(root->right);
    //cout<<root->data<<"    "<<rdia<<endl;
    return max(currdiameter,max(ldia,rdia));
}   
int main()
{
    struct node *root=newnode(3);
    root->left=newnode(2);
    root->right=newnode(4);
    root->left->left  = newnode(1);
    root->left->right = newnode(6);
    root->right->right = newnode(5);
    cout<<"height is "<<height(root)<<endl;
      cout<<"diameter is "<<diameter(root)<<endl;
    return 0;
}
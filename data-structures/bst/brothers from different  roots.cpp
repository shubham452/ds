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
/*void store(struct node *root,vector<int> &v)
{
    if(root==NULL)
    {
        return;
    }
    store(root->left,v);
    v.push_back(root->data);
    store(root->right,v);
}*/
bool find(struct node *root2,int x)
{
    if(root2==NULL)
    {
        return false;
    }
    if(root2->data==x)
    {
        return true;
    }
    find(root2->left,x);
    find(root2->right,x);
}
void findbrother(struct node *root1,struct node *root2,int sum)
{
    if(root1==NULL)
    {
        return;
    }
    if(find(root2,sum-root1->data)==true)
    {
        //cout<<root1->data<<endl;
       cout<<root1->data<<"  "<<sum-root1->data<<endl;
    }
    findbrother(root2->left,root1,sum);
    findbrother(root2->right,root1,sum);

}
int main()
{
    struct node *root1 = NULL;
    root1 = insert(root1, 8);
    root1 = insert(root1, 10);
    root1 = insert(root1, 3);
    root1 = insert(root1, 6);
    root1 = insert(root1, 1);
    root1 = insert(root1, 5);
    root1 = insert(root1, 7);
    root1 = insert(root1, 14);
    root1 = insert(root1, 13);
 
    // second BST
    struct node *root2 = NULL;
    root2 = insert(root2, 5);
    root2 = insert(root2, 18);
    root2 = insert(root2, 2);
    root2 = insert(root2, 1);
    root2 = insert(root2, 3);
    root2 = insert(root2, 4);
 
    int sum = 10;
    findbrother(root1, root2, sum);
 
    return 0;
}
/*Time Complexity: O(nlogn). This is the complexity of the sorting algorithm which we are using
 after first in-order traversal, rest of the operations take place in linear time.
Auxiliary Space: O(n). Use of data structure ‘array’ to store in-order traversal.*/

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int val)
{
    struct node *nn= new node;
    nn->data=val;
    nn->left=nn->right=NULL;
    return nn;
}
void inorder(node *root, vector<int> &v)
//here &v is used as parameter because any changes in v will be reflected in all v in the program
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
void inorder_bst(struct node *root, vector<int> v,int &i)
{
    if(root==NULL)
    return;
    inorder_bst(root->left,v,i);
    root->data=v[i];
    i++;
    inorder_bst(root->right,v,i);
}
struct node *binarytobst(struct node *root)
{
    vector<int> v;
    inorder(root,v);
    int i=0;
    sort(v.begin(),v.end());
    inorder_bst(root,v,i);
    return root;
}
void print(struct node *root)
{
    if (root == nullptr) {
        return;
    }
 
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}
int main()
{
    struct node *root=newnode(10);
    root->left=newnode(30);
    root->right=newnode(15);
    root->left->left  = newnode(20);
    root->right->right = newnode(5);
    vector<int> v;
    binarytobst(root);
    print(root);
}
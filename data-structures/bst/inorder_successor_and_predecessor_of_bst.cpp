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
    ptr->right=ptr->left=NULL;
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
void presuc(struct node *root, int &pre, int &suc, int key)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data==key)
    {
    
        if(root->left!=NULL)
        {
      
            struct node *tmp=root->left;
        
            while(tmp->right)
            {
                tmp=tmp->right;
            }
            pre=tmp->data;
        
        }
        if(root->right!=NULL)
        {
    
            
            struct node *tmp=root->right;
       
            while(tmp->left)
            {
                tmp=tmp->left;
            }
            suc=tmp->data;
    
        }
    }
    else if(root->data>key)
    {
    
        suc=root->data;
        presuc(root->left,pre,suc,key);
    }
    else
    {

       
        pre=root->data;
        presuc(root->right,pre,suc,key);
    }
   
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    root=insert(root, 30);
    root=insert(root, 20);
    root=insert(root, 40);
    root=insert(root, 70);
    root=insert(root, 60);
    root=insert(root, 80);
   // inorder(root);
    int suc=-1;
    int pre=-1;
    int key=60;
    presuc(root,pre,suc,key);
    cout<<"predecessor is "<<pre<<endl;
    cout<<"successor is "<<suc<<endl;
    return 0;

}
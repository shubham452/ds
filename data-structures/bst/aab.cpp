#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left,*right;
};
struct Node* newNode(int data)
{
    struct Node* ptr = new Node;
    ptr->data = data;
    ptr->left = ptr->right = NULL;
 
    return(ptr);
}
struct info
{
    int size;
    int max;
    int min;
    int ans;
    bool isbst;
};
info largestbstinbt(struct Node *root)
{
    if(root==NULL)
    {
        return{0,INT_MIN,INT_MAX,0,true};
    }
    if(root->left==NULL && root->right==NULL)
    {
        return{1,root->data,root->data,1,true};
       
    }
    info l=largestbstinbt(root->left);
    info r=largestbstinbt(root->right);
    info curr;
    curr.size=(1+l.size+r.size);
    cout<<root->data<<"  "<<curr.ans<<"11"<<endl;
    if(l.isbst && r.isbst && l.max<root->data && r.min>root->data)
    {
        curr.min=min(l.min,min(root->data,r.min));
        curr.max=max(r.max,max(root->data,l.max));
      //  cout<<"cuur ans is"<<curr.ans<<"22"<<endl;
        curr.ans=curr.size;
        
        curr.isbst=true;
        



     //  cout<<root->data<<" a "<<curr.ans<<"11"<<endl;



        return curr;
    }
    
    curr.ans=max(l.ans,r.ans);
    curr.isbst=false;


   // cout<<root->data<<" a "<<curr.ans<<"11"<<endl;
    //cout<<curr.ans<<"22"<<endl;


    return curr;
}
/*void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}*/
int main()
{
   struct Node *root = newNode(60);
    root->left = newNode(59);
    root->right = newNode(70);
    root->left->left = newNode(50);
    //inorder(root);
    cout<<endl;
    cout<<largestbstinbt(root).ans<<endl;
    return 0;
}
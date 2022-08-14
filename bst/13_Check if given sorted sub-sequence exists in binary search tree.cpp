#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};
struct node *newnode(int val)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->right=ptr->left=NULL;
    return ptr;
}
void inorder(struct node *root, vector<int> &v)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
void check(struct node *root, int a[],vector<int> v)
{
    int i,x=0,p=0;
    int n;
    
    n=sizeof(a);
    for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<'\t';
    }
    cout<<endl;
    for(i=0;i<v.size();i++)
    {
        if(v[i]==a[0])
        {
            x=i;
        }
    }
    cout<<"n is "<<n<<endl;

    for(i=0;i<n;i++)
    {
        if(a[i]!=v[x])
        {
            p=-1;
            break;
        }
        x++;
    }
    //cout<<p<<endl;
    if(p==0)
    {
        cout<<"match"<<endl;
    }
    else
    {
        cout<<"dont match"<<endl;
    }
    
}
int main()
{
    int a[]={4,8,10,12};
    
    vector<int> v;
    node *root;
    root=newnode(20);
    root->left=newnode(8);
    root->right = newnode(22);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(14);
    inorder(root,v);
    check(root,a,v);
    return 0;
}
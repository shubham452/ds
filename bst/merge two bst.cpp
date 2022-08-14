#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};
struct node *newnode(int val)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=temp->right=NULL;
    return temp;
}
void bsttoarr1(struct node *root1, vector<int> &v)
{
    if(root1==NULL)
    {
        return;
    }
    bsttoarr1(root1->left,v);
    v.push_back(root1->data);
    bsttoarr1(root1->right,v);
}
void bsttoarr2(struct node *root2, vector<int> &v)
{
    if(root2==NULL)
    {
        return;
    }
    bsttoarr2(root2->left,v);
    v.push_back(root2->data);
    bsttoarr2(root2->right,v);
}
/*void mergelist(int ar1[],int ar2[],vector<int> &v)
{
    int i;
    int n1,n2;
    n1=sizeof(ar1)/sizeof(ar1[0]);
    n2=sizeof(ar2)/sizeof(ar2[0]);
    for(i=0;i<n1;i++)
    {
        v.push_back(ar1[i]);
    }
    for(i=0;i<n2;i++)
    {
        v.push_back(ar2[i]);
    }
    
}*/

struct node *totree(vector<int> v,int start,int end)
{
    sort(v.begin(),v.end());
    if(start>end)
    {
        return NULL;
    }
    int mid=(start+end)/2;
    struct node *root=NULL;
    root=newnode(v[mid]);
    root->left=totree(v,start,mid-1);
    root->right=totree(v,mid+1,end);
    return root;
}
void print(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    print(root->left);
    cout<<root->data<<endl;
    print(root->right);
}
int main()
{
    node *root1 = NULL, *root2 = NULL;
    vector<int> v;
    root1 = newnode(3);
    root1->left = newnode(1);
    root1->right = newnode(5);

    root2 = newnode(4);
    root2->left = newnode(2);
    root2->right = newnode(6);
    bsttoarr1(root1,v);
    bsttoarr2(root2,v);
    /*for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }*/
    struct node *root=totree(v,0,v.size());
    print(root);
    return 0;
}

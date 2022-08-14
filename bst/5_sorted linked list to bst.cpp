#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
    
};
struct linknode
{
    int val;
    struct linknode *next;
    
};

struct linknode *push(struct linknode *start,int y)
{
    
    struct linknode *newnode= (struct linknode*)malloc(sizeof(struct linknode));
    struct linknode *ptr;
    ptr=start;
    newnode->val=y;
    if(start==NULL)
    {
        
        newnode->next=NULL;
        start=newnode;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=NULL;
    }
    return start;
}    
struct node *to_bst(int arr[],int start, int end)
{
    if(start>end)
    {
        return 0;
    }
    int mid=(start+end)/2;
    struct node *root=(struct node*)malloc(sizeof(struct node));
    root->data=arr[mid];
    root->left=to_bst(arr,start,mid-1);
    root->right=to_bst(arr,mid+1,end);
    return root;
}
void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    preorder(root->left);
    cout<<root->data<<endl;
    preorder(root->right);
}
int main()
{
    int n;
    cout<<"enter the size of list"<<endl;
    cin>>n;
    int arr[n];
    struct node *root=NULL;
    struct linknode *start=NULL;
    start=push(start,2);
    start=push(start,3);
    start=push(start,4);
    start=push(start,5);
    start=push(start,6);
    int x=0;
        struct linknode *ptr;
        ptr=start;
        if(start!=NULL)
        
        {
        while(ptr!=NULL)
        {
            arr[x]=ptr->val;
            ptr=ptr->next;
            
        }
    }
    root=to_bst(arr,0,n-1);
    preorder(root);
    return 0;
} 
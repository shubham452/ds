#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *left, *right;
};
struct linknode
{
	int key;
	struct linknode *next;
};
struct linknode *insert(struct linknode *start, int val)
{
	struct linknode *temp= (struct linknode*)malloc(sizeof(struct linknode));
	temp->key=val;
	struct linknode *ptr=start;
	if(start==NULL)
	{
		temp->next=NULL;
		start=temp;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
		temp->next=NULL;
	}
	return start;
}
struct node *tobst(vector<int> v,int start, int end)
{
	if(start>end)
	{
		return NULL;
	}
		int mid=(start+end)/2;
		struct node *root=(struct node*)malloc(sizeof(struct node));
		root->data=v[mid];
		root->left=tobst(v,start,mid-1);
		root->right=tobst(v,mid+1,end);
	    return root;
}
void preorder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<endl;
	preorder(root->left);
	
	preorder(root->right);
}
int main()
{
	vector<int> v;
	struct node *root=NULL;
	struct linknode *start=NULL;
	
	
	start=insert(start,7);
	start=insert(start,6);
	start=insert(start,5);
	start=insert(start,4);
	start=insert(start,3);
	start=insert(start,2);
	start=insert(start,1);
	//start=insert(start,50);
	struct linknode *p=start;
	//cout<<p->next->key<<endl;
	if(start!=NULL)
	{	
		//cout<<ptr->key<<endl;
	while(p!=NULL)
	{
		
		//cout<<p->key<<endl;
		v.push_back(p->key);
		p=p->next;
		
	}
	}
	//cout<<1<<endl;
	sort(v.begin(),v.end());
	//cout<<v[4];
	root=tobst(v,0,v.size()-1);
	preorder(root);
	//cout<<root->data;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct queu
{
    struct node *front;
    struct node *rear;
};
struct queu *q;
void creat(struct queu *q)
{
    q->front=NULL;
    q->rear=NULL;
}
struct queu *insert(struct queu *q,int val)
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    if(q->front==NULL)
    {
        q->front=ptr;
        q->rear=ptr;
        q->front->next=q->rear->next=NULL;
    }
    else
    {
        q->rear->next=ptr;
        q->rear=ptr;
        q->rear->next=NULL;
    }
    return q;
}
struct queu *display(struct queu *q)
{
    struct node *ptr;
    ptr=q->front;
    if(q->front==NULL)
    {
        cout<<"queue is empty"<<endl;
    }
    else{
    while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
    }
    return q;
}
struct queu *del(struct queu *q)
{
    struct node *ptr;
    ptr=q->front;
    if(q->front==NULL)
    {
        cout<<"q is empty"<<endl;
    }
    else{
        q->front=q->front->next;
        cout<<"value to be deleted is "<<ptr->data<<endl;
    }
    return q;
}
void peek(struct queu *q)
{
    if(q->front ==NULL)
    {
        cout<<"queue is empty"<<endl;
    }
    else
    {
        cout<<q->front->data<<endl;
    }
}
int main()
{
    int val,option;
    cout<<"aaa";
   // creat(q);
    cout<<"aaa";
    
        cout<<"0 to create, 1 to insert, 2 to display, 3 to pop ,4 to peep and 5 to quit"<<endl;
        cin>>option;
        while(option!=5)
        {
        switch(option)
        {
            case 0:
                creat(q);
                break;
            case 1:
                cout<<"enter a value"<<endl;
                cin>>val;
                q=insert(q,val);
                break;
            case 2:
                q=display(q);
                break;
            case 3:
                q=del(q);
                break;
            case 4:
                peek(q);
                break;            
        }
        cout<<"0 to create, 1 to insert, 2 to display, 3 to pop ,4 to peep and 5 to quit"<<endl;
        cin>>option;
    }
    return 0;
}
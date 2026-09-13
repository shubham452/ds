#include<bits/stdc++.h>
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
void create(struct queu *q)
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
    struct queu *dele(struct queu *q)
    {
        if(q->front==NULL)
        {
            cout<<"queue is empty"<<endl;
        }
        else
        {
            q->front=q->front->next;
            cout<<"deletion done"<<endl;
        }
        return q;
    }
    struct queu *display(struct queu *q)
    {
        struct node *ptr;
        ptr=q->front;
        while(ptr->next!=NULL)
        {
            cout<<ptr->data<<endl;
            ptr=ptr->next;
        }
        return q;
    }
    

int main()
{
    int ch,k;
    cout<<"enter 0 to create ,enter 1 to insert ,2 to del, 3 to display and 4 to exit"<<endl;
    cin>>ch;
    //create(q);
    while(ch!=4)
    {
        cout<<"aa"<<endl;
    switch(ch)
    {
        case 0:
            create(q);
            break;
        case 1:
            cout<<"enter the value"<<endl;
            cin>>k;
            q=insert(q,k);
            break;
        case 2:
            q=dele(q);
            break;
        case 3:
            q=display(q);
            break;        
    }
    cout<<"enter choice"<<endl;
    cin>>ch; 
    }
    return 0;
}
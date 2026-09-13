#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;
struct node *push(struct node *top, int val)
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    if(top==NULL)
    {
        ptr->next=NULL;
        top=ptr;
    }
    else
    {
        ptr->next=top;
        top=ptr;
    }
    return top;
}
struct node *display(struct node *top)
{
    struct node *ptr;
    ptr=top;
    if(top==NULL)
    {
        cout<<"stack is empty"<<endl;
    }
    else{
    while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
    }
    return top;
}
struct node *pop(struct node *top)
{
    struct node *ptr;
    ptr=top;
    if(top==NULL)
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        top=top->next;
        cout<<"value to be deleted is "<<ptr->data<<endl;
    }  
    return top;  
}

void *peek(struct node *top)
{
    if(top==NULL)
    {
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"top value is "<<top->data<<endl;
    }
}
int main()
{
    int option,val;
    do
    {
    cout<<"1 to push, 2 to display, 3 to pop, 4 to peek and 5 to exit"<<endl;
    cin>>option;
    switch(option)
    {
        case 1:
            cout<<"Enter a value"<<endl;
            cin>>val;
            top=push(top,val);
            break;
        case 2:
            top=display(top);
            break;
        case 3:
            top=pop(top);
            break;
        case 4:
            peek(top);
            break;
    }
    }while(option !=5);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n=100;
int ar[100];
int top=-1;
    
void push(int x)
{
    if(top>=n)
    {
        cout<<"stack overflow"<<endl;
    }
    else
    {
        top++;
        ar[top]=x;
    }
}
void pop()
{
    if(top==-1)
    {
        cout<<"Stack underflow"<<endl;
    }
    else
    {
        top--;
    }
}
void display()
{
    for(int i=0;i<=top;i++)
    {
        cout<<ar[i]<<endl;
    }
}
int main()
{
    int ch;
    cout<<"enter choice"<<endl;
    cin>>ch;
    while(ch!=-1)
    {
        //cin>>ch;
        switch (ch)
        {
        case 1:
            int x;
            cout<<"enter the value"<<endl;
            cin>>x;
            push(x);
        break;
        case 2:
            pop();
        break;
        case 3:
            display();
        break;
        default:
        break;
        }
        cout<<"enter choice"<<endl;
        cin>>ch;

    }
    return 0;
}
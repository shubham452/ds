#include<bits/stdc++.h>
using namespace std;
class twostack
{
    int *ar;
    int top1,top2,n;
    public:
    twostack(int n)
    {
        ar=new int[n];
        top1=0;
        top2=n-1;
    }
    void push1(int x)
    {
        if(top1<=(n/2))
        {
            ar[top1]=x;
        }
        top1++;
    }
     void push2(int x)
    {
        if(top2<n)
        {
            ar[top2]=x;
        }
        top1--;
    }

    int pop1()
    {
        if(top1==0)
        {
            cout<<"Stack underflow"<<endl;
        }
        else
        {
            return ar[top1];
            top1--;
        }
    }
    int pop2()
    {
        if(top2==n)
        {
            cout<<"Stack underflow"<<endl;
        }
        else
        {
            return ar[top2];
            top2++;
        }
    }
};
int main()
{
    twostack ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is "
         << " : " << ts.pop1()
         << endl;
    ts.push2(40);
    cout << "\nPopped element from stack2 is "
         << ": " << ts.pop2()
         << endl;
    return 0;


}
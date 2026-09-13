#include<bits/stdc++.h>
using namespace std;

class minelement
{
    stack<int> st;
    int minele;
    public:
    void push(int x)
    {
        if(st.empty())
        {
            minele=x;
            st.push(x);
            
        }
        else if(x < minele)
        {
            st.push(2*x-minele);
            minele=x;
        }
        else
        {
            st.push(x);
        }
        cout<<"number inserted "<<x<<endl;
    }

    void pop()
    {
        if(st.empty())
        {
            cout<<"stack underflow"<<endl;
            return;
        }
        int t=st.top();
        st.pop();
        if(t < minele)
        {
           // cout<<"t is "<<t<<" and minele is "<<minele<<endl;
            cout<<"popped element is "<<minele<<endl;
            minele=2*minele-t;
        }
        else
        cout<<"popped element is "<<t<<endl;
    }
    void minvalue()
    {
        cout<<"minimum value is "<<minele<<endl;
    }
};
int main()
{
    minelement s;
    s.push(3);
    s.push(5);
    s.minvalue();
    s.push(2);
    s.push(1);
    s.minvalue();
    s.pop();
    s.minvalue();
    s.pop();
    return 0;
}
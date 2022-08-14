#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;
    int i,n,check=1;
    string str;
    cin>>str;
    n=str.length();
    for(i=0;i<n;i++)
    {
        if(str[i]=='{' || str[i]=='(' || str[i]=='[' )
        {
            st.push(str[i]);
        }
        else if(str[i]=='}')
        {
            if(st.top()=='{')
            {
                st.pop();
            }
            else
            {
                check =0;
            }    
        }
        else if(str[i]==')')
        {
            if(st.top()=='(')
            {
                st.pop();
            }
            else
            {
                check =0;
            }    
        }
        else if(str[i]==']')
        {
            if(st.top()=='[')
            {
                st.pop();
            }
            else
            {
                check= 0;
            }    
        }
        else if(st.empty())
        {
            check= 0;
        }
    }
    if(check==1)
    {
        cout<<"balanced";
    }
    else
    {
        cout<<"not balanced";
    }
    
    return 0;
}
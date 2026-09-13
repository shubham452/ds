#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<char> st;
    int i,n;
    string s="()(()))))";
    n=s.size();
    int result=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            st.push('(');
        }
        else if(!st.empty() && s[i]==')')
        {
            if(st.top()=='(')
            {
                st.pop();
                result+=2;
            }
        }
    }
    cout<<result;
    return 0;
}
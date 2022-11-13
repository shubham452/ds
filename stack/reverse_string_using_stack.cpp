#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    stack<char> st;
    string s="shubham kumar";
    for(i=0;i<s.size();i++)
    {
        st.push(s[i]);
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    return 0;
}
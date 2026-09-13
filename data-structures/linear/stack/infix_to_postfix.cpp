#include<bits/stdc++.h>
using namespace std;
int prec(char c)
{
    if(c=='^')
    return 5;
    else if(c=='/' || c=='*' || c=='%')
    return 4;
    else if(c=='+'|| c=='-')
    return 3;
    else
    return 2;
}
void intopo(string s)
{
    int i;
    string result;
    stack<char> st;
    for(i=0;i<s.length();i++)
    {
        char c=s[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            result +=c;
        }
        else if(c=='(')
        {
            st.push('(');
        }
        else if(c==')')
        {
            while(st.top()!='(')
            {
                result +=st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if(!st.empty() && prec(s[i])<=prec(st.top()))
            {
                result +=st.top();
                st.pop();
            }
            st.push(s[i]);
        }   
    }
    while(!st.empty())
    {
        result +=st.top();
        st.pop();
    }
    cout<<result;
}
int main()
{
    string sl;
    sl="a+b*(c^d-e)^(f+g*h)-i";
    intopo(sl);
    return 0;
}
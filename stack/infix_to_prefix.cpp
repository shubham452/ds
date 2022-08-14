
#include<bits/stdc++.h>
using namespace std;
int pre(char ch)
{
    if(ch=='+' || ch=='-')
    {
        return 1;
    }
    else if(ch=='/' || ch=='*')
    {
        return 2;
    }
    else if(ch=='^' || ch=='%')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
string reverse(string st)
{
    string var;
    
    for(int i=st.length()-1;i>=0;i--)
    {
        if(st[i]=='(')
        {
            var+=')';
        }
        else if(st[i]==')')
        {
            var+='(';
        }
        else
        {
            var+=st[i];
        }
    }
    return var;
}
string infix_to_pretfix(string infix)
{
   // cout<<infix;
    int i;
    stack<char> st;
    char ch;
    string output;
    for(i=0;i<infix.length();i++)
    {
        ch=infix[i];
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            output +=ch;
       //     cout<<output<<endl;
        }
        else if(ch=='(')
        {
            st.push('(');
        }
        else if(ch==')')
        {
            while(st.top()!='(')
            {
                output+=st.top();
            //    cout<<output<<endl;
                st.pop();
            }
            st.pop();
        }
        else
        {
            if(!st.empty() && pre(ch)<=pre(st.top()))
            {
                output+=st.top();
              //  cout<<output<<endl;
                st.pop();
            }
            st.push(ch);
        }
        
    }
    while(!st.empty())
    {
        output+=st.top();
     //  cout<<output<<endl;
        st.pop();
    }
    output=reverse(output);
   // cout<<output;
    return output;
}
int main()
{
    string sl;
    sl="A*B+C/D";
    sl=reverse(sl);
   // cout<<sl;
    cout<<infix_to_pretfix(sl);
    return 0;
}
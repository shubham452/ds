#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    stack<int> st,temp;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    n=st.size();
    for(i=0;i<(n/2);i++)
    {
        temp.push(st.top());
        st.pop();
    }
   // cout<<st.top();
    st.pop();
    while(!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
    for(i=0;i<n-1;i++)
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}
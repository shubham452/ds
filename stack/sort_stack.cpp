/*Time Complexity: O(n2) where n is the total number of integers in the given stack.
Auxiliary Space: O(n)*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    stack<int> st,temp;
    st.push(34);
    st.push(3);
    st.push(31);
    st.push(98);
    st.push(92);
    st.push(23);
    n=st.size();
    while(temp.size()!=n)
    {
        if(temp.empty())
        {
            temp.push(st.top());
            st.pop();
        }
        else if(temp.top()<=st.top())
        {
            temp.push(st.top());
            st.pop();
        }
        else
        {
            int k=st.top();
            st.pop();
            while(!temp.empty() && temp.top()>k)
            {
                st.push(temp.top());
                temp.pop();
            }
            temp.push(k);
        }
    }
    while(!temp.empty())
    {
        cout<<temp.top()<<endl;
        temp.pop();
    }
    return 0;
    
}
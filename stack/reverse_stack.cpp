/*Time Complexity : O(N)
Where n is the total number of elements.

Space Complexity: O(N)
As we have to create a Queue
 of N elements to reverse the original stack.*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    stack<int> st;
    queue<int> q;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    n=st.size();
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    for(i=0;i<n;i++)
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int>st,index;
    int i,n;
    cin>>n;
    int ar[n],out[n];
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    for(i=0;i<n;i++)
    {
        if(st.empty())
        {
            out[i]=1;
            st.push(ar[i]);
            index.push(i);
        }
        else if(st.top()>ar[i])
        {
            st.push(ar[i]);
            index.push(i);
            out[i]=1;
        }
        else if(!st.empty() && st.top()<=ar[i])
        {
            while(!st.empty() && st.top()<=ar[i])
            {
                st.pop();
                index.pop();
            }
            out[i]=i-index.top();
            st.push(ar[i]);
            index.push(i);
            
        }
    }
    for ( i = 0; i < n; i++)
    {
        cout<<out[i]<<'\t';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    int ar[]={6,2,5,4,5,1,6};
    n=sizeof(ar)/sizeof(int);
    int ans[n];
    stack<int> st,index;
    for(i=n-1;i>=0;i--)
    {
        if(st.empty())
        {
            st.push(ar[i]);
            index.push(i);
            ans[i]=n;
        }
        else if (!st.empty() && st.top()>ar[i])
        {
            st.push(ar[i]);
            index.push(i);
            ans[i]=i+1;
        }
        else if(!st.empty() && st.top()<=ar[i])
        {
            while(!st.empty() && st.top()<=ar[i])
            {
                st.pop();
                index.pop();
            }
            if(st.empty())
            {
                ans[i]=n;
            }
            else
            {
                ans[i]=index.top();
            }
            st.push(ar[i]);
            index.push(i);
    }
    
}
for(i=0;i<n;i++) 
    {
        cout<<ans[i]<<"   ";
    }
}
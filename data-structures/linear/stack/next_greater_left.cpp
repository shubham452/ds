#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;
    int n,i;
    cout<<"enter total values"<<endl;
    cin>>n;
    int ar[n],out[n];
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    memset(out,n,0);
    for(i=0;i<n;i++)
    {
        if(st.empty())
        {
            out[i]=-1;
            st.push(ar[i]);
        }
        else if(!st.empty() && st.top()>ar[i])
        {
            out[i]=st.top();
            st.push(ar[i]);
        }
        else if(!st.empty() && st.top()<=ar[i])
        {
            while(!st.empty() && st.top()<=ar[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                out[i]=-1;
            }
            else
            {
                out[i]=st.top();
            }
            st.push(ar[i]);
        }
    }
    for ( i = 0; i < n; i++)
    {
        cout<<out[i]<<'\t';
    }
    return 0;
}
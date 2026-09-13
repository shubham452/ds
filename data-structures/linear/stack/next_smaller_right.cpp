#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;
    int n,i;
    cout<<"enter no. of elements"<<endl;
    cin>>n;
    int ar[n],out[n];
    memset(out,n,0);
    cout<<"enter the values"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    for ( i = n-1; i >=0; i--)
    {
        if(st.empty())
        {
            st.push(ar[i]);
            out[i]=-1;
        }
        else if(!st.empty() && st.top()<ar[i])
        {
            out[i]=st.top();
            st.push(ar[i]);
        }
        else if(!st.empty() && st.top()>=ar[i])
        {
            while(!st.empty() && st.top()>=ar[i])
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
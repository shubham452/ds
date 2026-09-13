#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;
    int n,i;
    cout<<"enter total values"<<endl;
    cin>>n;
    int ar[n],output[n];
    memset(output,n,0);
    cout<<"enter the values"<<endl;
    for ( i = 0; i < n; i++)
    {
        cin>>ar[i];
    }
    for(i=n-1;i>=0;i--)
    { 
        if(st.empty())
        {
            output[i]=-1;
            st.push(ar[i]);
        }
        else if(!st.empty() && st.top()>ar[i])
        {
            output[i]=st.top();
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
                output[i]=-1;
            }
            else
            {
                output[i]=st.top();
            }
            st.push(ar[i]);
        }
    }
    for ( i = 0; i < n; i++)
    {
        cout<<output[i]<<'\t';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st,index;
    int n,i;
    cout<<"enter no. of inputs"<<endl;
    cin>>n;
    int out[n],ar[n];
    //memset(out,n,0);
    for (i = 0; i < n; i++)
    {
        cin>>ar[i];
    }
    
    for(i=0;i<n;i++)
    {
        if(st.empty())
        {
            st.push(ar[i]);
            out[i]=1;
            index.push(i);
            cout<<i<<" "<<out[i]<<endl;
        }
        else if(!st.empty() && st.top()>ar[i])
        {
            out[i]=i-index.top();
            st.push(ar[i]);
            index.push(i);
            cout<<i<<" "<<out[i]<<endl;
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
                out[i]=i+1;
            }
            else
            {
                out[i]=i-index.top();
            }
            
            st.push(ar[i]);
            index.push(i);
            cout<<i<<" "<<out[i]<<endl;
        }
        //cout<<"pos is "<<pos<<endl;
    }
    for ( i = 0; i < n; i++)
    {
        cout<<out[i]<<'\t';
    }
    return 0;
    
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    int ar[]={6,2,5,4,5,1,6};
    stack<int>st,index;
    n=sizeof(ar)/sizeof(int);
    int ans[n];
    for(i=0;i<n;i++)
    {
        if(st.empty())
        {
            st.push(ar[i]);
            index.push(i);
            ans[i]=-1;
            
        }
        else if(!st.empty() && st.top()<ar[i])
        {
            
            st.push(ar[i]);
            index.push(i);
            ans[i]=i-1;
        }
        else if(!st.empty() && st.top()>=ar[i])
        {
            
            while(!st.empty() && st.top()>=ar[i] )
            {
                st.pop();
                index.pop();
                
            }

            if(st.empty())
            {
                
                ans[i]=-1;
                
                 
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
    return 0;
}
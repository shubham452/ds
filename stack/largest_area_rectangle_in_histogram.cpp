#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st1,st2,index_left,index_right;
    int n,i;
    cout<<"enter no. of inputs"<<endl;
    cin>>n;
    int ar[n],out_left[n],out_right[n];
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    for(i=0;i<n;i++)
    {
        if(st1.empty())
        {
            st1.push(ar[i]);
            index_left.push(i);
            out_left[i]=index_left.top();
        }
        else if(!st1.empty() && st1.top()<ar[i])
        {
            st1.push(ar[i]);
            out_left[i]=index_left.top();
            index_left.push(i);
            
        }
        else if(!st1.empty() && st1.top()>=ar[i])
        {
            while(!st1.empty() && st1.top()>=ar[i])
                {
                    st1.pop();
                    index_left.pop();
                }    
            if(st1.empty())
            {
                index_left.push(i);
                out_left[i]=index_left.top();
            }
            else
            {
                out_left[i]=index_left.top();
                index_left.push(i);
            }    
        }
    }
    for ( i = 0; i < n; i++)
    {
        cout<<out_left[i]<<'\t';
    }
    return 0;
}
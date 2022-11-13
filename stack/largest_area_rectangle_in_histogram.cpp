#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    int ar[]={6, 2, 5, 4, 5, 1, 6};
    int max=INT_MIN;
    n=sizeof(ar)/sizeof(int);
    stack<int> st1,index1,st2,index2;
    int ans1[n],ans2[n];
    for(i=0;i<n;i++)
    {
        if(st1.empty())
        {
            ans1[i]=-1;
            st1.push(ar[i]);
            index1.push(i);
        }
        else if (!st1.empty() && st1.top()<ar[i])
        {
            st1.push(ar[i]);
            index1.push(i);
            ans1[i]=i-1;   
        }
        else if(!st1.empty() && st1.top()>=ar[i])
        {
            while(!st1.empty() && st1.top()>=ar[i])
            {
                st1.pop();
                index1.pop();
            }
            if(st1.empty())
            {
                ans1[i]=-1;
            }
            else
            {
                ans1[i]=index1.top();
            }
            st1.push(ar[i]);
            index1.push(i);
        }
    }
    for(i=n-1;i>=0;i--)
    {
        if(st2.empty())
        {
            ans2[i]=n;
            st2.push(ar[i]);
            index2.push(i);
        }
        else if (!st2.empty() && st2.top()<ar[i])
        {
            st2.push(ar[i]);
            index2.push(i);
            ans2[i]=i+1;   
        }
        else if(!st2.empty() && st2.top()>=ar[i])
        {
            while(!st2.empty() && st2.top()>=ar[i])
            {
                st2.pop();
                index2.pop();
            }
            if(st2.empty())
            {
                ans2[i]=n;
            }
            else
            {
                ans2[i]=index2.top();
            }
            st2.push(ar[i]);
            index2.push(i);
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<ans1[i]<<"  ";
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<ans2[i]<<"  ";
    }
    int val;
    for(i=0;i<n;i++)
    {
        val=((i-ans1[i]-1)+(ans2[i]-i-1)+1)*ar[i];
        if(val>max)
        {
            max=val;
        }
    }
    cout<<"ans is "<<max;
    return 0;
}
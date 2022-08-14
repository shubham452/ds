#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int> l;
    int i,n;
    cout<<"enter total inputs"<<endl;
    cin>>n;
    int a[n];
    int k;
    cout<<"enter window size"<<endl;
    cin>>k;
    cout<<"enter values"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<k;i++)
    {    
        if(a[i]<0)
        {
            l.push_back(a[i]);
        }
    }

    
    int left=1,right=k-1;
    for(i=k;i<n;i++)
    {
        if(l.empty())
        {
            cout<<"0"<<" ";
        }
        else
        {
            cout<<l.front()<<" ";
        }
        while(!l.empty() && left<i)
        {
            l.pop_front();
        }
        if(a[i]<0)
        {
            l.push_back(a[i]);
        }
        
    }
    return 0;
}
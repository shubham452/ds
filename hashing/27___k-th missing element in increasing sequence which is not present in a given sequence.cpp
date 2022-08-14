#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<int> u;
    int n1,n2,i;
    cout<<"enter length of first array"<<endl;
    cin>>n1;
    int a1[n1];
    cout<<"enter values"<<endl;
    for(i=0;i<n1;i++)
    {
        cin>>a1[i];
    }
    cout<<"enter length of second array"<<endl;
    cin>>n2;
    int a2[n2],k,out[n1],p=0;
    cout<<"enter values"<<endl;
    for(i=0;i<n2;i++)
    {
        cin>>a2[i];
        u.insert(a2[i]);
    }
    cout<<"enter index"<<endl;
    cin>>k;
    for(i=0;i<n1;i++)
    {
        if(u.find(a1[i])==u.end())
        {
            out[p]=a1[i];
            p++;
        }
    }
    cout<<out[k-1]<<endl;
    return 0;
}
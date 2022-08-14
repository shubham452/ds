#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<int,int> mp;
    int n,m,i,j;
    cout<<"enter rows and column"<<endl;
    cin>>n>>m;
    int a[n][m];
    cout<<"enter values"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>a[i][j];
            mp[a[i][j]]=i;
        }    
    }
    int sum,val;
    cout<<"enter sum"<<endl;
    cin>>sum;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            val=sum-a[i][j];
            if(mp.find(val)!=mp.end() && mp[val]>i )
            {
                cout<<a[i][j]<<"  "<<val<<endl;
            }
        }
    }
    return 0;
}    
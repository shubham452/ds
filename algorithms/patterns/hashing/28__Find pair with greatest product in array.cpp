#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cout<<"enter size of input"<<endl;
    cin>>n;
    int a[n],val;
    unordered_map<int,int> mp;
    cout<<"enter values"<<endl;
    for ( i = 0; i < n; i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(a,a+n);
    for(i=n-1;i>=1;i--)
    {
        for(j=0;j<i && a[j]<=sqrt(a[i]);j++)
        {
            if(a[i]%a[j]==0)
            {
                val=a[i]/a[j];
            
            if(val!=a[j] && mp[val]>0)
            {
                cout<<a[i]<<endl;
            }
            else if(val==a[j] && mp[val]>1)
            {
                cout<<a[i]<<endl;
            }
            }
        }
    }

    return 0;
}
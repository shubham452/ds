#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    cout<<"enter length"<<endl;
    cin>>n;
    int a[n];
    unordered_map<int,int> mp;
    pair<int,int> x,y,z;
    x.second=y.second=z.second=INT_MIN;
    cout<<"enter values"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    for(auto curr:mp)
    {
        cout<<curr.first<<"  "<<curr.second<<endl;
    }
    cout<<"------"<<endl;
    for(auto curr:mp)
    {
        if(x.second<curr.second)
        {
            z=y;
            y=x;
            x.first=curr.first;
            x.second=curr.second;
            cout<<"first"<<endl;
            cout<<curr.first<<"  "<<curr.second<<endl;
        }
        else if(y.second<curr.second)
        {
            z=y;
            y.first=curr.first;
            y.second=curr.second;
            cout<<"second"<<endl;
            cout<<curr.first<<"  "<<curr.second<<endl;
        }
        else if(z.second<curr.second)
        {
            z.first=curr.first;
            z.second=curr.second;
            cout<<"third"<<endl;
            cout<<curr.first<<"  "<<curr.second<<endl;
        }
    }
    cout<<"largest frequency is of 3 are "<<x.first<<"  "<<y.first<<"  "<<z.first;
    return 0;
}    
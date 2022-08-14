#include<bits/stdc++.h>
using namespace std;
struct item
{
    string name;
    int price;
};
int main()
{
    int n1,n2,i;
    cout<<"enter no of items in first list"<<endl;
    cin>>n1;
    cout<<"enter no of items in second list"<<endl;
    cin>>n2;
    struct item l1[n1],l2[n2];
    unordered_map<string,int> mp;
    for(i=0;i<n1;i++)
    {
        cin>>l1->name;
        cin>>l1->price;
        mp[l1[i]->name]=l1[i]->price;
    }
    for(i=0;i<n2;i++)
    {
        cin>>l2[i]->name;
        cin>>l2[i]->price;
        //mp[l2[i].name]=l2[i].price;
    }
    int count=0;
    for(i=0;i<n2;i++)
    {
        if((mp.find(l2[i].name)!=mp.end()) && mp[l2[i].name]!=l2[i].price)
        {
            cout<<"  "<<l2[i]->price<<endl;
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> l1;
    string x;
    unordered_set<string> st;
    int i,n1,n2;
    cout<<"enter size of both inputs"<<endl;
    cin>>n1>>n2;
    cout<<"enter 1st values"<<endl;
    for(i=0;i<n1;i++)
    {
        cin>>x;
        l1.push_back(x);
    }
    for(i=0;i<n1;i++)
    {
        cin>>x;
        st.insert(x);
    }

    for(i=0;i<n1;i++)
    {
        if(st.find(l1[i])!=st.end())
        {
            cout<<l1[i]<<endl;
        }
    }  
    return 0;
    
}
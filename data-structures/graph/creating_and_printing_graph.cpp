#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,v,e,n,m;
    cout<<"enter no. of vertex and edge"<<endl;
    cin>>v>>e;
    //
    vector<int> adj[v+1];
    cout<<"enter edges"<<endl;
    for(i=0;i<e;i++)
    {
        cin>>n>>m;
        adj[n].push_back(m);
        adj[m].push_back(n);
    }
    for(i=0;i<v;i++)
    {
        cout<<i<<"-> ";
        for(j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
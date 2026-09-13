#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
bool vis[N];
vector<int> adj[N];
int main()
{
    int i,n,m,x,y,r;
    for(i=0;i<N;i++)
    {
        vis[i]=0;
    }
    cout<<"enter no of nodes and edges"<<endl;
    cin>>n>>m;
    cout<<"enter edges"<<endl;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    cout<<"enter first node"<<endl;
    cin>>r;
    q.push(r);
    vis[r]=1;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        cout<<p<<endl;
        vector<int>::iterator it;
        for(it=adj[p].begin();it!=adj[p].end();it++)
        {
            if(!vis[*it])
            {
                vis[*it]=1;
                q.push(*it);
            }
        }
    }
    return 0;
}
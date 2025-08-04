#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int> adj[],int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool iscyclic(int src,vector<int> adj[],int vis[])
{
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty())
    {
    int node=q.front().first;
    int parent=q.front().second;
    q.pop();
    for(auto ptr: adj[node])
    {
        if(vis[ptr]!=1)
        {
            vis[ptr]=1;
            q.push({ptr,node});
        }
        else if(parent!=ptr)
        {
            return true;
        }
    }
    }
    return false;
}
bool checkcycle(int v, vector<int> adj[])
{
    int i;
    int vis[v]={0};
    for(i=0;i<v;i++)
    {
        if(vis[i]!=1)
        {
            if(iscyclic(i,adj,vis))
            {
                return true;
            }
        }
        
    }
    return false;
}
int main()
{
    int x,y,i,v;
    cout<<"enter no. of vertices";
    cin>>v;
    vector<int> adj[v];
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,2,0);
    addedge(adj,2,3);
    if(checkcycle(v,adj))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    return 0;

}
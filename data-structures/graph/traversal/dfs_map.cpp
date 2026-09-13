#include<bits/stdc++.h>
using namespace std;
void adjList(unordered_map<int, vector<int>> &adj)
{
    int x,y,m;
    cout<<"enter no. of edges"<<endl;
    cin>>m;
    cout<<"enter edges"<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

}
void dfs(unordered_map<int, vector<int>> adj, unordered_map<int,bool> &vis, int start )
{
    
    vis[start]=true;
    cout<<start<<endl;
    for(auto it=adj[start].begin();it!=adj[start].end();it++)
    {
        if(!vis[*it])
        {
            vis[*it]=true;
            dfs(adj,vis,*it);
        }
    }
}
int main()
{
    int s;
    unordered_map<int, vector<int>> adj;
    unordered_map<int,bool> vis;
    adjList(adj);
    cout<<"enter the starting node"<<endl;
    cin>>s;
    dfs(adj,vis,s);
    return 0;
    
}
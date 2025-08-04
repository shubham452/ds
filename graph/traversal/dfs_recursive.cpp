#include<bits/stdc++.h>
using namespace std;
void dfs(int vertex, vector<int> adj[],unordered_map<int,bool> &visited, vector<int> &ans)
{
    ans.push_back(vertex);
    visited[vertex]=true;
    for(auto x:adj[vertex])
    {
        if(!visited[x])
        {
            dfs(x,adj,visited,ans);
        }
    }
}
int main()
{
    int v,e,i,j,x,y,start;
    cout<<"Enter vertex and edges"<<endl;
    vector<int> ans;
    cin>>v>>e;

    vector<int> adj[v];
    unordered_map<int,bool> vis;
    cout<<"enter edges"<<endl;
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<"enter the starting node"<<endl;
    cin>>start;
    for(i=0;i<v;i++)
    {
        if(!visited[i])
        {
            
        }
    }
    dfs(start,adj,visited,ans);


}
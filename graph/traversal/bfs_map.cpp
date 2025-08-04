#include<bits/stdc++.h>
using namespace std;

void adjList(unordered_map<int,vector<int>> &adj)
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

int main()
{
    int p,s;
    unordered_map<int,vector<int>> adj;  // Changed list<int> to vector<int>
    vector<int> ans;
    unordered_map<int, bool> visited;
    adjList(adj);
    queue<int> q;
    cout<<"enter starting node"<<endl;
    cin>>s;
    q.push(s);
    visited[s]=true;
    
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        cout<<p<<endl;
        for(auto it=adj[p].begin();it!=adj[p].end();it++)  // This remains unchanged
        {
            if(!visited[*it])
            {
                q.push(*it);
                visited[*it]=true;
            }
        }
    }

    return 0;
}

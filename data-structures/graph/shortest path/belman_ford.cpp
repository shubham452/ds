#include<bits/stdc++.h>
using namespace std;
const int INF=1e7;
int main()
{
    int v,e,i,src;
    cout<<"enter no. of vertices and edges"<<endl;
    cin>>v>>e;
    vector<vector<int>> edge;
    vector<int> dist(v,INF);
    for(i=0;i<e;i++)
    {
        cout<<"enter starting point ,end point and distance between the two"<<endl;
        int u,v,w;
        cin>>u>>v>>w;
        edge.push_back({u,v,w});
    }
    cout<<"enter the starting point"<<endl;
    cin>>src;
    dist[src]=0;
    for(i=0;i<v-1;i++)
    {
        for(auto it:edge)
        {
            int start=it[0];
            int end=it[1];
            int weight=it[2];
            if (dist[start] != INF && dist[start] + weight < dist[end]) {
                dist[end] = dist[start] + weight;
            }
        }
    }
    int flag=1;
    for(auto it:edge)
    {
        int start = it[0];
        int end= it[1];
        int weight = it[2];
        if (dist[start] != INF && dist[start] + weight < dist[end])
        {
            flag=0;
            break;
        }
        
    }
    if(flag==1)
    {
        for(auto ans:dist)
        {
            cout<<ans<<" ";
        }
    }
    else
    {
        cout<<-1;
    }
    
    
    return 0;

}
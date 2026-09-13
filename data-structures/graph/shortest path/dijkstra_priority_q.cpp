#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<pair<int,int>> adj[], int S)
{
    set<pair<int,int>> st;

    vector<int> dist(V, 1e9);

    st.insert({0,S});

    dist[S]=0;

    while(!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;

        st.erase(it);
        for(auto it:adj[node])
        {
            int adjNode = it.first;
            int adjW = it.second;

            if(dis+adjW<dist[adjNode])
            {
                if(dist[adjNode] !=1e9)
                {
                    st.erase({dist[adjNode],adjNode});
                }
                dist[adjNode] = dis+adjW;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;

}
int main()
{
    int edge,vertex,x,y,weight;
    
    cout<<"enter no. of edges and vertex"<<endl;
    cin>>edge;
    cin>>vertex;
    vector<pair<int,int>> adj[vertex];
    cout<<"enter the edges and weight"<<endl;
    for(int i=0;i<edge;i++)
    {
        cin>>x>>y>>weight;
        adj[x].push_back({y,weight});
        adj[y].push_back({x,weight});
    }
    vector<int> res = dijkstra(vertex,adj,0);
    for(int j=0;j<vertex;j++)
    {
        cout<<"Node "<<j<<":"<<res[j]<<endl;
    }
    return 0;
}
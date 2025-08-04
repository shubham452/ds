#include<bits/stdc++.h>
using namespace std;
#define V 9
int getminimum(int dist[], bool visited[])
{
    int m=INT_MAX;
    int index;
    for(int i=0;i<V;i++)
    {
        if(dist[i]<m && visited[i]==0)
        {
            m=dist[i];
            index=i;
        }
    }
    return index;
}
void dijkstra(int graph[V][V],int src)
{
    int i,j;
    int dist[V];
    bool visited[V];
   // memset(dist,V,INT_MAX);
    //memset(visited,V,0);
    for(i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
        visited[i]=0;
    }
    dist[src]=0;
    for(i=0;i<V-1;i++)
    {
        int u=getminimum(dist,visited);
        visited[u]=1;
        for(j=0;j<V;j++)
        {
            if(graph[u][j]!=0 && visited[j]!=1 && dist[u]+graph[u][j]<dist[j] && dist[u]!=INT_MAX)
            {
                dist[j]=graph[u][j]+dist[u];
            }
        }
    }
    cout<<"vertex"<<"    "<<"distance"<<endl;
    for(i=0;i<V;i++)
    {
        cout<<i<<"    "<<dist[i]<<endl;
    }
} 
int main()
{
    //int V=9;
    int src;
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    cout<<"enter the source"<<endl;
    cin>>src;
    dijkstra(graph,src);
    
}
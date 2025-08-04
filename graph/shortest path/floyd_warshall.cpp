//here we try to insert a node between the nodes to check if the distance is reduced or not by introducing a node.
#include<bits/stdc++.h>
using namespace std;
const int INF =1e9;
int main()
{
    int v,i,j,k;
    cout<<"enter the no. of vertices"<<endl;
    cin>>v;
    vector<vector<int>> graph={ { 0, 5, INF, 10 },
                                { INF, 0, 3, INF },
                                { INF, INF, 0, 1 },
                                { INF, INF, INF, 0 } };

    vector<vector<int>> dist=graph;
    for(k=0;k<v;k++)
    {
        for(i=0;i<v;i++)
        {
            for(j=0;j<v;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j] && dist[i][k]!=INF && dist[k][j]!=INF)
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }               
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            cout<<dist[i][j]<<"  ";
        }
        cout<<endl;
    }               
                     

    return 0;
}
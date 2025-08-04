#include<bits/stdc++.h>
using namespace std;
/*consider the adjency list
    1->2
    2->3
    3->4,6
    4->5
    5->
    6->5
    7->2,8
    8->9
    9->7
*/
bool checkcycle(int node,int visited[], int dfs[],vector<int> adj[])
{
    visited[node]=1;
    dfs[node]=1;
    //1).algorithm will not find any cycle from 1 to 6
    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            if(checkcycle(it,visited,dfs,adj))//2).7,8,9 will come here
            {
                return true;//4.)7 returns true,so the above condition return true through this line for 9
                            //for 9 it will again return true to 8 and then to 7
                            //and then this function will return true , which will tell us that there is cycle in the graph.
            }
            
        }
        else if(dfs[it])//3.)when 7 comes again through 9, it will return true
        {
            return true;
        }
    }
    dfs[node]=0;
    return false;
}
bool iscycle(int v,vector<int> adj[])
{
    int visited[v];
    int dfs[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=0;
        dfs[i]=0;
    }
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
           // cout<<i<<endl;
            if(checkcycle(i,visited,dfs,adj))
            {
               // cout<<i<<endl;

                return true;
            }
        }
    }
    return false;
}
void addEdge(vector < int > adj[], int u, int v) 
{
  adj[u].push_back(v);
}
int main()
{
    int v,e,i,x,y;
    cout<<"enter vertices"<<endl;
    cin>>v;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    /*for(i=0;i<e;i++)
    {
        cout<<"enter edges"<<endl;
        cin>>x>>y;
        adj[x].push_back(y);
    }*/
    if(iscycle(v,adj))
    {
        cout<<"cycle detected";
    }
    else
    {
        cout<<"cycle not detected";
    }
    return 0;
}
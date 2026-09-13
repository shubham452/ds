//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    public:
    
        bool dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &pathVis,int node)
        {
            vis[node]=true;
            pathVis[node]=true;
            
            for(auto x:adj[node])
            {
                if(!vis[x])
                {
                        
                    if(dfs(adj,vis,pathVis,x))
                    {
                        return true;
                    }
                }
                else if(pathVis[x])
                {
                    return true;
                }
            }
            pathVis[node]=false;
            return false;
        }
        
        bool isCyclic(int V, vector<vector<int>> &edges) {
            // code here
        vector<bool> vis(V,false);
        vector<bool> pathVis(V,false);
        vector<vector<int>> adj(V);
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
        }
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(adj,vis,pathVis,i))
                {
                    return true;
                }
            }
            
        }
        return false;
            
        }
    };


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}

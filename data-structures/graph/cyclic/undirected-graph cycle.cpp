//https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) 
    {
        unordered_map<int,vector<int>> adj;
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
       
        
        vector<int> vis(V,0);
        
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                queue<pair<int,int>> q;
                q.push({i,-1});
                vis[i]=1;
            
                while(!q.empty())
                {
                    int node=q.front().first;
                    int parent=q.front().second;
                    q.pop();
                    for(auto neighbour:adj[node])
                    {
                        if(!vis[neighbour])
                        {
                            q.push({neighbour,node});
                            vis[neighbour]=1;
                        }
                        else if(neighbour!=parent)
                        {
                            return true;
                        }
                        
                    }
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
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
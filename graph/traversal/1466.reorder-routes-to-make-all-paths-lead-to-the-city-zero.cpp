//https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/

class Solution {
public:
    void dfs(vector<vector<pair<int,int>>> &adj, int &count, int start, vector<bool> &vis)
    {
        vis[start] = true;
        for(auto &p:adj[start])
        {
            if(!vis[p.first])
            {
                if(p.second==1)
                {
                    count++;
                }
                dfs(adj,count,p.first,vis);
            }
        }
    }   
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector<vector<pair<int,int>>> adj(n);
        vector<bool> vis(n, false);

        for(auto &x:connections)
        {
            int a=x[0];
            int b= x[1];
            adj[a].push_back({b,1});
            adj[b].push_back({a,0});
        }
        int count=0;
        dfs(adj,count,0,vis);
        return count;
        
    }
};
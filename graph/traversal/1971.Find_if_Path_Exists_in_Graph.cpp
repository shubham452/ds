//https://leetcode.com/problems/find-if-path-exists-in-graph/description/
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        unordered_map<int,vector<int>> adj;
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,bool> visited;
        for (int i = 0; i < n; ++i) 
        {
            visited[i] = false;
        }

        queue<int> q;
        q.push(source);
        visited[source]=true;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(auto it:adj[x])
            {
                if(!visited[it])
                {
                    visited[it]=true;
                    q.push(it);
                }
            }
        }
       return visited[destination] ;      
    }
       

};
//https://leetcode.com/problems/number-of-provinces/description/

class Solution {
public:
    void helper(vector<vector<int>>& isConnected,unordered_map<int,vector<int>> &adj, unordered_map<int,bool> &vis)
    {
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[i].size();j++)
            {
                vis[j]=false;
                if(i!=j && isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }
    void dfs(int vertex, unordered_map<int,vector<int>> adj, unordered_map<int,bool> &vis)
    {
        vis[vertex]=true;
        for(auto it:adj[vertex])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,bool> vis;
        helper(isConnected,adj,vis);
        int ans=0;
        for(auto it:vis)
        {
            if(!it.second)
            {
                dfs(it.first,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};
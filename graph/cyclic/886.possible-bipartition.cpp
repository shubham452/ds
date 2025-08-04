//https://leetcode.com/problems/possible-bipartition/description/

class Solution {
public:
    bool dfs(int col,int node, vector<vector<int>> &adj, int n, vector<int> &colors)
    {
        colors[node]=col;
        for(auto x:adj[node])
        {
            if(colors[x]==-1)
            {
                if(!dfs(1-col,x,adj,n,colors))
                {
                    return false;
                }
            }
            else if(colors[x]==col)
            {
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        vector<vector<int>> adj(n+1);
        int i;
        vector<int> colors(n+1,-1);
        for(auto x:dislikes)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
            for(i=1;i<=n;i++)
            {
                if(colors[i]==-1)
                {
                    if(!dfs(0,i,adj,n,colors))
                    {
                        return false;
                    }
                }
            }
            
        return true;    
    }
};

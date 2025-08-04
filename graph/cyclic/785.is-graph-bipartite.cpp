//https://leetcode.com/problems/is-graph-bipartite/description/

class Solution {
public:
    bool dfs(int node,int col, vector<vector<int>> graph, vector<int> &colors)
    {
        colors[node]=col;
        for(auto x:graph[node])
        {
            if(colors[x]==-1)
            {
            
                if(!dfs(x,1-col,graph,colors))
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
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<int> colors(n,-1);
        for(int i=0;i<n;i++)
        {
            if(colors[i]==-1)
            {
                if(!dfs(i,0,graph,colors))
                {
                    return false;
                }
            }
           
        }
        return true;

    }
};
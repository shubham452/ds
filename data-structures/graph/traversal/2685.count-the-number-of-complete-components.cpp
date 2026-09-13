//https://leetcode.com/problems/count-the-number-of-complete-components/description/
class Solution {
public:

    void dfs(unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &vis,int &edge_count,int node,unordered_set<int> &st)
    {
        vis[node]=true;
        st.insert(node);
        for(auto x:adj[node])
        {
            edge_count++;
            if(!vis[x])
            {
                dfs(adj,vis,edge_count,x,st);
            }
            
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int>> adj;
        unordered_map<int,bool> vis;

        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            
        }
       for(int i=0;i<n;i++)
       {
        vis[i]=false;
       }
        int ans=0;
        for(auto visited:vis)
        {
             
            if(!visited.second)
            {
                unordered_set <int> st;
                int edge_count = 0;
                dfs(adj,vis,edge_count,visited.first,st);
                
                int k=st.size();
                edge_count=edge_count/2;

                if(edge_count==(k*(k-1))/2)
                {   
                    ans++;
                }
            }
            
        }
        return ans;
    }
};
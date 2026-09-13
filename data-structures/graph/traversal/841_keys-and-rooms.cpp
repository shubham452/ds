//https://leetcode.com/problems/keys-and-rooms/description/

class Solution {
public:
    void helper(vector<vector<int>> rooms,unordered_map<int,vector<int>> &adj, unordered_map<int, bool> &vis)
    {
        vis[0]=false;
        for(int i=0;i<rooms.size();i++)
        {
            if(rooms[i].size()==0)
            {
                vis[i]=false;
            }
            for(int j=0;j<rooms[i].size();j++)
            {
                adj[i].push_back(rooms[i][j]);
                vis[rooms[i][j]]=false;
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        unordered_map<int,vector<int>> adj;
        unordered_map<int, bool> vis;
        helper(rooms,adj,vis);

        queue<int> q;
        q.push(0);
        vis[0]=1; 
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(auto it:adj[x])
            {
                if(!vis[it])
                {
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
        for(auto p:vis)
        {
            if(p.second==false)
            {
                return false;
            }
        }   
        return true;
    }
};
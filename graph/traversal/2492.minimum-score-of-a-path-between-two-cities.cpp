//https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) 
    {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto itr: roads)
        {
            adj[itr[0]].push_back({itr[1],itr[2]});
            adj[itr[1]].push_back({itr[0],itr[2]});
        }
        unordered_map<int,bool> visited;
        queue<pair<int,int>> q;
        q.push({1,0});
        int minDistance=INT_MAX;
        while(!q.empty())
        {
            auto [curr,wt]= q.front();
            q.pop();
            for(auto next:adj[curr])
            {
                minDistance = min(minDistance,next.second);
                if(!visited[next.first])
                {
                    q.push({next.first,next.second});
                    visited[next.first]= true;
                }
                
            }
        }
        return minDistance;
    }
};
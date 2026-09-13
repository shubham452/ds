//https://leetcode.com/problems/flower-planting-with-no-adjacent/description/

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) 
    {
        int i;
        vector<vector<int>> adj(n+1);
        vector<int> visited(n+1,0);
        vector<int> flower_colors(n+1,0);

        for(auto i:paths)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }  
        for(i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                queue<int> q;
                q.push(i);
                visited[i]=1;
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    vector<int> colors_used(5,0);
                    for(auto x:adj[node])
                    {
                        if(flower_colors[x]!=0)
                        {
                            colors_used[flower_colors[x]]=1;
                        }
                    }
                    for(int p=1;p<=4;p++)
                    {
                        if(colors_used[p]==0)
                        {
                            flower_colors[node]=p;
                            break;
                        }
                    }
                }
            }
            
            
        } 
        return vector<int>(flower_colors.begin()+1, flower_colors.end());
    }
};
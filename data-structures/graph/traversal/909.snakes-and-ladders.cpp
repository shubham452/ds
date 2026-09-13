//https://leetcode.com/problems/snakes-and-ladders/description/

class Solution {
public:
vector<int> findCoordinates(int pos, int n)
{
    
    int x=n-1-(pos-1)/n;
    int y=(pos-1)%n;
    if((n-1-x)%2==1)
    {
        y=n-1-y;
    }
    return {x,y}; 
}
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int n=board.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        int ans=0;
        q.push({1,0});
        visited[n-1][0]=true;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto [front,moves]=q.front();
                q.pop();
                if(front==n*n)
                {
                    return moves;
                }
                for(int k=1;k<=6;k++)
                {
                    if(front+k>n*n)
                    {
                        break;
                    }
                    vector<int> pos=findCoordinates(front+k,n);
                    int x=pos[0];
                    int y=pos[1];
                   

                    if(visited[x][y])
                    {
                        continue;
                    }
                    visited[x][y]=true;
                    if(board[x][y]!=-1)
                    {
                        
                        q.push({board[x][y],moves+1});
                    }
                    else
                    {
                        q.push({front+k,moves+1});
                    }
                }
            }
        }
        return -1;   
    }
};
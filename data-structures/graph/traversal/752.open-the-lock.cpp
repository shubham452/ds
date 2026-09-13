//https://leetcode.com/problems/open-the-lock/description/

class Solution {
public:

    int openLock(vector<string>& deadends, string target) 
    {
        unordered_set<string> deadend(deadends.begin(),deadends.end());
        unordered_set<string> visited;

        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int steps=0;
        if(deadend.find("0000")!=deadend.end())
        {
            return -1;
        }
        while(!q.empty())
        {
            int n=q.size();
           // steps++;
            for(int i=0;i<n;i++)
            {
                string front=q.front();
                q.pop();
                if(front==target)
                {
                    return steps;
                }
                for(int j=0;j<4;j++)
                {
                    string up=front;
                    string down=front;
                    
                    up[j]=(up[j]=='9'?'0':up[j]+1);
                    down[j]=(down[j]=='0'?'9':down[j]-1);
                    if(visited.find(up)==visited.end() && deadend.find(up)==deadend.end())
                    {
                        visited.insert(up);
                        q.push(up);
                    }
                    if(visited.find(down)==visited.end() && deadend.find(down)==deadend.end())
                    {
                        visited.insert(down);
                        q.push(down);
                    }
                }
            }
            steps++;

        }
    return -1;

    }
};
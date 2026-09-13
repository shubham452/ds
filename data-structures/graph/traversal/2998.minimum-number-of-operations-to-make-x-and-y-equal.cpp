//https://leetcode.com/problems/minimum-number-of-operations-to-make-x-and-y-equal/description/

class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) 
    {
        queue<int> q;
        unordered_map<int,bool> vis;
        q.push(x);
        vis[x]=true;
        int steps=0;
        while(!q.empty())
        {
            int n=q.size();
            
            for(int i=0;i<n;i++)
            {
                int val=q.front();
                q.pop();
                //cout<<"steps are :"<<steps<<endl;
                if(val==y)
                {
                    return steps;
                }
                if(val%11==0 && vis[val%11]==false)
                {
                    q.push(val/11);
                    vis[val/11]=true;
                    //cout<<val/11<<endl;
                }
                if(val%5==0 && vis[val%5]==false)
                {
                    q.push(val/5);
                    vis[val/5]=true;
                    //cout<<val/5<<endl;
                }
                if(vis[val-1]==false)
                {
                    q.push(val-1);
                    vis[val-1]=true;
                   // cout<<val-1<<endl;
                }
                if(vis[val+1]==false)
                {
                    q.push(val+1);
                    vis[val+1]=true;
                   // cout<<val+1<<endl;
                }
            }
            steps++;
        }  
        return steps;  
    }
};
//https://www.naukri.com/code360/problems/dfs-traversal_630462
void dfs(unordered_map<int,vector<int>> &adj,int vertex,unordered_map<int,bool> &vis,vector<int> &ans)
{
    
    vis[vertex]=true;
    ans.push_back(vertex);
    for(auto it:adj[vertex])
    {
        if(!vis[it])
        {
            dfs(adj,it,vis,ans);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int,vector<int>> adj;
    unordered_map<int,bool> vis;
    for(int i=0;i<E;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
        vis[edges[i][0]]=false;
        vis[edges[i][1]]=false;
    }
    vector<vector<int>> gp;
    int count=0;

    for(auto it:vis)
    {

        if(!it.second)
        {
            vector<int> singleAns;
            dfs(adj,it.first,vis,singleAns);
            sort(singleAns.begin(),singleAns.end());
            gp.push_back(singleAns);
        }
        
    }
    return gp;
    
}
class Solution {
public:
vector<vector<int>> adj;
vector<int> vis;
bool dfs(int node,int dest)
{
    if(node==dest) return true;
    vis[node]=1;
    for(auto nei : adj[node])
    {
        if(!vis[nei])
        {
            if(dfs(nei,dest))
            {
                return true;
            }
        }
    }

    return false;
}

bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
    adj.resize(n+1);
    vis.resize(n+1,0);

    for(auto k : edges)
    {
        int u=k[0],v=k[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return dfs(src,dest);
    }
};
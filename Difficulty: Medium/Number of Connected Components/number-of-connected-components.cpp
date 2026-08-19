class Solution {
  public:
 vector<int> vis;
  vector<vector<int>>adj;
  
void dfs(int node,vector<vector<int>>& edges)
{
    vis[node]=1;
    for(auto nei : edges[node])
    {
        if(!vis[nei])
        {
            dfs(nei,edges);
        }
    }
}

int countConnected(int V, vector<vector<int>>& edges) {
      int comp=0;
      vis.resize(V+1,0);
      adj.resize(V+1);
     
      
     for(auto k : edges)
     {
         int u=k[0];
         int v=k[1];
         adj[u].push_back(v);
         adj[v].push_back(u);
     }
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                comp++;
                dfs(i,adj);
            }
        }
        
        return comp;
        
    }
};
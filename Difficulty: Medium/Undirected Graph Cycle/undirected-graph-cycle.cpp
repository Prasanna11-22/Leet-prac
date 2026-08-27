class Solution {
  public:
  vector<bool> vis;
  int r,c;
  
  bool bfs(int i,vector<vector<int>>& adj)
  {
      queue<pair<int,int>>q;
      q.push({i,-1});
      vis[i]=true;
      
      while(!q.empty())
      {
          auto [sr,pr]=q.front();
          q.pop();
          
          
          for(auto node : adj[sr])
          {
          if(!vis[node])
          {
              q.push({node,sr});
              vis[node]=true;
          }
          else if(node!=pr)
          {
              return true;
          }
          
          }
      }
      return false;
  }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        
        
        for(auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        
       // r=adj.size(),c=adj[0].size();
        vis.assign(V,false);
        
        for(int i=0;i<adj.size();i++)
        {
           
            if(!vis[i])
            {
            if(bfs(i,adj))
            {
                return true;
            }
            }
        }
        return false;
    }
};
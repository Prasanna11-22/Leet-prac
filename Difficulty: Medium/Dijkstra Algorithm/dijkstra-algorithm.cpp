class Solution {
  public:
  void dij(int src,vector<vector<pair<int,int>>> &adj,vector<int>& dist)
  {
      set<pair<int,int>> q;
      dist[src]=0;
      q.insert({0,src});
      
      while(!q.empty())
      {
          auto k=q.begin();
          int d=k->first;
          int u=k->second;
          q.erase(q.begin());
          for(auto node : adj[u])
          {
              int v=node.first;
              int w=node.second;
              
              if(d+w<dist[v])
              {
                  if(dist[v]!=1e9)
                  {
                      q.erase({dist[v],v});
                  }
                  
                  dist[v]=d+w;
                  q.insert({dist[v],v});
              }
          }
      }
      
  }
  
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    vector<vector<pair<int,int>>> adj(V);
    vector<int> dist(V,1e5);
    
    for(auto i : edges)
    {
        int u=i[0];
        int v=i[1];
        int wt=i[2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    dij(src,adj,dist);
    
    return dist;
        
    }
};
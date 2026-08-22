class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int r=adj.size(),c=adj[0].size();
       vector<bool> vis(r+1,false);
       
       queue<int>q;
       vector<int> res;
       int st=0;
       
       q.push(st);
       vis[st]=true;
       
       while(!q.empty())
       {
           int node=q.front();
           q.pop();
           res.push_back(node);
           
           for(auto nei : adj[node])
           {
             
             if(!vis[nei])
             {
                 vis[nei]=true;
                 q.push(nei);
             }
             
           }
           
       }
       
       return res;
        
    }
};
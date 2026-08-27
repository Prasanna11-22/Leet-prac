class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
    vector<bool> vis(adj.size(),false);
    vector<int> col(adj.size(),-1);

    for(int i=0;i<adj.size();i++)
    {
        if(col[i]==-1)
        {
        if(dfs(i,0,adj,vis,col)==false)
        {
            return false;
        }
        }
    }
        return true;        
    }

    bool dfs(int node,int c,vector<vector<int>>& adj,vector<bool>& vis,vector<int>& col)
    {
        col[node]=c;

        for(auto nei : adj[node])
        {
            if(col[nei]==-1) 
            {
                if(dfs(nei,!c,adj,vis,col)==false) return false;
            }
            else if(col[nei]==c)
            {
                return false;
            }
        }
      
    return true;

    }
};
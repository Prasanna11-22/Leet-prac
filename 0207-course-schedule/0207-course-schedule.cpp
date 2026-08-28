class Solution {
public:
vector<bool> vis;
vector<bool> inpath; 

bool dfs(int n,int par,vector<vector<int>> &adj)
{
    vis[n]=true;
    inpath[n]=true;

    for(auto nei : adj[n])
    {
        if(!vis[nei])
        {
            if(dfs(nei,n,adj))
            {
                return true;
            }
        }
        else if(inpath[nei])
        {
            return true;
        }
    }

    inpath[n]=false;
    return false;
}
    bool canFinish(int nums, vector<vector<int>>& preq) {
        vis.assign(nums,false);
        inpath.assign(nums,false);
        vector<vector<int>> adj(nums);

        for(auto k : preq)
        {
            int u=k[0];
            int v=k[1];
            adj[u].push_back(v);
        }

        for(int i=0;i<nums;i++)
        {
                if(!vis[i]) 
                {
                    if(dfs(i,-1,adj))
                    {
                        return false;
                    }
                }
        }
        return true;
    }
};
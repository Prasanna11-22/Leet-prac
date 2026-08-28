class Solution {
public:
int V;
vector<vector<int>> res;

void dfs(int n,vector<vector<int>>& graph,vector<int> ans,vector<bool> vis)
{
    vis[n]=true;

        ans.push_back(n);   
    if(n==V-1) 
    {
        res.push_back(ans);
        return;
    }
    for(int nei : graph[n])
    {
        if(!vis[nei])
        {
            dfs(nei,graph,ans,vis);
        }
        else
        {
           ans.pop_back();
            return;
        }
    }
    return;

}

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
         V=graph.size();
         vector<bool> vis;
         vector<int> ans;
         vis.assign(V,false);
         dfs(0,graph,ans,vis);

    return res;
    }
};
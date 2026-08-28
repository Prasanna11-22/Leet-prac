class Solution {
public:
vector<bool>vis;
vector<bool>inpath;
vector<bool>chk;

bool dfs(int n ,vector<vector<int>>& graph)
{
    vis[n]=true;
    inpath[n]=true;

    for(int nei : graph[n])
    {
        if(!vis[nei])
        {
            if(dfs(nei,graph))
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
    chk[n]=true;
    return false;
}



    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vis.assign(V,false);
        inpath.assign(V,false);
        chk.assign(V,false);
        vector<int> res;

        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,graph);
            }

            if(chk[i]==true)
            {
                res.push_back(i);
            }
        }
        
        return res;
    }
};
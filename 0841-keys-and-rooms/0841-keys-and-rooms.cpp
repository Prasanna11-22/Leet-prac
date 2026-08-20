class Solution {
public:
vector<int> vis;

void dfs(int node,vector<vector<int>>&rooms)
{
    vis[node]=1;
    for(int i : rooms[node])
    {
        if(!vis[i])
        {
            dfs(i,rooms);
        }
    }
}

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vis.resize(n+1,0);

        dfs(0,rooms);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                return false;
            }
        }
        return true;
    }
};
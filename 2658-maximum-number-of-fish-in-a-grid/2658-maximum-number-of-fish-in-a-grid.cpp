class Solution {
public:
int r,c;
vector<vector<int>> vis;
int dfs(int i,int j,vector<vector<int>> &grid)
{
    if(i<0||j<0||i>=r||j>=c||grid[i][j]==0||vis[i][j]==1) return 0;
    int t=0;
    
    if(!vis[i][j])
    {
     t=grid[i][j];
     vis[i][j]=1;
    }

    return t+dfs(i-1,j,grid)+dfs(i+1,j,grid)+dfs(i,j+1,grid)+dfs(i,j-1,grid);
}

    int findMaxFish(vector<vector<int>>& grid) {
        r=grid.size(),c=grid[0].size();
        vis.resize(r+1,vector<int>(c+1,0));
        int maxi=0,res=0;

        for(int i=0;i<r;i++)
        {
         for(int j=0;j<c;j++)
         {
            if(!vis[i][j]&&grid[i][j]!=0)
            {
                res=dfs(i,j,grid);
                maxi=max(maxi,res);
            }
         }
        }

        return maxi;
    }
};
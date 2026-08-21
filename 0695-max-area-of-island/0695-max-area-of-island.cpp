class Solution {
public:
int r,c;

int dfs(int i,int j,vector<vector<int>>& grid)
{
    if(i<0||i>=r||j<0||j>=c||grid[i][j]==0) return 0;

   grid[i][j]=0;
   return 1+dfs(i-1,j,grid)+dfs(i+1,j,grid)+dfs(i,j-1,grid)+dfs(i,j+1,grid);

}
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        r=grid.size(),c=grid[0].size();
        int res=0,maxi=0;

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    int cnt=0;
                    res=dfs(i,j,grid);
                    maxi=max(maxi,res);
                }
            }
        }

        return maxi;
        
    }
};
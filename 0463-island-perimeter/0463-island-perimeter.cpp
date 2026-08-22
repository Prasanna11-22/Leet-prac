class Solution {
public:
int r,c,res=0;
vector<vector<int>> vis;

void dfs(int i,int j,vector<vector<int>>& grid)
{
    if(i<0||j<0||i>=r||j>=c||grid[i][j]==0)
    {
        res++;
        return;
    }
    
    if(grid[i][j]==-1) return;
    
    grid[i][j]=-1;

    dfs(i-1,j,grid);
    dfs(i+1,j,grid);
    dfs(i,j-1,grid);
    dfs(i,j+1,grid); 
}

    int islandPerimeter(vector<vector<int>>& grid) {
        r=grid.size(),c=grid[0].size();
        vis.resize(r+1,vector<int>(c+1,0));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                  dfs(i,j,grid);
                  return res;
                }
            }
        }
        return -1;
    }
};
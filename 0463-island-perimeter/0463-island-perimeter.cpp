class Solution {
public:
int r,c;
vector<vector<int>> vis;

int dfs(int i,int j,vector<vector<int>>& grid)
{
    if(i<0||j<0||i>=r||j>=c)
    {
        return 1;
    }
    
    if(grid[i][j]==1&&vis[i][j]) return 0;
    else if(grid[i][j]==0)
    {
    if(!vis[i][j])
    {
        vis[i][j]=1;
    }
    return 1;
    }
    
    vis[i][j]=1;
    return dfs(i-1,j,grid)+dfs(i+1,j,grid)+dfs(i,j-1,grid)+dfs(i,j+1,grid); 
}

    int islandPerimeter(vector<vector<int>>& grid) {
        int res=0;
        bool chk=true;
        r=grid.size(),c=grid[0].size();
        vis.resize(r+1,vector<int>(c+1,0));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(chk)
                {
                if(grid[i][j]==1)
                {
                  res=dfs(i,j,grid);
                  chk=false; 
                }
                }
            }
        }

        return res;
    }
};
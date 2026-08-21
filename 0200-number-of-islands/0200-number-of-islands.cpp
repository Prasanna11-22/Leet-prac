class Solution {
public:
int r,c;
vector<vector<int>> vis;
void dfs(int i,int j,vector<vector<char>>& grid)
{
    if(i<0||i>=r||j<0||j>=c) return;
    if(!vis[i][j]&&grid[i][j]=='1')
    {
        vis[i][j]=1;
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);
    }
    else
    {
        return;
    }
   
}
    int numIslands(vector<vector<char>>& grid) {
        int comp=0;
        r=grid.size(),c=grid[0].size();
        vis.resize(r+1,vector<int>(c+1,0));

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(!vis[i][j]&&grid[i][j]=='1')
                {
                    comp++;
                    dfs(i,j,grid);
                }
            }
        }

        return comp;
    }
};
class Solution {
public:
int r,c;

void dfs(int i,int j,vector<vector<int>>& grid,int rep)
{
    if(i<0||i>=r||j<0||j>=c) return;

    if(grid[i][j]==0) return;

    if(grid[i][j]==1) 
    {
    grid[i][j]=rep;
    dfs(i-1,j,grid,rep);
    dfs(i+1,j,grid,rep);
    dfs(i,j-1,grid,rep);
    dfs(i,j+1,grid,rep);
    }
    else
    {
        return;
    }
}

    int numEnclaves(vector<vector<int>>& grid) {
        r=grid.size(),c=grid[0].size();
        int cnt=0;

        for(int i=0;i<r;i++)
        {
            if(grid[i][0]==1)
            {
                dfs(i,0,grid,3);
            }
            if(grid[i][c-1])
            {
                dfs(i,c-1,grid,3);
            }
        }

        for(int i=0;i<c;i++)
        {
            if(grid[0][i]==1)
            {
                dfs(0,i,grid,3);
            }
            if(grid[r-1][i])
            {
                dfs(r-1,i,grid,3);
            }
        }


        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                   // cout<<grid[i][j]<<" ";
                    cnt++;
                }
            }
            //cout<<endl;
        }
        return cnt;
    }
};
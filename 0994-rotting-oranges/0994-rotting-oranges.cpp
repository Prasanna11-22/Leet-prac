class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vector<vector<bool>> vis(r+1,vector<bool>(c+1,false));
        int minutes=0,fresh=0;
        vector<pair<int,int>> diff={{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    vis[i][j]=true;
                }
                else if(grid[i][j]==1) fresh++;
            }
        }

        while(!q.empty())
        {
            int lev=q.size();

            for(int i=0;i<lev;i++)
            {
             auto [dr,dc]=q.front();
             q.pop();

             for(auto k : diff)
             {
                int nr=dr+k.first;
                int nc=dc+k.second;
                if(nr<0||nr>=r||nc<0||nc>=c) continue;
                if(!vis[nr][nc])
                {
                    if(grid[nr][nc]==1)
                    {

                        q.push({nr,nc});
                        grid[nr][nc]=2;
                        fresh--;

                    }
                    vis[nr][nc]=true;
                }
             }
            }

            if(!q.empty()) minutes++;
        }
        return (fresh==0)?minutes:-1;
    }
};
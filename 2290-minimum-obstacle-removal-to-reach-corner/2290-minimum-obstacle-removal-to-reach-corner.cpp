class Solution {
public:
int r,c;
    int minimumObstacles(vector<vector<int>>& grid) {
       r=grid.size(),c=grid[0].size();

       vector<int> dx={1,-1,0,0};
       vector<int> dy={0,0,1,-1};
       deque<pair<int,int>> q;
       vector<vector<int>> dist(r,vector<int>(c,1e9));
       q.push_back({0,0});
       dist[0][0]=0;

       while(!q.empty())
       {
        auto [x,y]=q.front();
        q.pop_front();

        if(x==r-1&&y==c-1) return dist[x][y];

        for(int i=0;i<4;i++)
        {
            int nr=x+dx[i];
            int nc=y+dy[i];
            if(nr<0||nc<0||nr>=r||nc>=c) continue;

            int w=grid[nr][nc];

            if(dist[x][y]+w<dist[nr][nc])
            {
            dist[nr][nc]=dist[x][y]+w;  
            if(w==1)
            {
                q.push_back({nr,nc});
            }
            else
            {
                q.push_front({nr,nc});
            }
            }
        }

       }
        return dist[r-1][c-1];
    }
};
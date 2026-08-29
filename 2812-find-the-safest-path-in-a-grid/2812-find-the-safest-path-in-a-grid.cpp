class Solution {
public:
int r,c;
#define mp make_pair

vector<int> dx={1,-1,0,0};
vector<int> dy={0,0,1,-1};

void bfs(vector<vector<int>>&grid ,vector<vector<int>>&dist)
{
    queue<pair<int,int>> q;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(grid[i][j]==1)
            {
                dist[i][j]=0;
                q.push(mp(i,j));
            }
        }
    }

    while(!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nr=x+dx[i];
            int nc=y+dy[i];

            if(nr<0||nc<0||nr>=r||nc>=c) continue;

            if(grid[nr][nc]==0&&dist[nr][nc]==INT_MAX)
            {
                dist[nr][nc]=dist[x][y]+1;
                q.push(mp(nr,nc));
            }
        }
    }

}

bool isposs(int lim,vector<vector<int>>&dist)
{
    vector<vector<bool>> vis(r,vector<bool>(c,false));

    if(dist[0][0]<lim) return false;
    queue<pair<int,int>> q;

    q.push(mp(0,0));
    vis[0][0]=true;

    while(!q.empty())
    {
        auto [x,y] =q.front();
        q.pop();
        if(x==r-1&&y==c-1) return true;

        for(int i=0;i<4;i++)
        {
            int nr=x+dx[i];
            int nc=y+dy[i];

            if(nr<0||nc<0||nr>=r||nc>=c) continue;

            if((dist[nr][nc]>=lim)&&(!vis[nr][nc]))
            {
                vis[nr][nc]=true;
                q.push(mp(nr,nc));
            }
        }
    }
    return false;
}


    int maximumSafenessFactor(vector<vector<int>>& grid) {
        r=grid.size(),c=grid[0].size();
        vector<vector<int>> dist(r,vector<int>(c,INT_MAX));
        
        bfs(grid,dist);

        int l=0,h=2*c,ans=0;

        while(l<=h)
        {
            int mid=l+(h-l)/2;

            if(isposs(mid,dist))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return ans;
    }
};
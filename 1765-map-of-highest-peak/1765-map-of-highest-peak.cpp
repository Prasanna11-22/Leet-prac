class Solution {
public:
#define mp make_pair
int r,c;
    vector<vector<int>> highestPeak(vector<vector<int>>& water) {
      queue<pair<int,int>> q;
      r=water.size(),c=water[0].size();
      vector<vector<bool>> vis(r,vector<bool>(c,false));
      vector<int> dx={1,-1,0,0};
      vector<int> dy={0,0,1,-1};

      for(int i=0;i<r;i++)
      {
        for(int j=0;j<c;j++)
        {
        if(water[i][j]==1) 
        {
         water[i][j]=0;
          vis[i][j]=true;
          q.push(mp(i,j));
        }
        }
      }

      while(!q.empty())
      {
        auto [x,y]=q.front();
        for(int i=0;i<4;i++)
        {
            int nr=x+dx[i];
            int nc=y+dy[i];

            if(nr<0||nr>=r||nc<0||nc>=c) continue;
            if(!vis[nr][nc])
            {
                vis[nr][nc]=true;
                water[nr][nc]=water[x][y]+1;
                q.push(mp(nr,nc));
            }
        }
        q.pop();
      }

    return water;

    }
};
class Solution {
public:

class tp {
public:
int i,j,cnt;
};

vector<int> dx={1,-1,0,0};
vector<int> dy={0,0,1,-1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        int r=maze.size(),c=maze[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        queue<tp> q;
        q.push({ent[0],ent[1]});
        vis[ent[0]][ent[1]]=true;

        while(!q.empty())
        {
            auto [x,y,cnt]=q.front();
            cout<<x<<y<<cnt<<endl;
            q.pop();
            if((x==r-1||y==c-1||x==0||y==0)&&(ent[0]!=x||ent[1]!=y))
            {
                return cnt;
            }

            for(int i=0;i<4;i++)
            {
                int nr=x+dx[i],nc=y+dy[i];
                if(nr<0||nc<0||nr>=r||nc>=c) continue;
                if((!vis[nr][nc])&&(maze[nr][nc]=='.'))
                {
                    vis[nr][nc]=true;
                    q.push({nr,nc,cnt+1});
                }
            }
        }
        return -1;
    }
};
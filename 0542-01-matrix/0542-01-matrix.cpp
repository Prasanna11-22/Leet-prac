class Solution {
public:
#define mp make_pair
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       queue<pair<int,int>> q;
       int r=mat.size(),c=mat[0].size();
       vector<vector<bool>> vis(r+1,vector<bool>(c+1,false));
       vector<vector<int>> dir={{1,0},{-1,0},{0,-1},{0,1}};

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(mat[i][j]==0)
            {
                q.push(mp(i,j));
                vis[i][j]=true;
            }
        }
    }

    while(!q.empty())
    {
        auto [i,j] =q.front();
        for(auto k : dir)
        {
            int nr=k[0]+i;
            int nc=k[1]+j;

            if(nr<0||nr>=r||nc<0||nc>=c) continue;
            
            if(!vis[nr][nc]&&mat[nr][nc]==1)
            {
                vis[nr][nc]=true;
                mat[nr][nc]=mat[i][j]+1;
                q.push(mp(nr,nc));
            }
        }
        q.pop();
    }
    return mat;
    }
};
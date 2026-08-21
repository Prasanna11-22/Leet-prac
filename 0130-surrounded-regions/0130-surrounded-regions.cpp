class Solution {
public:
vector<vector<int>> vis;
int r,c;

void dfs(int i ,int j,vector<vector<char>>& board,char rep)
{

    if(i<0||i>=r||j<0||j>=c)
    {
        return;
    }

    if(!vis[i][j]&&board[i][j]=='O')
    {
        vis[i][j]=1;
        board[i][j]=rep;
        dfs(i-1,j,board,rep);
        dfs(i+1,j,board,rep);
        dfs(i,j+1,board,rep);
        dfs(i,j-1,board,rep);
    }
    else
    {
        return;
    }
}

    void solve(vector<vector<char>>& board) {

         r=board.size();
         c=board[0].size();
        vis.resize(r+1,vector<int>(c+1,0));

        for(int i=0;i<c;i++)
        {
          if(board[0][i]=='O')
          {
            dfs(0,i,board,'T');
          }
          if(board[r-1][i]=='O')
          {
            dfs(r-1,i,board,'T');
          }
        }

        for(int i=0;i<r;i++)
        {
          if(board[i][0]=='O')
          {
            dfs(i,0,board,'T');
          }
          if(board[i][c-1]=='O')
          {
            dfs(i,c-1,board,'T');
          }
        }

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='T') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};
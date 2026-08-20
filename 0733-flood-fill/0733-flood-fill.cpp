class Solution {
public:
vector<vector<bool>> vis;
vector<vector<int>> res;
int r,c,chk;

void dfs(int i,int j,int col,vector<vector<int>>& img)
{
   
    if(!vis[i][j]&&img[i][j]==chk)
    {
        res[i][j]=col;
    }
        vis[i][j]=true;
    if(i>0 &&img[i-1][j]==chk&&!vis[i-1][j])  dfs(i-1,j,col,img);
    if(j>0&&img[i][j-1]==chk&&!vis[i][j-1])  dfs(i,j-1,col,img);
    if(i<r-1&&img[i+1][j]==chk&&!vis[i+1][j])  dfs(i+1,j,col,img);
    if(j<c-1&&img[i][j+1]==chk&&!vis[i][j+1])  dfs(i,j+1,col,img);

}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       r=image.size(),c=image[0].size();
       vis.resize(r+1,vector<bool>(c+1,false));
       res=image;

       chk=image[sr][sc];

       dfs(sr,sc,color,image);

       return res;
    }
};
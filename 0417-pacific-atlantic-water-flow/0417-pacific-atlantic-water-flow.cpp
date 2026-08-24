class Solution {
public:
#define mp make_pair         
    vector<int> dr={1,-1,0,0};
    vector<int> dc={0,0,1,-1};
    int r,c;
void dfs(int i,int j,vector<vector<int>>& heights,vector<vector<bool>>& vis)
{
    vis[i][j]=true;
            
            for(int k=0;k<4;k++)
            {
                int nr=dr[k]+i;
                int nc=dc[k]+j;

                if(nr<0||nr>=r||nc<0||nc>=c) continue;
                if(vis[nr][nc]||heights[nr][nc] < heights[i][j]) continue;
                dfs(nr,nc,heights,vis);
            }
}

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        r=heights.size(),c=heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> paci(r+1,vector<bool>(c+1,false));
        vector<vector<bool>> atl(r+1,vector<bool>(c+1,false));

    for(int j=0;j<c;j++) dfs(0,j,heights,paci);
    for(int j=0;j<r;j++) dfs(j,0,heights,paci);
    
    for(int j=0;j<c;j++) dfs(r-1,j,heights,atl);
    for(int j=0;j<r;j++) dfs(j,c-1,heights,atl);

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(paci[i][j]&&atl[i][j]) res.push_back({i,j}); 
        }
    }

        return res;
    }
};
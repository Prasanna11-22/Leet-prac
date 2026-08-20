class Solution {
public:
vector<int> vis;
void dfs(int i,vector<vector<int>>& iscon)
{
    vis[i]=1;
    for(int j=0;j<iscon.size();j++)
    {
        if(iscon[i][j]==1 && !vis[j])
        {
            dfs(j,iscon);
        }
    }
}

    int findCircleNum(vector<vector<int>>& isCon) {
   int n=isCon.size();
   vis.resize(n+1,0);
   int comp=0;

   for(int i=0;i<n;i++)
   {
    if(!vis[i])
    {
        comp++;
        dfs(i,isCon);
    }
   }
    return comp;    
    }
};
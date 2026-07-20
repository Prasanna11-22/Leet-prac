class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k){
        int r=grid.size();
        int c=grid[0].size();

        int tot=r*c;

        k%=tot;
        vector<vector<int>> res(r,vector<int>(c));

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int oind=i*c+j;
                int nind=(oind+k)%tot;

                int nrow=nind/c;
                int ncol=nind%c;

                res[nrow][ncol] = grid[i][j];
            }
        }
        return res;
    }
};
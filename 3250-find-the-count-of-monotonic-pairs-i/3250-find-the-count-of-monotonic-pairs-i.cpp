class Solution {
public:
const int mod=1e9+7;
int dp[2001][52][52];

int rec(vector<int>& nums,int i,int p1,int p2)
{
    if(i==nums.size()) return 1;
    if(dp[i][p1][p2]!=-1) return dp[i][p1][p2];
    int ans=0;
    for(int k=p1;k<=nums[i];k++)
    {
        int x1=k,x2=nums[i]-k;
        if(x1>=p1 && x2<=p2 )
        {
            ans=(ans+rec(nums,i+1,x1,x2))%mod;
        }
    }
    return dp[i][p1][p2]=ans;
}

    int countOfPairs(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int l= rec(nums,0,0,50);
        return l;
    }
};
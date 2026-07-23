class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int t) {
        int mod=1e9+7;
        long long sum=accumulate(arr.begin(),arr.end(),0);
        long long target=(t+sum);

        if(sum < abs(t) || target%2!=0)
        {
            return 0;
        }
        target/=2;

        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(long long j=0;j<=target;j++)
            {
                if(j<arr[i-1])
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-arr[i-1]])%mod;
                }
            }
        }

        return dp[n][target];
        
    }
};
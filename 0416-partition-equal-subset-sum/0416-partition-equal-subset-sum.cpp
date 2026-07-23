class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int mod=1e9+7;
        long long sum=accumulate(arr.begin(),arr.end(),0);

        if(sum%2!=0)
        {
            return false;
        }

        int n=arr.size();
        long long t=sum/2;
        vector<vector<int>> dp(n+1,vector<int>(t+1,0));
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(long long j=0;j<=t;j++)
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

        return dp[n][t]>0;
        
    }
};
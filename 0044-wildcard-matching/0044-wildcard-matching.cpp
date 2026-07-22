class Solution {
public:
    bool isMatch(string s, string p) {
        int s1=s.size(),s2=p.size();
        vector<vector<bool>>dp(s1+1,vector<bool>(s2+1,false));
        for(int i=0;i<=s1;i++)
        {
            for(int j=0;j<=s2;j++)
            {
                if(i==0&&j==0) dp[i][j]=1;
                else if(i==0)
                {
                    if(p[j-1]=='*'&& dp[i][j-1]==1)
                    {
                     dp[i][j]=1;
                    }
                    else
                    {
                     dp[i][j]=0;
                    }
                }
                else if(j==0)
                {
                    dp[i][j]=0;
                }
                else if(s[i-1]==p[j-1]||p[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
                }

            }
        }
        return dp[s1][s2];
    }
};
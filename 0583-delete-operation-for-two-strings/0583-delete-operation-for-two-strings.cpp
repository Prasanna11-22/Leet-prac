class Solution {
public:
    int minDistance(string t1, string t2) {
    int s1=t1.size(),s2=t2.size();
    vector<vector<int>> dp(s1+1,vector<int>(s2+1,0));
    
    for(int i=0;i<=s1;i++)
    {
        dp[i][0]=0;
    }
    
    for(int i=0;i<=s2;i++)
    {
        dp[0][i]=0;
    }

    for(int i=1;i<=s1;i++)
    {
        for(int j=1;j<=s2;j++)
        {
            if(t1[i-1]==t2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int r1=s1-dp[s1][s2];
    int r2=s2-dp[s1][s2];
    return (r1+r2);
    }
};
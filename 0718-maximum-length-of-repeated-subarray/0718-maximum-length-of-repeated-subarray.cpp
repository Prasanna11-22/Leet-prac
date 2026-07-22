class Solution {
public:
    int findLength(vector<int>& n1, vector<int>& n2) {
        int s1 = n1.size(), s2 = n2.size();
        int maxi = -1e9;
        vector<vector<int>> dp(s1 + 1,vector<int>(s2 + 1, 0));

        for (int i = 1; i <= s1; i++) 
        {
            for (int j = 1; j <= s2; j++) 
            {
                if (n1[i - 1] == n2[j - 1]) 
                {
                    dp[i][j] = 1 +dp[i - 1][j - 1];
                } 
                else 
                {
                    dp[i][j] = 0;
                }
                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi;
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(),maxi=-1e9,sind=-1,eind=-1;
        int count = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int diff = 0; diff < n; diff++) 
        {
            for (int i = 0, j = i + diff; j < n && i < n; i++, j++) 
            {
                if (i == j) {
                    dp[i][j] = 1;
                } else if (diff == 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 2;
                    }
                } else {
                    if (s[i] == s[j] && dp[i + 1][j - 1] != 0) {
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                    }
                }
                int diff=(j-i+1);
                if (dp[i][j] != 0&&(diff>maxi)) 
                {
                    sind=i;
                    eind=j;
                    maxi=max(maxi,diff);
                }
            }
        }
        return s.substr(sind,maxi);
    }
};
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = 0, cnt = 0, mini = INT_MAX, minlen = INT_MAX;
        string ans = "", minis = s;
        for (int r = 0; r < s.size(); r++) 
        {
            if (s[r] == '1')
                cnt++;

            while (cnt > k) 
            {
                if (s[l] == '1')
                    cnt--;
                l++;
            }
            if (cnt == k) 
            {
                while (s[l] == '0')
                    l++;
                if (minlen >= r - l + 1) 
                {
                    if (minlen == r - l + 1) 
                    {
                        ans = min(ans, s.substr(l, r - l + 1));
                    } 
                    else 
                    {
                        ans = s.substr(l, r - l + 1);
                    }
                    cout << ans << endl;
                    minlen = r - l + 1;
                }
            }
        }
        return ans;
    }
};
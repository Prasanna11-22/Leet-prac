class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0,maxi=INT_MIN;
        unordered_map<int,int> mp;

        for(int r=0;r<s.size();r++)
        {
            mp[s[r]]++;
            while(mp[s[r]]>2)
            {
                mp[s[l]]--;
                l++;
            }
            maxi=max(maxi,r-l+1);
        }
        return maxi;
        
    }
};
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        bool nonzero=false;
        int k=0,cnt=0;
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            k^=nums[i];
            nonzero|=nums[i]>0;
        }

        if(k!=0) return n;

        if(nonzero) return n-1;

        return 0;
        
    }
};
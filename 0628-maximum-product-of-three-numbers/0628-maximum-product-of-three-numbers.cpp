class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        int res1=1,res2=1,res3=1;
    
        for(int i=n-1;i>=0;i--)
        {
            res1*=nums[i];
            if(n-i==3) break;
        }
        if(n==3) return res1;
        for(int i=0;i<2;i++)
        {
            res2*=nums[i];
        }
        res2*=nums[n-1];
        return max(res2,res1);
    }
};
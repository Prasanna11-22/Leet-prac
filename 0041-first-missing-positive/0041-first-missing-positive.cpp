class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
       map<int,int> mp;
       int maxi=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>0) mp[nums[i]]++;
        maxi=max(maxi,nums[i]);
    }
         int chk=1;
        for(auto &k: mp)
        {
            if(k.first!=chk) return chk;
            else chk++;
        }
        
        return maxi+1;
    }
};
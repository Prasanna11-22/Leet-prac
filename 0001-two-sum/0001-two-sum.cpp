class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++)
        {
        int chk=target-nums[i];
        if(mp.count(chk))
        {
            return{mp[chk],i};
        }
        else
        {
            mp[nums[i]]=i;
        }
        }
    return {};
    }
};
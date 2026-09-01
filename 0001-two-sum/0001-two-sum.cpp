class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> res;
        
        for(int i=0;i<nums.size();i++)
        {
        int chk=target-nums[i];
        if(mp.count(chk))
        {
            res.push_back(mp[chk]);
            res.push_back(i);
        }
        else
        {
            mp[nums[i]]=i;
        }
        }
    return res;
    }
};
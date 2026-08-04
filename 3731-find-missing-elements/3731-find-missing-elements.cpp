class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int n = nums.size();
        int ind = nums[0];
        for (int i = 0; i < n; i++,ind++) 
        {
            while (ind != nums[i]) 
            {  res.push_back(ind);
                ind++;
            }
        }
        return res;
    }
};
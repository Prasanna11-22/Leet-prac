class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int k=nums[0];
        int one=0,two=0;
        for(int i : nums)
        {
            one=(i^one)&~two;
            two=(i^two)&~one;
        }
        return one;
    }
};
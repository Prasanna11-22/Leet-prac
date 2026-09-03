class Solution {
public:
    int jump(vector<int>& nums) {
        int far=0,step=0,curreach=0;

        for(int i=0;i<nums.size()-1;i++)
        {
            far=max(far,i+nums[i]);

            if(i==curreach)
            {
                step++;
                curreach=far;
            }

        }

        return step;
    }
};
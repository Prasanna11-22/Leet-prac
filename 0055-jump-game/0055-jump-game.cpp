class Solution {
public:
    bool canJump(vector<int>& nums) {

        int lon=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>lon) 
            {
                return false;
            }

            lon=max(lon,i+nums[i]);

            if(lon>=nums.size()-1)
            {
                return true;
            }
        }

        return false;
        
    }
};
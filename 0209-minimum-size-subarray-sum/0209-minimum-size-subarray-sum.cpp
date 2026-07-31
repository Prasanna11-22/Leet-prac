class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) { int sum=0,cnt=0,mini=INT_MAX,l=0;

    for(int r=0;r<nums.size();r++)
    {
        sum+=nums[r];

        while(sum>=target)
        {
             mini=min(r-l+1,mini);
            sum-=nums[l];
            l++;
        }

       
    }
    return (mini==INT_MAX)?0:mini;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
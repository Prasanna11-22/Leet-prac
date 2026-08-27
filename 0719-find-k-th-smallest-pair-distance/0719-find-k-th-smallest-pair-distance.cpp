class Solution {
public:
    bool isposs(vector<int>& nums,int diff,int k)
    {
        int l=0,pair=0;

        for(int r=1;r<nums.size();r++)
        {
            while((nums[r]-nums[l])>diff)
            {
                l++;
            }
            pair+=(r-l);
        }
    
        return pair>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums[nums.size()-1]-nums[0],ans=r;


        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(isposs(nums,mid,k))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                 l=mid+1;
            }

        }
        return l;
    }
};
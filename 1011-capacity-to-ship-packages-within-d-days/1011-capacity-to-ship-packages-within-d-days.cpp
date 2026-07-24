class Solution {
public:
bool isposs(int w,vector<int>& weights,int days)
{
    int sum=0,daysused=1;
    for(int x : weights)
    {
        sum+=x;
        if(sum>w){
            daysused++;
            sum=x;
        }
        
    }

    return (daysused<=days);
}
    int shipWithinDays(vector<int>& weights, int days) {
        int ans=0;
        int l=*max_element(weights.begin(),weights.end());
        int r=accumulate(weights.begin(),weights.end(),0);

        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(isposs(mid,weights,days))
            {
               ans=mid;
               r=mid-1; 
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
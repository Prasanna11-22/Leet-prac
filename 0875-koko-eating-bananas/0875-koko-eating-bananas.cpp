class Solution {
public:
bool isposs(int ban,vector<int>& piles,int h)
{
    long long sum=0;

    for(int i : piles)
    {
        sum+=(i+ban-1)/ban;
    }

    return sum<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=r;

        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(isposs(mid,piles,h))
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
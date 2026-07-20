class Solution {
public:

bool isposs(vector<int>& piles,int h,int k)
{
    long long eathr=0;
    for(int i : piles)
    {
        eathr+=ceil((double)i/k);
    }
   return eathr<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,ans=0;
        int r=*max_element(piles.begin(),piles.end());
        // for(int i=l;i<=r;i++)
        // {
        //     cout<<i<<"->"<<isposs(piles,h,i)<<endl;
        // }

        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(isposs(piles,h,mid))
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
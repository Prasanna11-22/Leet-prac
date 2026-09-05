class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pmin(n);
        vector<int> smax(n);
        pmin[0]=nums[0];
        smax[n-1]=nums[n-1];

        for(int i=1;i<n;i++)
        {
            pmin[i]=max(pmin[i-1],nums[i]);
        }

        for(int i=n-2;i>=0;i--)
        {
            smax[i]=min(smax[i+1],nums[i]);
        }

for(int i=0;i<n;i++)
{
    int diff=pmin[i]-smax[i];
    if(diff<=k) return i;
    //cout<<pmin[n-i-1]<<" "<<smax[i]<<endl;
}

       return -1; 
    }
};
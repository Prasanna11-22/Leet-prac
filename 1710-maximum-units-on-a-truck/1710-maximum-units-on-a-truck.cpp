class Solution {
public:
static bool cmp(vector<int>&a,vector<int>&b)
{
    return a[1]>b[1];
}
    int maximumUnits(vector<vector<int>>& boxes, int truckSize) {
        sort(boxes.begin(),boxes.end(),cmp);
        int ans=0;

        for(auto k : boxes)
        {
            if(truckSize>=0)
            {
            int maxi=min(truckSize,k[0]);
            ans+=(k[1]*maxi);
            truckSize-=k[0];
            }
        }

        return ans;
    }
};
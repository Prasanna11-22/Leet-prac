class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxes, int truckSize) {
        sort(boxes.begin(),boxes.end(),[](vector<int>&a,vector<int>&b){
            return a[1]>b[1]; 
        });
        int ans=0;

        for(auto k : boxes)
        {
            int maxi=min(truckSize,k[0]);
            ans+=(k[1]*maxi);
            truckSize-=k[0];
            
            if(truckSize<=0) break;
        }

        return ans;
    }
};
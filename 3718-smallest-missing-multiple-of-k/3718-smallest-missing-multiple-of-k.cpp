class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
     unordered_set<int>mp(nums.begin(),nums.end());
     int n=1,t=k;

    
     
   bool chk=true;
     while(chk)
     {
        t=k*n;
        if(mp.find(t)==mp.end())
        {
            return t;
        }
            n++;  
        }
     
   return 0;

    }
};
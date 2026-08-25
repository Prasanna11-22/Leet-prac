class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
     map<int,int> mp;
    for (int num:nums) 
    {
     mp[num]++;
    }

     int n=1,t=k;
     
   bool chk=true;
     while(chk)
     {
        if(mp[t]==0)
        {
            return t;
        }
        else
        {
            n++;
            t=k*n;
        }

     }
     
   return 0;

    }
};
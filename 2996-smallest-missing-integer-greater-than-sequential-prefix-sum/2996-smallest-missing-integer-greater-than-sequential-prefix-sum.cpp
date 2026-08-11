class Solution {
public:
int chk(int count,set<int>& s)
{
      while(s.find(count)!=s.end())
        {
            count++;
        }
    return count;
}
    int missingInteger(vector<int>& nums) {

        int count=nums[0];
        int n=nums.size();
        if(n==1) return count+1;
        vector<int> pref(n,0);
        set<int> s(nums.begin(),nums.end());

        pref[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1]+1)
            {

                pref[i]=pref[i-1]+nums[i];
            }
            else
            {
               count=pref[i-1];
               return chk(count,s);
               
            }
        }

      
        return chk(pref[n-1],s);
        
    }
};
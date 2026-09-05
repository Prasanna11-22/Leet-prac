class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
       int n=nums.size();
        int cnt=0;
        unordered_map<int,int> mp;
        vector<bool> chk(101,false);
        
        for(int i=0;i<n;i++)
        {
            if(!mp.count(nums[i]))
            {
                mp[nums[i]]=i;
                cnt++;
            }
            else
            {
                int diff=i-mp[nums[i]];
                if(diff==1)
                {
                    mp[nums[i]]=i;
                }
                else if(chk[nums[i]]==false)
                {
                    chk[nums[i]]=true;
                    cnt--;
                }
            }
           
        }
        return cnt;
    }
};
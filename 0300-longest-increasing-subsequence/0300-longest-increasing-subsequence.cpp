class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       vector<int> res;

       for(int x : nums)
       {
        int pos=lower_bound(res.begin(),res.end(),x) - res.begin();

        if(pos==res.size())
        {
            res.push_back(x);

        }
        else
        {
            res[pos]=x;
        }
       } 
       return res.size();
    }
};
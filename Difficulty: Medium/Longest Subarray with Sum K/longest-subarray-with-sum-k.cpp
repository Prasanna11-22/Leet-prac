class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        long long sum=0;
        unordered_map<int,int> mp;
        int maxlen=INT_MIN;

        
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum==k) maxlen=i+1;
            
            if(mp.count(sum-k))
            {
                maxlen=max(maxlen,(i-mp[sum-k]));
                
            }
            
            if(!mp.count(sum))
            {
                mp[sum]=i;
            }
        }
        
        return (maxlen==INT_MIN)?0:maxlen;
    }
};
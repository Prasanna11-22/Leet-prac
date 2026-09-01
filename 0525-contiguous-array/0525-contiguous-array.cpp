class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        unordered_map<int,int> mp;
        long long sum=0;
        int maxlen=0;

        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)
            {
                sum-=1;
            }
            sum+=arr[i];
            if(sum==0) maxlen=max(maxlen,i+1);
            else if(mp.count(sum)) 
            {
              maxlen=max(maxlen,(i-mp[sum]));
            }
            else
            {
                mp[sum]=i;
            }
        }
       return maxlen; 
    }
};
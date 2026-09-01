class Solution {
  public:
    int maxLength(vector<int>& arr) {
      unordered_map<long long,int> mp;
      int len,maxlen=INT_MIN;
      mp[0]=-1;
     // vector<int> prefix(arr.size());
    long long sum=0;
      
      for(int i=0;i<arr.size();i++)
      {
          sum+=arr[i];
          
          if(mp.count(sum))
          {
              len=i-mp[sum];
              maxlen=max(maxlen,len);
          }
          else
          {
              mp[sum]=i;
          }
      }
      
      return (maxlen==INT_MIN)?0:maxlen;
    }
};
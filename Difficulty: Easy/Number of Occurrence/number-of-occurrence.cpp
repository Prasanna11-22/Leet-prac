class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        
        return mp[target];
    }
};

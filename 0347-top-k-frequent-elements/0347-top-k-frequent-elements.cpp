class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {


    unordered_map<int,int> mp;

    for(int i=0;i<nums.size();i++)
    {
        mp[nums[i]]++;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    vector<int> res;

    for(auto i : mp)
    {
        pq.push({i.second,i.first});
        while(pq.size()>k)
        {
            pq.pop();
        }
    }

    while(!pq.empty())
    {
        res.push_back(pq.top().second);
        pq.pop();
    }


    return res;        
    }
};
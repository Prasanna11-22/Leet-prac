class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string,int> mp;

    for(int i=0;i<words.size();i++)
    {
        mp[words[i]]++;
    }

auto cmp=[](const pair<int,string>&a,const pair<int,string>&b)
{
    if(a.first==b.first)
    {
        return a.second < b.second;
    }

    return a.first > b.first;
};
    priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(cmp)>pq;

    vector<string> res;

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

    reverse(res.begin(),res.end());
    return res;  
        
    }
};
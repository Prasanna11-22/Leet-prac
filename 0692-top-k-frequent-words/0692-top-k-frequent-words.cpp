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


    for(auto i : mp)
    {
        pq.push({i.second,i.first});
        while(pq.size()>k)
        {
            pq.pop();
        }
    }
    vector<string> res(k,"");

    while(!pq.empty())
    {
        res[k-1]=(pq.top().second);
        pq.pop();
        k--;
    }
    
    return res;  
        
    }
};
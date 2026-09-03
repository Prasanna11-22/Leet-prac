class Solution {
public:
    vector<int> partitionLabels(string s) {

        vector<int> mp(26,0);

        for(int i=0;i<s.size();i++)
        {
            mp[s[i]-'a']=i;
        }
        vector<int> res;

        int st=0,last=0,cnt=0;

        for(int i=0;i<s.size();i++)
        {
        last=max(mp[s[i]-'a'],last);
        if(i==last)
        {
            res.push_back(last-st+1);
            st=i+1;
        }

        }

        return res;
        
    }
};
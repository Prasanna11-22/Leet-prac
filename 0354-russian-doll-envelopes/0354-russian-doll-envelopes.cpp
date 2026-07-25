class Solution {
public:
static bool cmp(vector<int>& a,vector<int> & b)
        {
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        
        vector<int> res;
    sort(envelopes.begin(),envelopes.end(),cmp);
    for(auto x : envelopes)
    {
        int p1=x[1];
    int pos=lower_bound(res.begin(),res.end(),p1)-res.begin();
        if(pos==res.size())
        {
            res.push_back(p1);
        }
        else
        {
            res[pos]=p1;
        }
    }
    return res.size();
    }
};
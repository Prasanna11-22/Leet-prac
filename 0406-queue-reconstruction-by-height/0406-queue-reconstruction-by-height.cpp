class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](vector<int> &a,vector<int>&b){
            if(a[0]!=b[0]) return a[0]>b[0];
            return a[1]<b[1];
        });

        vector<vector<int>> res;

        for(auto k : people)
        {
            int k1=k[0];
            int k2=k[1];
            res.insert(res.begin()+k2,k);
        }

        return res;
    }
};
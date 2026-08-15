class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int k=0;
        set<int> s;
        for(int i : nums)
        {
           if(s.find(i)==s.end()) 
            s.insert(i);
            k^=i;
        }

        for(auto i:s) k^=i;
        return k;

    }
};
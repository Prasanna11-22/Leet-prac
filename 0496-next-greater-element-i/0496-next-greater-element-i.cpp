class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        stack<int> st;
        vector<int> res;
        unordered_map<int,int> mp;
        for(int i=n2-1;i>=0;i--)
        {
            while(!st.empty()&&nums2[i]>st.top())
            {
                st.pop();
            }

            if(st.empty())
            {
                mp[nums2[i]]=-1;
                st.push(nums2[i]);
            }
            else if(nums2[i]<st.top())
            {
                mp[nums2[i]]=st.top();
                st.push(nums2[i]);
                cout<<st.top();
            }
    
        }

        for(int i=0;i<n1;i++)
        {
            res.push_back(mp[nums1[i]]);
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
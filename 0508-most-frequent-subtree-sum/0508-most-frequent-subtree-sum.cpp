/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

// bool cmp(int a,int b)
// {
//     if(freq[a]!=freq[b])
//     {
//         return freq[a]>freq[b];
//     }
//     return a<b;
// }
unordered_map<int,int> mp;
int maxfreq=INT_MIN;
int postord(TreeNode* root)
{
    if(!root) return 0;
    int l=postord(root->left);
    int r=postord(root->right);
    
    int sum=(l+r+root->val);
    mp[sum]++;
    maxfreq=max(maxfreq,mp[sum]);
    return (root->val)+l+r;
}
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        postord(root);
        for(auto k : mp)
        {
            if(k.second==maxfreq)
           {
             res.push_back(k.first);
            }
        }
        return res;
        
    }
};
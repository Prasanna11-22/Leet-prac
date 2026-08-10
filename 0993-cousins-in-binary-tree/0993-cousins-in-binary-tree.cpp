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
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<pair<int,TreeNode*>> q;
        q.push({-1,root});

        while(!q.empty())
        {
            int n=q.size();
            unordered_map<int,int> mp;
            for(int i=0;i<n;i++)
            {
                TreeNode* t=q.front().second;
                int par=q.front().first;
                q.pop();

                mp[t->val]=par;

                if(t->left) q.push({t->val,t->left});
                if(t->right) q.push({t->val,t->right});
            }
            if(n!=1)
            {
                if(mp.find(x)!=mp.end()&&mp.find(y)!=mp.end())
                {
                    if(mp[x]!=mp[y])
                    return true;
                }

            }
        } 


        return false;
    }
};
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*,TreeNode*>> q;

        q.push({root,nullptr});

        while(!q.empty())
        {
            int n=q.size();
            long long tot=0;
            unordered_map<TreeNode*,vector<TreeNode*>> mp;
            for(int i=0;i<n;i++)
            {
            TreeNode* t=q.front().first;
            TreeNode* par=q.front().second;
            q.pop();
            tot+=t->val;
            mp[par].push_back(t);

            if(t->left) q.push({t->left,t});
            if(t->right) q.push({t->right,t});
            }
            for(auto& kid : mp)
            {
                long long sib=0;
                for(auto& k : kid.second)
                {
                    sib+=k->val;
                }

                for(auto& l : kid.second)
                {
                    l->val=tot-sib;
                }
            }

        }
    return root;
    }
};
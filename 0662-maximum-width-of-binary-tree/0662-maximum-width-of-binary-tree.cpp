/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
         int maxwidth=0;
         long long first=0,last=0;

        while(!q.empty())
        {
            long long n=q.size();
             long long minind = q.front().second;

            for(long long i=0;i<n;i++)
            {
                TreeNode* t=q.front().first;
                long long val=q.front().second-minind;
                q.pop();

               if(i==0) first=val;
               if(i==n-1) last=val;

                if(t->left) q.push({t->left,2*val+1});
                if(t->right) q.push({t->right,2*val+2});
            }
            maxwidth=max(maxwidth,(int(last-first+1)));
        }
        
        return maxwidth;
    }
};
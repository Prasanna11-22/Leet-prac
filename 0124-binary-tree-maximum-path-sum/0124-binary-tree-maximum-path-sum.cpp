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
int ans=INT_MIN;
int postord(TreeNode* root)
{
    if(!root) return 0;

    int left=postord(root->left);
    int right=postord(root->right);
    
    int l=max(0,left),r=max(0,right);

    ans=max(ans,l+root->val+r);
    return max(l,r)+root->val;
}

    int maxPathSum(TreeNode* root) {
       postord(root);
        return ans;
    }
};
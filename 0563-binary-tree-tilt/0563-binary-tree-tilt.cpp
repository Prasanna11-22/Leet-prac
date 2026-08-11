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
int sum=0;
bool isleaf(TreeNode* root)
{
    return (root)&&(!root->left)&&(!root->right);
}

    int findTilt(TreeNode* root){
        solve(root);
        return sum;
    }

    int solve(TreeNode* r)
    {
        if(!r)
        {
            return 0;
        }

        int left = solve(r->left);
        int right = solve(r->right);
        
        sum+=abs(left-right);
        return (r->val+left+right);
    }
};
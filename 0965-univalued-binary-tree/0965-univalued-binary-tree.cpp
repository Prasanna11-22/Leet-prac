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
bool rec(TreeNode* root)
{
    if(!root) return true;
    int l=rec(root->left);
    int r=rec(root->right);

    if((root->left)&&(root->left->val!=root->val||!l)) return false;
    if((root->right)&&(root->right->val!=root->val||!r)) return false;

    return l&&r;
}

    bool isUnivalTree(TreeNode* root) {
        return rec(root);
    }
};
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
int postord(TreeNode* root)
{
    if(!root) return 0;

    int l=postord(root->left);
    if(l==-1) return -1;
    int r=postord(root->right);
    if(r==-1) return -1;

    if(abs(l-r)>1) return -1;

    return 1+max(l,r);
}

    bool isBalanced(TreeNode* root) {
        int h=postord(root);
       
        return (h!=-1)?true:false;
    }
};
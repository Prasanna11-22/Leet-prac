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

int chkheight(TreeNode* root)
{
    if(root==nullptr) return 0;


    int left=chkheight(root->left);
    if(left==-1) return -1;

    int right=chkheight(root->right);
    if(right==-1) return -1;

    if(abs(left-right)>1) return -1;

    return max(left,right)+1;
}

bool isBalanced(TreeNode* root) 
{       
    return (chkheight(root)!=-1);
}

};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
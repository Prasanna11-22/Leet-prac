class Solution {
public:

bool solve(TreeNode* root,long long mini,long long maxi)
{
    if(root==NULL) return true;
    if(root->val<=mini || root->val>=maxi)
    {
        return false;
    }
    return solve(root->left,mini,root->val)&&solve(root->right,root->val,maxi);

}

    bool isValidBST(TreeNode* root) {
        return solve(root,LLONG_MIN, LLONG_MAX);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
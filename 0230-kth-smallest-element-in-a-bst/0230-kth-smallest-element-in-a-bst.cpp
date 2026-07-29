class Solution {
public:
int solve(TreeNode* root,int k,int& count)
{
    if(root==NULL) return -1;

    int left = solve(root->left, k, count);
    if (left != -1) return left;
    
    count++;
    
    if(count==k) return root->val;

    return solve(root->right,k,count);
}
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        return solve(root,k,cnt);

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
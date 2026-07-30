class Solution {
public:

int sum=0;
bool preord(TreeNode* root,int tsum,int sum)
{
    if(root==NULL) return false;

    int totsum=sum+root->val;

    if(root->left==NULL && root->right==NULL)
    return (tsum==totsum);

 return preord(root->left,tsum,totsum) || preord(root->right,tsum,totsum);

}
    bool hasPathSum(TreeNode* root, int tsum) {
        return preord(root,tsum,0);
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
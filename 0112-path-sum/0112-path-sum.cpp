class Solution {
public:
bool isleaf(TreeNode* root)
{
    return (root)&&(!root->left)&&(!root->right);
}
 bool rec(TreeNode* root,int targ,int sum)
 {
    if(!root) return false;

    sum+=root->val;

    if(isleaf(root))
    {
        return (sum==targ);
    }

    return  rec(root->left,targ,sum)|| rec(root->right,targ,sum);
 }

    bool hasPathSum(TreeNode* root, int targetSum) {

  return rec(root,targetSum,0);
        
    }
};
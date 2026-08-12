class Solution {
public:
const int uncov=0,oncam=1,cov=2;
int cameras=0;
int dfs(TreeNode* root)
{
    if(!root) return cov;

    int left=dfs(root->left);
    int right=dfs(root->right);

    if(left == uncov ||right == uncov)
    {
        cameras++;
        return oncam;
    }
    else if(left==oncam || right==oncam)
    {
        return cov;
    }
    else
    {
        return uncov;
    }

    return uncov;

}
    int minCameraCover(TreeNode* root) {
     int last=dfs(root);

     if(last==uncov) cameras++;

     return cameras;
    }
};
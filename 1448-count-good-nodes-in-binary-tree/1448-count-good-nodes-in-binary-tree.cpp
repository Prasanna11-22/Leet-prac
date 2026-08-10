class Solution {
public:
int count=0;
void preord(TreeNode* root,int maxval)
{
    if(!root) return;

    if(root->val>=maxval)
    {
        count++;
        maxval=root->val; 
    }
    preord(root->left,maxval);
    preord(root->right,maxval);


}
    int goodNodes(TreeNode* root) {
        preord(root,-1e5);

        return count;
    }
};
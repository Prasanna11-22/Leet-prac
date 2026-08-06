class Solution {
public:
int mindiff=1e9;
int flag=0;
int prev=1e9;

void inod(TreeNode* root)
{
    if(!root) return;
    inod(root->left);
    if(flag==0)
    {
        prev=root->val;
        flag=1;
    }
    else
    {
        int diff=(root->val)-prev;
        mindiff=min(mindiff,diff);
        prev=root->val;
    }
    inod(root->right);
}
    int getMinimumDifference(TreeNode* root) {
        inod(root);
        return mindiff;

    }
};
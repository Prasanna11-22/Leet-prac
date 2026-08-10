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
int ans=0;
int postord(TreeNode* root)
{
    if(!root) return 0;
    int left=postord(root->left);
    int right=postord(root->right);

    int l=0,r=0;
   
   if((root->left)&&root->val==root->left->val)
   {
         l=left+1;
   }
    if((root->right)&&root->val==root->right->val)   
    {
        r=right+1;
    }
    ans=max(ans,(l+r));

    cout<<ans<<endl;

    return max(l,r);
}
    int longestUnivaluePath(TreeNode* root) {

        postord(root);
        return ans; 

    }
};
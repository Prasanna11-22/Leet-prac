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
int ans=INT_MIN;
int postord(TreeNode* root)
{
    if(!root) return 0;

    int left=postord(root->left);
    int right=postord(root->right);
    cout<<root->val<<"->"<<" "<<left<<" "<<right<<" "<<ans<<endl;
    int l=max(0,left),r=max(0,right);


    // if((root->left)&&root->val+root->left->val+left >=left)
    // {
    //     l=root->left->val+left; 
    // }

    // if((root->right)&&root->val+right>=right)
    // {
    //     r=root->right->val+right; 
    // }

    ans=max(ans,l+root->val+r);

    cout<<root->val<<" "<<l<<" "<<r<<" "<<ans<<endl;
    return max(l,r)+root->val;
}

    int maxPathSum(TreeNode* root) {
       postord(root);
        return ans;
    }
};
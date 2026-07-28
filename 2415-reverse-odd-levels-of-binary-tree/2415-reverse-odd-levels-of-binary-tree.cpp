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
void rec(TreeNode* r1,TreeNode* r2,int level)
{
    if(r1==NULL||r2==NULL) return;
    if(level%2!=0)
    {
        swap(r1->val,r2->val);   
    }

    rec(r1->left,r2->right,level+1);
    rec(r1->right,r2->left,level+1);
    
   
}

    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==nullptr) return nullptr;
      rec(root->left,root->right,1); 
      return root;

    }
};
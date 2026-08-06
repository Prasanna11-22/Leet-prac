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
int dia=0;

int rec(TreeNode* root)
{
    if(!root) return 0;

    int l1=rec(root->left);
    int l2=rec(root->right);


    
    dia=max(l1+l2,dia);

    return max(l1,l2)+1;
}

int diameterOfBinaryTree(TreeNode* root) 
{
    rec(root);
    return dia; 
    
           
}
};
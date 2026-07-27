class Solution {
public:
vector<int> res;
 void inord(TreeNode* root)
 {
    if(root==NULL) return;

    inord(root->left);
    res.push_back(root->val);
    inord(root->right);

 }
    vector<int> inorderTraversal(TreeNode* root) {
        inord(root);
        return res;
        
    }
};
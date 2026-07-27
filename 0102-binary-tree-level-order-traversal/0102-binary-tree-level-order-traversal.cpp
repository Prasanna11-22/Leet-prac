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

vector<vector<int>> res;

vector<vector<int>> trav(TreeNode* root)
{
     queue<TreeNode*> q;
        q.push(root);
        int currlevel=0;
        while(!q.empty())
        {
            int n=q.size();
            res.push_back({});
            for (int i = 0; i <n; i++) {
            TreeNode* t=q.front();
            q.pop();

            res[currlevel].push_back(t->val);

            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            }
            currlevel++;
        }
        return res;
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return res;
        return trav(root);
    }
};
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;

            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            ans = level[0];
        }

        return ans;
    }
};